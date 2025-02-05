
#include "plane.h"
#include <SFML/Window/Event.h>

void analyse_event(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed ||
        (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape))
            sfRenderWindow_close(window);
}
