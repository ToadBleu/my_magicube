
#include "plane.h"
#include <SFML/Config.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>

int collision_head(game_t *game, object_t *object)
{
    sfFloatRect player_head = sfSprite_getGlobalBounds(game->sprite->player);
    sfFloatRect ground = sfRectangleShape_getGlobalBounds(object->ground);
    sfVector2f pos_down = {player_head.left, ground.top + ground.height};

    player_head.height = 1;
    player_head.left = player_head.left + 2;
    player_head.width = player_head.width - 6;

    if (sfFloatRect_intersects(&player_head, &ground, NULL) == sfTrue) {
        sfSprite_setPosition(game->sprite->player, pos_down);
        game->player->offset.y = -0.01;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

int collision_side_left(game_t *game, object_t *object)
{
    sfFloatRect player_body = sfSprite_getGlobalBounds(game->sprite->player);
    sfFloatRect ground = sfRectangleShape_getGlobalBounds(object->ground);
    sfVector2f pos_left = {ground.left + ground.width + 1, player_body.top};

    player_body.top += 1;
    player_body.height -= 2;
    player_body.left -= 1;
    player_body.width = 2;

    if (sfFloatRect_intersects(&player_body, &ground, NULL) == sfTrue) {
        sfSprite_setPosition(game->sprite->player, pos_left);
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

int collision_side_right(game_t *game, object_t *object)
{
    sfFloatRect player_body = sfSprite_getGlobalBounds(game->sprite->player);
    sfFloatRect ground = sfRectangleShape_getGlobalBounds(object->ground);
    sfVector2f pos_right = {ground.left - player_body.width, player_body.top};

    player_body.top += 1;
    player_body.height -= 2;
    player_body.left += player_body.width;
    player_body.width = 2;

    if (sfFloatRect_intersects(&player_body, &ground, NULL) == sfTrue) {
        sfSprite_setPosition(game->sprite->player, pos_right);
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

int collision_ground(game_t *game, object_t *object)
{
    sfFloatRect player_feet = sfSprite_getGlobalBounds(game->sprite->player);
    sfFloatRect ground = sfRectangleShape_getGlobalBounds(object->ground);
    sfVector2f pos_up = {player_feet.left, ground.top - player_feet.height};

    player_feet.top = player_feet.top + player_feet.height;
    player_feet.height = 2;
    player_feet.left = player_feet.left + 2;
    player_feet.width = player_feet.width - 6;

    if (sfFloatRect_intersects(&player_feet, &ground, NULL) == sfTrue) {
        game->player->grounded = 1;
        sfSprite_setPosition(game->sprite->player, pos_up);
        return EXIT_SUCCESS;
    }
    game->player->grounded = 0;
    return EXIT_FAILURE;
}

void collision(game_t *game)
{
    for (object_t *obj = game->object; obj != NULL; obj = obj->next) {
        if (collision_ground(game, obj) == EXIT_SUCCESS)
            break;
    }
    for (object_t *obj = game->object; obj != NULL; obj = obj->next) {
        if (collision_head(game, obj) == EXIT_SUCCESS)
            break;
    }
    for (object_t *obj = game->object; obj != NULL; obj = obj->next) {
        if (collision_side_right(game, obj) == EXIT_SUCCESS)
            break;
        if (collision_side_left(game, obj) == EXIT_SUCCESS)
            break;
    }
}