
#include "plane.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>

int render(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_drawSprite(window, game->sprite->background, NULL);
    sfRenderWindow_drawSprite(window, game->sprite->player, NULL);
    for (object_t *obj = game->object; obj != NULL; obj = obj->next) {
        sfRenderWindow_drawRectangleShape(window, obj->ground, NULL);
    }
    return EXIT_SUCCESS;
}