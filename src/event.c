
#include "plane.h"
#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>

void analyse_event(sfRenderWindow *window, sfEvent event, game_t *game)
{
    if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed) {
        switch (event.key.code) {
            case sfKeyEscape:
                sfRenderWindow_close(window);
                break;
            case sfKeyQ:
                game->player->movement = -3;
                break;
            case sfKeyD:
                game->player->movement = 3;
                break;
            case sfKeySpace:
            case sfKeyZ:
                jump(game);
                break;
            default:
                break;
        }
    }
    if (event.type == sfEvtKeyReleased) {
        if (event.key.code == sfKeyQ && game->player->movement <= 0)
                game->player->movement = 0;
        if (event.key.code == sfKeyD && game->player->movement >= 0)
                game->player->movement = 0;

    }
}
