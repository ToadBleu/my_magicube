
#ifndef PLANE_
    #define PLANE_
    #include <SFML/Config.h>
#define EXIT_SUCCESS 0
    #define EXIT_FAILURE 1
    #define BACKGROUND "./include/texture/back.jpg"
    #define PLAYER "./include/texture/plane.png"
    #define TEXT "./include/text.ttf"
    #define FALL_SPEED 9.80665 / 60

    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Types.h>
    #include <SFML/System/Vector2.h>

typedef struct player_s {
    sfVector2f offset;
    sfClock *fall_time;
    sfBool grounded;
    int movement;
} player_t;

typedef struct sprite_s {
    sfSprite *player;
    sfSprite *background;
} sprite_t;

typedef struct object_s {
    sfRectangleShape *ground;
} object_t;

typedef struct game_s {
    player_t *player;
    object_t *object;
    sprite_t *sprite;
} game_t;

int game(game_t *game);
void collision(game_t *game);
game_t *init_game(void);
void free_game(game_t *game);
void move_player(game_t *game);
int render(sfRenderWindow *window, game_t *game);
void analyse_event(sfRenderWindow *window, sfEvent event, game_t *game);
void jump(game_t *game);
void free_all(sfRenderWindow *window, game_t *game, sfClock *clock);

#endif
