
#include "plane.h"
#include <SFML/Config.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>

void collision_ground(game_t *game, object_t *object)
{
    sfFloatRect player_feet = sfSprite_getGlobalBounds(game->sprite->player);
    sfFloatRect ground = sfRectangleShape_getGlobalBounds(object->ground);
    sfVector2f pos_up = {player_feet.left, ground.top - player_feet.height};

    player_feet.top = player_feet.top + player_feet.height;
    player_feet.height = 2;
    player_feet.left = player_feet.left - 2;
    player_feet.width = player_feet.width - 4;

    if (sfFloatRect_intersects(&player_feet, &ground, NULL) == sfTrue) {
        game->player->grounded = 1;
        sfSprite_setPosition(game->sprite->player, pos_up);
    } else
        game->player->grounded = 0;
    return;
}

void collision(game_t *game)
{
    for (object_t *obj = game->object; obj != NULL; obj = obj->next) {
        collision_ground(game, obj);
    }
}