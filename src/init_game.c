
#include "magicube.h"
#include <SFML/Config.h>
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>
#include <stdlib.h>

int init_box(game_t *game)
{
    box_t *box = malloc(sizeof(box_t));

    if (!box)
        return EXIT_FAILURE;
    box->box = sfRectangleShape_create();
    box->fall_time = sfClock_create();
    if (!box->box || !box->fall_time)
        return EXIT_FAILURE;
    box->grounded = 0;
    sfRectangleShape_setSize(box->box, (sfVector2f){20, 20});
    sfRectangleShape_setOrigin(box->box, (sfVector2f){10, 10});
    sfRectangleShape_setPosition(box->box, (sfVector2f){530, 400});
    sfRectangleShape_setFillColor(box->box, sfGreen);
    box->next = game->object->boxs;
    game->object->boxs = box;

    box = malloc(sizeof(box_t));

    if (!box)
        return EXIT_FAILURE;
    box->box = sfRectangleShape_create();
    box->fall_time = sfClock_create();
    if (!box->box || !box->fall_time)
        return EXIT_FAILURE;
    box->grounded = 0;
    sfRectangleShape_setSize(box->box, (sfVector2f){20, 20});
    sfRectangleShape_setOrigin(box->box, (sfVector2f){10, 10});
    sfRectangleShape_setPosition(box->box, (sfVector2f){515, 450});
    sfRectangleShape_setFillColor(box->box, sfGreen);
    box->next = game->object->boxs;
    game->object->boxs = box;

        box = malloc(sizeof(box_t));

    if (!box)
        return EXIT_FAILURE;
    box->box = sfRectangleShape_create();
    box->fall_time = sfClock_create();
    if (!box->box || !box->fall_time)
        return EXIT_FAILURE;
    box->grounded = 0;
    sfRectangleShape_setSize(box->box, (sfVector2f){20, 20});
    sfRectangleShape_setOrigin(box->box, (sfVector2f){10, 10});
    sfRectangleShape_setPosition(box->box, (sfVector2f){500, 500});
    sfRectangleShape_setFillColor(box->box, sfGreen);
    box->next = game->object->boxs;
    game->object->boxs = box;

    box = malloc(sizeof(box_t));

    if (!box)
        return EXIT_FAILURE;
    box->box = sfRectangleShape_create();
    box->fall_time = sfClock_create();
    if (!box->box || !box->fall_time)
        return EXIT_FAILURE;
    box->grounded = 0;
    sfRectangleShape_setSize(box->box, (sfVector2f){20, 20});
    sfRectangleShape_setOrigin(box->box, (sfVector2f){10, 10});
    sfRectangleShape_setPosition(box->box, (sfVector2f){485, 550});
    sfRectangleShape_setFillColor(box->box, sfGreen);
    box->next = game->object->boxs;
    game->object->boxs = box;

        box = malloc(sizeof(box_t));

    if (!box)
        return EXIT_FAILURE;
    box->box = sfRectangleShape_create();
    box->fall_time = sfClock_create();
    if (!box->box || !box->fall_time)
        return EXIT_FAILURE;
    box->grounded = 0;
    sfRectangleShape_setSize(box->box, (sfVector2f){20, 20});
    sfRectangleShape_setOrigin(box->box, (sfVector2f){10, 10});
    sfRectangleShape_setPosition(box->box, (sfVector2f){470, 600});
    sfRectangleShape_setFillColor(box->box, sfGreen);
    box->next = game->object->boxs;
    game->object->boxs = box;

    box = malloc(sizeof(box_t));

    if (!box)
        return EXIT_FAILURE;
    box->box = sfRectangleShape_create();
    box->fall_time = sfClock_create();
    if (!box->box || !box->fall_time)
        return EXIT_FAILURE;
    box->grounded = 0;
    sfRectangleShape_setSize(box->box, (sfVector2f){20, 20});
    sfRectangleShape_setOrigin(box->box, (sfVector2f){10, 10});
    sfRectangleShape_setPosition(box->box, (sfVector2f){455, 650});
    sfRectangleShape_setFillColor(box->box, sfGreen);
    box->next = game->object->boxs;
    game->object->boxs = box;

    return EXIT_SUCCESS;
}

int init_ground(game_t *game)
{
    ground_t *ground = malloc(sizeof(object_t));
    sfVector2f size = {1920, 50};
    sfVector2f position = {1920.0/2, 1080 - 250};

    if (!ground)
        return EXIT_FAILURE;
    ground->ground = sfRectangleShape_create();
    if (!ground->ground)
        return EXIT_FAILURE;
    sfRectangleShape_setSize(ground->ground, size);
    sfRectangleShape_setFillColor(ground->ground, sfBlack);
    sfRectangleShape_setOrigin(ground->ground, (sfVector2f){size.x / 2, size.y / 2});
    sfRectangleShape_setPosition(ground->ground, position);
    ground->next = game->object->ground;
    game->object->ground = ground;

    ground = malloc(sizeof(object_t));
    size = (sfVector2f){50, 1000};
    position = (sfVector2f){1920.0/3, 1080 - 250};
    if (!ground)
        return EXIT_FAILURE;
    ground->ground = sfRectangleShape_create();
    if (!ground->ground)
        return EXIT_FAILURE;
    sfRectangleShape_setSize(ground->ground, size);
    sfRectangleShape_setFillColor(ground->ground, sfBlack);
    sfRectangleShape_setOrigin(ground->ground, (sfVector2f){size.x / 2, size.y / 2});
    sfRectangleShape_setPosition(ground->ground, position);
    ground->next = game->object->ground;
    game->object->ground = ground;

    ground = malloc(sizeof(object_t));
    size = (sfVector2f){50, 1000};
    position = (sfVector2f){1920.0/6, 1080 - 250};
    if (!ground)
        return EXIT_FAILURE;
    ground->ground = sfRectangleShape_create();
    if (!ground->ground)
        return EXIT_FAILURE;
    sfRectangleShape_setSize(ground->ground, size);
    sfRectangleShape_setFillColor(ground->ground, sfBlack);
    sfRectangleShape_setOrigin(ground->ground, (sfVector2f){size.x / 2, size.y / 2});
    sfRectangleShape_setPosition(ground->ground, position);
    ground->next = game->object->ground;
    game->object->ground = ground;

    game->object->arrow = sfCircleShape_create();
    if (!game->object->arrow)
        return EXIT_FAILURE;
    sfCircleShape_setPointCount(game->object->arrow, 3);
    sfCircleShape_setRadius(game->object->arrow, 5);
    sfCircleShape_setFillColor(game->object->arrow, sfYellow);
    sfCircleShape_setOrigin(game->object->arrow, (sfVector2f){5, 5});

    return EXIT_SUCCESS;
}

int init_sprite(sprite_t *data_sprite)
{
    sfTexture *texture;
    sfSprite *sprite;

    data_sprite->background = NULL;
    data_sprite->player = NULL;

    texture = sfTexture_createFromFile(BACKGROUND, NULL);
    if (!texture)
        return EXIT_FAILURE;
    sprite = sfSprite_create();
    if (!sprite)
        return EXIT_FAILURE;
    sfSprite_setTexture(sprite, texture, sfFalse);
    data_sprite->background = sprite;

    texture = sfTexture_createFromFile(PLAYER, NULL);
    if (!texture)
        return EXIT_FAILURE;
    sprite = sfSprite_create();
    if (!sprite)
        return EXIT_FAILURE;
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setOrigin(sprite, (sfVector2f){10, 10});
    data_sprite->player = sprite;
    sfSprite_setPosition(sprite, (sfVector2f){1920.0/4.5, 250});

    return EXIT_SUCCESS;
}

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return NULL;
    game->player = malloc(sizeof(player_t));
    game->sprite = malloc(sizeof(sprite_t));
    game->object = malloc(sizeof(object_t));

    if (!game->sprite || !game->player || !game->object) {
        free_game(game);
        return NULL;
    }
    game->player->offset = (sfVector2f){0, 0};
    game->player->fall_time = sfClock_create();
    game->player->spell = 0;
    game->player->grounded = 0;
    game->player->movement = 0;
    game->sprite->background = NULL;
    game->sprite->player = NULL;
    game->object->ground = NULL;
    game->object->arrow = NULL;
    game->object->boxs = NULL;
    game->object->spell_box = NULL;
    if (!game->player->fall_time || init_sprite(game->sprite) != 0) {
        free_game(game);
        return NULL;
    }
    if (init_ground(game) != 0) {
        free(game);
        return NULL;
    }
    if (init_box(game) != 0) {
        free(game);
        return NULL;
    }
    return game;
}