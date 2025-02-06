
#include "magicube.h"

void spell(game_t *game)
{
    if (game->player->spell == 0 || game->player->grounded == 0)
        return;
    game->player->spell = 0;
}
