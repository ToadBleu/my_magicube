
#include "plane.h"
#include <stdio.h>

int main(void) {
    game_t *game_d = init_game();

    if (game_d == NULL) {
        dprintf(2, "ERROR : Loading of the data had an error\n");
        return EXIT_FAILURE;
    }
    return game(game_d);
}