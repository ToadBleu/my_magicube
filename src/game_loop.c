
#include "magicube.h"
#include <time.h>
#include <stdlib.h>

int do_render(sfClock *clock)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds < ((float)1 / 60))
        return 0;
    sfClock_restart(clock);
    return 1;
}

sfRenderWindow *init_win(void)
{
    sfVideoMode video_mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(video_mode,
    "game", sfDefaultStyle, NULL);

    sfRenderWindow_setFramerateLimit(window, 60);
    return window;
}

int game(game_t *game)
{
    sfRenderWindow *window = init_win();
    sfEvent event;
    sfClock *clock = sfClock_create();

    while (sfRenderWindow_isOpen(window) && clock != NULL && window != NULL){
        while (sfRenderWindow_pollEvent(window, &event) == sfTrue)
            analyse_event(window, event, game);
        if (do_render(clock) == 1) {
            sfRenderWindow_clear(window, sfBlack);
            process_keys(game);
            move_player(game);
            collision(game);
            render(window, game);
            sfRenderWindow_display(window);
        }
    }
    free_all(window, game, clock);
    return 0;
}
