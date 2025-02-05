
#include "plane.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>

int render(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_drawSprite(window, game->sprite->background, NULL);
    sfRenderWindow_drawSprite(window, game->sprite->player, NULL);
    sfRenderWindow_drawRectangleShape(window, game->object->ground, NULL);
    return EXIT_SUCCESS;
}