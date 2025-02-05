
#include "plane.h"
#include <SFML/Config.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>

int init_ground(object_t *object)
{
    sfVector2f size = {1920, 50};
    sfVector2f position = {0, 1080 - 500};

    object->ground = sfRectangleShape_create();
    if (!object->ground)
        return EXIT_FAILURE;
    sfRectangleShape_setSize(object->ground, size);
    sfRectangleShape_setFillColor(object->ground, sfBlack);
    sfRectangleShape_setPosition(object->ground, position);
    return EXIT_SUCCESS;
}

int init_sprite(sprite_t *data_sprite)
{
    sfTexture *texture;
    sfSprite *sprite;

    data_sprite->background = NULL;
    data_sprite->player = NULL;

    texture = sfTexture_createFromFile(BACKGROUND, NULL);
    if (!texture)
        return EXIT_FAILURE;
    sprite = sfSprite_create();
    if (!sprite)
        return EXIT_FAILURE;
    sfSprite_setTexture(sprite, texture, sfFalse);
    data_sprite->background = sprite;

    texture = sfTexture_createFromFile(PLAYER, NULL);
    if (!texture)
        return EXIT_FAILURE;
    sprite = sfSprite_create();
    if (!sprite)
        return EXIT_FAILURE;
    sfSprite_setTexture(sprite, texture, sfFalse);
    data_sprite->player = sprite;

    return EXIT_SUCCESS;
}

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return NULL;
    game->player = malloc(sizeof(player_t));
    game->sprite = malloc(sizeof(sprite_t));
    game->object = malloc(sizeof(object_t));
    game->player->offset = (sfVector2f){0, 0};
    game->player->fall_time = sfClock_create();
    if (!game->sprite || !game->player || !game->player->fall_time
        || !game->object) {
        free_game(game);
        return NULL;
    }
    if (init_sprite(game->sprite) != 0) {
        free_game(game);
        return NULL;
    }
    if (init_ground(game->object) != 0) {
        free(game);
        return NULL;
    }
    game->player->grounded = 0;
    return game;
}