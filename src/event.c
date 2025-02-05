/*
** EPITECH PROJECT, 2024
** event.c
** File description:
** handle event
*/

#include "plane.h"
#include <SFML/Window/Event.h>

void analyse_event(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed ||
        (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape))
            sfRenderWindow_close(window);
}
