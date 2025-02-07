

#include "magicube.h"
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>

int collision_ground_box(game_t *game, ground_t *ground)
{
    sfFloatRect box_bottom;
    sfFloatRect ground_bound;
    sfVector2f pos_up;
    box_t *box = game->object->boxs;

    if (game->object->spell_box)
        box = game->object->spell_box;
    while (box) {
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
            return EXIT_SUCCESS;
        }
        box->grounded = 0;
        box = box->next;
    }
    return EXIT_FAILURE;
}

void collision_box(game_t *game)
{
    for (ground_t *obj = game->object->ground; obj != NULL; obj = obj->next) {
        if (collision_ground_box(game, obj) == EXIT_SUCCESS)
            break;
    }
}