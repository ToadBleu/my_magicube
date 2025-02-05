
#ifndef PLANE_
    #define PLANE_
    #define EXIT_SUCCESS 0
    #define EXIT_FAILURE 1
    #define BACKGROUND "./include/texture/back.jpg"
    #define PLAYER "./include/texture/plane.png"
    #define FALL_SPEED 9.80665

    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Types.h>
    #include <SFML/System/Vector2.h>

typedef struct player_s {
    sfVector2f offset;
    sfClock *fall_time;
} player_t;

typedef struct sprite_s {
    sfSprite *player;
    sfSprite *background;
} sprite_t;

typedef struct game_s {
    player_t *player;
    sprite_t *sprite;
}game_t;

int game(game_t *game);
game_t *init_game(void);
void free_game(game_t *game);
void move_player(game_t *game);
int render(sfRenderWindow *window, game_t *game);
void analyse_event(sfRenderWindow *window, sfEvent event);
void free_all(sfRenderWindow *window, game_t *game, sfClock *clock);

#endif
