
#include "plane.h"
#include <SFML/Config.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>

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
    game->player->offset = (sfVector2f){0, 0};
    game->player->fall_time = sfClock_create();
    if (!game->sprite || !game->player || !game->player->fall_time) {
        free_game(game);
        return NULL;
    }
    if (init_sprite(game->sprite) != 0) {
        free_game(game);
        return NULL;
    }
    return game;
}