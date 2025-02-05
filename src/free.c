/*
** EPITECH PROJECT, 2024
** free.c
** File description:
** free
*/

#include "plane.h"
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Clock.h>
#include <stdlib.h>

void free_sprite(sprite_t *sprite)
{
    if (sprite->player) {
        if (sfSprite_getTexture(sprite->player))
            sfTexture_destroy((sfTexture *)sfSprite_getTexture(sprite->player));
        sfSprite_destroy(sprite->player);
    }
    if (sprite->background) {
        if (sfSprite_getTexture(sprite->background))
            sfTexture_destroy((sfTexture *)sfSprite_getTexture(sprite->background));
        sfSprite_destroy(sprite->background);
    }
}

void free_game(game_t *game)
{
    if (game->player) {
        if (game->player->fall_time)
            sfClock_destroy(game->player->fall_time);
        free(game->player);
    }
    if (game->sprite) {
        free_sprite(game->sprite);
        free(game->sprite);
    }
    if (game->object) {
        sfRectangleShape_destroy(game->object->ground);
        free(game->object);
    }
    free(game);
}

void free_all(sfRenderWindow *window, game_t *game, sfClock *clock)
{
    if (window != NULL)
        sfRenderWindow_destroy(window);
    free_game(game);
    if (clock != NULL)
        sfClock_destroy(clock);
}
