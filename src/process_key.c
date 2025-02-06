

#include "magicube.h"

void process_keys(game_t *game)
{
    game->player->movement =
    (sfKeyboard_isKeyPressed(sfKeyD) - sfKeyboard_isKeyPressed(sfKeyQ)) * 3;
    if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue)
        jump(game);
}
