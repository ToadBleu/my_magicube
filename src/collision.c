
#include "plane.h"
#include <SFML/Config.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Sprite.h>
#include <sys/cdefs.h>

void collision(game_t *game)
{
    sfFloatRect player_feet = sfSprite_getGlobalBounds(game->sprite->player);
    sfFloatRect ground = sfRectangleShape_getGlobalBounds(game->object->ground);

    player_feet.top = player_feet.top + player_feet.height;
    player_feet.height = 2;
    player_feet.left = player_feet.left - 2;
    player_feet.width = player_feet.width - 4;

    if (sfFloatRect_intersects(&player_feet, &ground, NULL) == sfTrue) {
        game->player->grounded = 1;
        return;
    }
    game->player->grounded = 0;
    return;
}