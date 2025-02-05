
#include "plane.h"
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Vector2.h>

void move_player(game_t *game)
{
    sfTime time;
    float seconds;

    if (1) {
        time = sfClock_getElapsedTime(game->player->fall_time);
        seconds = time.microseconds / 1000000.0;
        game->player->offset.y = seconds * FALL_SPEED;
    } else {
        sfClock_restart(game->player->fall_time);
    }
    sfSprite_move(game->sprite->player, game->player->offset);
}