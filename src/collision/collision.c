
#include "magicube.h"

void collision(game_t *game)
{
    collision_player_wall(game);
    collision_box(game);
}