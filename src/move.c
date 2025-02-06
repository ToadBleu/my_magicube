
#include "magicube.h"
#include <SFML/Config.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Vector2.h>

void jump(game_t *game)
{
    if (game->player->grounded && !game->player->spell) {
        game->player->offset.y = -5;
        game->player->grounded = sfFalse;
        sfClock_restart(game->player->fall_time);
    }
}

void move_player(game_t *game)
{
    sfTime time;
    float seconds;

    if (!game->player->grounded) {
        time = sfClock_getElapsedTime(game->player->fall_time);
        seconds = time.microseconds / 1000000.0;
        game->player->offset.y += seconds * FALL_SPEED;
    }
    if (game->player->grounded && game->player->offset.y >= 0){
        sfClock_restart(game->player->fall_time);
        game->player->offset.y = 0;
    }
    game->player->offset.x = game->player->movement;
    // if (game->player->movement > 0)
    //     sfSprite_setRotation(game->sprite->player, 0);
    // else if (game->player->movement < 0)
    //     sfSprite_setRotation(game->sprite->player, 180);
    sfSprite_move(game->sprite->player, game->player->offset);
}

void move(game_t *game)
{
    if (game->player->spell) {
        game->player->movement = 0;
    }
    move_player(game);
}