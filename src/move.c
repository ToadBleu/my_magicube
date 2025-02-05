
#include "plane.h"
#include <SFML/Config.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Vector2.h>

void jump(game_t *game)
{
    if (game->player->grounded) {
        game->player->offset.y = -3;
        game->player->grounded = sfFalse;
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
    sfSprite_move(game->sprite->player, game->player->offset);
}