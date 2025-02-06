
#include "magicube.h"
#include <SFML/Config.h>
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>

int init_ground(game_t *game)
{
    ground_t *ground = malloc(sizeof(object_t));
    sfVector2f size = {1920, 50};
    sfVector2f position = {0, 1080 - 250};

    if (!ground)
        return EXIT_FAILURE;
    ground->ground = sfRectangleShape_create();
    if (!ground->ground)
        return EXIT_FAILURE;
    sfRectangleShape_setSize(ground->ground, size);
    sfRectangleShape_setFillColor(ground->ground, sfBlack);
    sfRectangleShape_setPosition(ground->ground, position);
    ground->next = game->object->ground;
    game->object->ground = ground;

    game->object->arrow = sfCircleShape_create();
    if (!game->object->arrow)
        return EXIT_FAILURE;
    sfCircleShape_setPointCount(game->object->arrow, 3);
    sfCircleShape_setRadius(game->object->arrow, 5);
    sfCircleShape_setFillColor(game->object->arrow, sfYellow);
    sfCircleShape_setOrigin(game->object->arrow, (sfVector2f){5, 5});

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
    game->player->spell = 0;
    game->player->grounded = 0;
    if (!game->sprite || !game->player || !game->player->fall_time
        || !game->object) {
        free_game(game);
        return NULL;
    }
    game->sprite->background = NULL;
    game->sprite->player = NULL;
    game->object->ground = NULL;
    game->object->arrow = NULL;
    if (init_sprite(game->sprite) != 0) {
        free_game(game);
        return NULL;
    }
    if (init_ground(game) != 0) {
        free(game);
        return NULL;
    }
    game->player->grounded = 0;
    game->player->movement = 0;
    return game;
}