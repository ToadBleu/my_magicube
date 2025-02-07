
#include "magicube.h"
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>

void collision_head_box_player(game_t *game, box_t *box)
{
    sfFloatRect box_bound = sfRectangleShape_getGlobalBounds(box->box);
    sfFloatRect player_bound = sfSprite_getGlobalBounds(game->sprite->player);
    sfVector2f pos_up = {player_bound.left + player_bound.width / 2, box_bound.top - player_bound.height / 2};

    box_bound.height = 1;
    box_bound.left = box_bound.left + 2;
    box_bound.width = box_bound.width - 6;
    if (sfFloatRect_intersects(&box_bound, &player_bound, NULL) == sfTrue) {
        game->player->grounded = 1;
        sfSprite_setPosition(game->sprite->player, pos_up);
    }
}

int collision_side_left_box_player(game_t *game, box_t *box)
{
    sfFloatRect box_bound = sfRectangleShape_getGlobalBounds(box->box);
    sfFloatRect player_bound = sfSprite_getGlobalBounds(game->sprite->player);
    sfVector2f pos_left = (sfVector2f){player_bound.left + player_bound.width + box_bound.width / 2 + 2, box_bound.top + box_bound.height / 2};
    sfVector2f player = (sfVector2f){player_bound.left + player_bound.width / 2 - 3, player_bound.top + player_bound.height / 2};
    player_bound.top += 1;
    player_bound.height -= 2;
    player_bound.left += player_bound.width;
    player_bound.width = 2;
    if (sfFloatRect_intersects(&box_bound, &player_bound, NULL) == sfTrue) {
        sfRectangleShape_setPosition(box->box, pos_left);
        if (collision_side_right_box(game, box) == EXIT_SUCCESS) {
            box_bound = sfRectangleShape_getGlobalBounds(box->box);
            sfSprite_setPosition(game->sprite->player, player);
        }
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

int collision_side_right_box_player(game_t *game, box_t *box)
{

    sfFloatRect box_bound = sfRectangleShape_getGlobalBounds(box->box);
    sfFloatRect player_bound = sfSprite_getGlobalBounds(game->sprite->player);
    sfVector2f pos_right = (sfVector2f){player_bound.left - box_bound.width / 2 - 2, box_bound.top + box_bound.height / 2};
    sfVector2f player = (sfVector2f){player_bound.left + player_bound.width / 2 + 3, player_bound.top + player_bound.height / 2};
    player_bound.top += 1;
    player_bound.height -= 2;
    player_bound.left -= 1;
    player_bound.width = 2;
    if (sfFloatRect_intersects(&box_bound, &player_bound, NULL) == sfTrue) {
        sfRectangleShape_setPosition(box->box, pos_right);
        if (collision_side_left_box(game, box) == EXIT_SUCCESS) {
            box_bound = sfRectangleShape_getGlobalBounds(box->box);
            sfSprite_setPosition(game->sprite->player, player);
        }
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}