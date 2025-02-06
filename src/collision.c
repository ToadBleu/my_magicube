
#include "magicube.h"
#include <SFML/Config.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>
#include <stdlib.h>

int collision_head(game_t *game, ground_t *ground)
{
    sfFloatRect player_head = sfSprite_getGlobalBounds(game->sprite->player);
    sfFloatRect ground_bound = sfRectangleShape_getGlobalBounds(ground->ground);
    sfVector2f pos_down = {player_head.left, ground_bound.top + ground_bound.height};

    player_head.height = 1;
    player_head.left = player_head.left + 2;
    player_head.width = player_head.width - 6;

    if (sfFloatRect_intersects(&player_head, &ground_bound, NULL) == sfTrue) {
        sfSprite_setPosition(game->sprite->player, pos_down);
        game->player->offset.y = -0.01;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

int collision_side_left(game_t *game, ground_t *ground)
{
    sfFloatRect player_body = sfSprite_getGlobalBounds(game->sprite->player);
    sfFloatRect ground_bound = sfRectangleShape_getGlobalBounds(ground->ground);
    sfVector2f pos_left = {ground_bound.left + ground_bound.width + 1, player_body.top};

    player_body.top += 1;
    player_body.height -= 2;
    player_body.left -= 1;
    player_body.width = 2;

    if (sfFloatRect_intersects(&player_body, &ground_bound, NULL) == sfTrue) {
        sfSprite_setPosition(game->sprite->player, pos_left);
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

int collision_side_right(game_t *game, ground_t *ground)
{
    sfFloatRect player_body = sfSprite_getGlobalBounds(game->sprite->player);
    sfFloatRect ground_bound = sfRectangleShape_getGlobalBounds(ground->ground);
    sfVector2f pos_right = {ground_bound.left - player_body.width, player_body.top};

    player_body.top += 1;
    player_body.height -= 2;
    player_body.left += player_body.width;
    player_body.width = 2;

    if (sfFloatRect_intersects(&player_body, &ground_bound, NULL) == sfTrue) {
        sfSprite_setPosition(game->sprite->player, pos_right);
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

int collision_ground(game_t *game, ground_t *ground)
{
    sfFloatRect player_feet = sfSprite_getGlobalBounds(game->sprite->player);
    sfFloatRect ground_bound = sfRectangleShape_getGlobalBounds(ground->ground);
    sfVector2f pos_up = {player_feet.left, ground_bound.top - player_feet.height};

    player_feet.top = player_feet.top + player_feet.height;
    player_feet.height = 2;
    player_feet.left = player_feet.left + 2;
    player_feet.width = player_feet.width - 6;

    if (sfFloatRect_intersects(&player_feet, &ground_bound, NULL) == sfTrue) {
        game->player->grounded = 1;
        sfSprite_setPosition(game->sprite->player, pos_up);
        return EXIT_SUCCESS;
    }
    game->player->grounded = 0;
    return EXIT_FAILURE;
}

void collision(game_t *game)
{
    for (ground_t *obj = game->object->ground; obj != NULL; obj = obj->next) {
        if (collision_ground(game, obj) == EXIT_SUCCESS)
            break;
    }
    for (ground_t *obj = game->object->ground; obj != NULL; obj = obj->next) {
        if (collision_head(game, obj) == EXIT_SUCCESS)
            break;
    }
    for (ground_t *obj = game->object->ground; obj != NULL; obj = obj->next) {
        if (collision_side_right(game, obj) == EXIT_SUCCESS)
            break;
        if (collision_side_left(game, obj) == EXIT_SUCCESS)
            break;
    }
}