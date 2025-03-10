
#ifndef MAGICUBE_
    #define MAGICUBE_
    #define EXIT_SUCCESS 0
    #define EXIT_FAILURE 1
    #define BACKGROUND "./include/texture/back.jpg"
    #define PLAYER "./include/texture/plane.png"
    #define TEXT "./include/text.ttf"
    #define FALL_SPEED 0.980665

    #include <SFML/Config.h>
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Types.h>
    #include <SFML/System/Vector2.h>

typedef struct box_s {
    sfRectangleShape *box;
    struct box_s *next;
    sfClock *fall_time;
    sfBool grounded;
} box_t;

typedef struct ground_s {
    sfRectangleShape *ground;
    struct ground_s *next;
} ground_t;

typedef struct player_s {
    sfVector2f offset;
    sfClock *fall_time;
    sfBool grounded;
    sfBool spell;
    int movement;
} player_t;

typedef struct object_s {
    ground_t *ground;
    box_t *boxs;
    box_t *spell_box;
    sfCircleShape *arrow;
} object_t;

typedef struct sprite_s {
    sfSprite *player;
    sfSprite *background;
} sprite_t;

typedef struct game_s {
    player_t *player;
    object_t *object;
    sprite_t *sprite;
} game_t;

int game(game_t *game);
void collision(game_t *game);
game_t *init_game(void);
void process_keys(game_t *game);
void free_game(game_t *game);
void move(game_t *game);
int render(sfRenderWindow *window, game_t *game);
void spell(game_t *game);
void analyse_event(sfRenderWindow *window, sfEvent event, game_t *game);
void jump(game_t *game);
void free_all(sfRenderWindow *window, game_t *game, sfClock *clock);
void collision_player_wall(game_t *game);
void collision_box(game_t *game);
void collision_head_box_player(game_t *game, box_t *box);
int collision_side_left_box_player(game_t *game, box_t *box);
int collision_side_right_box_player(game_t *game, box_t *box);
int collision_side_left_box(game_t *game, box_t *box);
int collision_side_right_box(game_t *game, box_t *box);


#endif
