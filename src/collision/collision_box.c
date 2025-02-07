

#include "magicube.h"
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>

void collision_ground_box(game_t *game, box_t *box)
{
    sfFloatRect box_bottom;
    sfFloatRect ground_bound;
    sfVector2f pos_up;
    ground_t *ground = game->object->ground;

    while (ground) {
        box_bottom = sfRectangleShape_getGlobalBounds(box->box);
        ground_bound = sfRectangleShape_getGlobalBounds(ground->ground);
        pos_up = (sfVector2f){box_bottom.left + box_bottom.width / 2, ground_bound.top - box_bottom.height / 2};
        box_bottom.top = box_bottom.top + box_bottom.height;
        box_bottom.height = 2;
        box_bottom.left = box_bottom.left + 2;
        box_bottom.width = box_bottom.width - 6;

        if (sfFloatRect_intersects(&box_bottom, &ground_bound, NULL) == sfTrue) {
            box->grounded = 1;
            sfRectangleShape_setPosition(box->box, pos_up);
            return;
        }
        box->grounded = 0;
        ground = ground->next;
    }
}

void collision_head_box(game_t *game, box_t *box_bottom)
{
    sfFloatRect box_head;
    sfFloatRect box_bound;
    sfVector2f pos_up_box;
    box_t *box_top = box_bottom->next;

    while (box_top) {
        box_head = sfRectangleShape_getGlobalBounds(box_bottom->box);
        box_bound = sfRectangleShape_getGlobalBounds(box_top->box);
        pos_up_box = (sfVector2f){box_bound.left + box_bound.width / 2, box_head.top - box_bound.height / 2};
        box_head.height = 1;
        box_head.left = box_head.left + 2;
        box_head.width = box_head.width - 6;

        if (sfFloatRect_intersects(&box_head, &box_bound, NULL) == sfTrue) {
            sfRectangleShape_setPosition(box_top->box, pos_up_box);
            box_top->grounded = 1;
            return;
        }
        box_top = box_top->next;
    }
}

int collision_side_left_box(game_t *game, box_t *box)
{
    sfFloatRect box_left;
    sfFloatRect ground_bound;
    sfVector2f pos_left;
    ground_t *ground = game->object->ground;

    if (collision_side_left_box_player(game, box) == EXIT_SUCCESS)
        return EXIT_SUCCESS;
    while (ground) {
        box_left = sfRectangleShape_getGlobalBounds(box->box);
        ground_bound = sfRectangleShape_getGlobalBounds(ground->ground);
        pos_left = (sfVector2f){box_left.left + box_left.width / 2, ground_bound.top - box_left.height / 2};
        box_left.top += 1;
        box_left.height -= 2;
        box_left.left -= 1;
        box_left.width = 2;

        if (sfFloatRect_intersects(&box_left, &ground_bound, NULL) == sfTrue) {
            sfRectangleShape_setPosition(box->box, pos_left);
            return EXIT_SUCCESS;
        }
        ground = ground->next;
    }
    return EXIT_FAILURE;
}

int collision_side_right_box(game_t *game, box_t *box)
{
    sfFloatRect box_side;
    sfFloatRect ground_bound;
    sfVector2f pos_right;
    ground_t *ground = game->object->ground;

    if (collision_side_right_box_player(game, box) == EXIT_SUCCESS)
        return EXIT_SUCCESS;
    while (ground) {
        box_side = sfRectangleShape_getGlobalBounds(box->box);
        ground_bound = sfRectangleShape_getGlobalBounds(ground->ground);
        pos_right = (sfVector2f){box_side.left + box_side.width / 2, ground_bound.top - box_side.height / 2};
        box_side.top += 1;
        box_side.height -= 2;
        box_side.left += box_side.width;
        box_side.width = 2;

        if (sfFloatRect_intersects(&box_side, &ground_bound, NULL) == sfTrue) {
            sfRectangleShape_setPosition(box->box, pos_right);
            return EXIT_SUCCESS;
        }
        ground = ground->next;
    }
    return EXIT_FAILURE;
}

void collision_box(game_t *game)
{
    box_t *start = game->object->boxs;

    if (game->object->spell_box)
        start = game->object->spell_box;
    for (box_t *box = start; box != NULL; box = box->next) {
        collision_ground_box(game, box);
    }
    for (box_t *box = start; box != NULL; box = box->next) {
        collision_head_box(game, box);
        collision_head_box_player(game, box);
    }
    for (box_t *box = start; box != NULL; box = box->next) {
        if (collision_side_left_box(game, box) == EXIT_SUCCESS)
            continue;
        if (collision_side_right_box(game, box) == EXIT_SUCCESS)
            continue;
    }
}