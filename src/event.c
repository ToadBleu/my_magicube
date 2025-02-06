
#include "magicube.h"
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
            case sfKeyA:
                game->player->spell = 1;
                break;
            case sfKeyQ:
            case sfKeyD:
                spell(game);
            default:
                break;
        }
    }
}
