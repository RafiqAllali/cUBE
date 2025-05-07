#include "/home/eren/Desktop/cub3d/include/cub3d.h"

// Handle player strafing and collision
void handle_strafing(t_game *game, float *move_x, float *move_y)
{
    // Strafing left/right
    if (mlx_is_key_down(game->mlx, MLX_KEY_A))
    {
        *move_x += cos(game->player.angle - PI / 2) * MOVE_SPEED;
        *move_y += sin(game->player.angle - PI / 2) * MOVE_SPEED;
    }
    if (mlx_is_key_down(game->mlx, MLX_KEY_D))
    {
        *move_x += cos(game->player.angle + PI / 2) * MOVE_SPEED;
        *move_y += sin(game->player.angle + PI / 2) * MOVE_SPEED;
    }
    
    // Apply movement with collision detection
    if (*move_x != 0 || *move_y != 0)
        apply_movement(game, *move_x, *move_y);
}

// Apply movement with collision detection
void apply_movement(t_game *game, float move_x, float move_y)
{
    // Check x and y movements separately for better collision
    float new_x = game->player.x + move_x;
    float new_y = game->player.y + move_y;
    
    // Add a small buffer to prevent gliding through wall corners
    float buffer = 0.2;
    
    // Check x movement
    if ((int)new_x >= 0 && (int)new_x < game->map.width &&
        (int)game->player.y >= 0 && (int)game->player.y < game->map.height &&
        game->map.grid[(int)game->player.y][(int)new_x] != '1' &&
        // Check diagonal corners too
        game->map.grid[(int)(game->player.y - buffer)][(int)new_x] != '1' &&
        game->map.grid[(int)(game->player.y + buffer)][(int)new_x] != '1')
    {
        game->player.x = new_x;
    }
    
    // Check y movement
    check_y_collision(game, new_y, buffer);
}

// Check Y collision
void check_y_collision(t_game *game, float new_y, float buffer)
{
    if ((int)game->player.x >= 0 && (int)game->player.x < game->map.width &&
        (int)new_y >= 0 && (int)new_y < game->map.height &&
        game->map.grid[(int)new_y][(int)game->player.x] != '1' &&
        // Check diagonal corners too
        game->map.grid[(int)new_y][(int)(game->player.x - buffer)] != '1' &&
        game->map.grid[(int)new_y][(int)(game->player.x + buffer)] != '1')
    {
        game->player.y = new_y;
    }
}