#include "/home/eren/Desktop/cub3d/include/cub3d.h"

// Handle key presses
void key_handler(void *param)
{
    t_game *game = (t_game *)param;
    
    // Exit on ESC
    if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
        mlx_close_window(game->mlx);
    
    // Movement
    handle_movement(game);
    
    // Rotation with arrow keys
    handle_rotation(game);
}

// Handle player movement
void handle_movement(t_game *game)
{
    float move_x = 0;
    float move_y = 0;
    
    // Forward/backward movement
    if (mlx_is_key_down(game->mlx, MLX_KEY_W))
    {
        move_x += cos(game->player.angle) * MOVE_SPEED;
        move_y += sin(game->player.angle) * MOVE_SPEED;
    }
    if (mlx_is_key_down(game->mlx, MLX_KEY_S))
    {
        move_x -= cos(game->player.angle) * MOVE_SPEED;
        move_y -= sin(game->player.angle) * MOVE_SPEED;
    }
    
    handle_strafing(game, &move_x, &move_y);
}

// Handle player rotation
void handle_rotation(t_game *game)
{
    // Rotation with arrow keys
    if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
    {
        game->player.angle -= ROT_SPEED;
        if (game->player.angle < 0)
            game->player.angle += PI2;
    }
    if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
    {
        game->player.angle += ROT_SPEED;
        if (game->player.angle >= PI2)
            game->player.angle -= PI2;
    }
}