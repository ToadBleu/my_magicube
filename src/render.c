
#include "magicube.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>

int render(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_drawSprite(window, game->sprite->background, NULL);
    sfRenderWindow_drawSprite(window, game->sprite->player, NULL);
    for (ground_t *ground = game->object->ground; ground != NULL; ground = ground->next) {
        sfRenderWindow_drawRectangleShape(window, ground->ground, NULL);
    }

    return EXIT_SUCCESS;
}