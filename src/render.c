
#include "magicube.h"
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>

int render_arrow(sfRenderWindow *window, game_t *game)
{
    sfVector2f pos_arrow = sfSprite_getPosition(game->sprite->player);
    sfFloatRect bound = sfSprite_getGlobalBounds(game->sprite->player);

    pos_arrow.x -= 10 + bound.width / 2;
    sfCircleShape_setPosition(game->object->arrow, pos_arrow);
    sfCircleShape_setRotation(game->object->arrow, 270);
    sfRenderWindow_drawCircleShape(window, game->object->arrow, NULL);

    pos_arrow.x += 20 + bound.width;
    sfCircleShape_setRotation(game->object->arrow, 90);
    sfCircleShape_setPosition(game->object->arrow, pos_arrow);
    sfRenderWindow_drawCircleShape(window, game->object->arrow, NULL);
    return EXIT_SUCCESS;
}

int render(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_drawSprite(window, game->sprite->background, NULL);
    sfRenderWindow_drawSprite(window, game->sprite->player, NULL);
    for (ground_t *ground = game->object->ground; ground != NULL; ground = ground->next) {
        sfRenderWindow_drawRectangleShape(window, ground->ground, NULL);
    }
    for (box_t *box = game->object->boxs; box != NULL; box = box->next) {
        sfRenderWindow_drawRectangleShape(window, box->box, NULL);
    }
    if (game->player->spell == 1)
        render_arrow(window, game);
    return EXIT_SUCCESS;
}