#include "/home/eren/Desktop/cub3d/include/cub3d.h"

// Set initial player angle based on direction from parser
void set_player_angle(t_game *game, t_config *config)
{
    game->player.angle = 0;
    if (config->map.player_dir == 'N')
        game->player.angle = 270 * DEG_TO_RAD;
    else if (config->map.player_dir == 'S')
        game->player.angle = 90 * DEG_TO_RAD;
    else if (config->map.player_dir == 'E')
        game->player.angle = 0;
    else if (config->map.player_dir == 'W')
        game->player.angle = 180 * DEG_TO_RAD;
}

// Initialize the game data and MLX window
bool init_game(t_game *game, t_config *config)
{
    // Set player position and angle
    set_player_angle(game, config);
    game->player.x = config->map.player_x + 0.5;
    game->player.y = config->map.player_y + 0.5;
    
    // Store map for collision detection
    game->map = config->map;
    
    // Print colors from config for debugging
    // printf("Ceiling color: R=%d, G=%d, B=%d\n", 
        //    config->colors.ceiling[0], 
        //    config->colors.ceiling[1], 
        //    config->colors.ceiling[2]);
    // printf("Floor color: R=%d, G=%d, B=%d\n", 
        //    config->colors.floor[0], 
        //    config->colors.floor[1], 
        //    config->colors.floor[2]);
    
    // Set up colors and window
    return init_colors_and_window(game, config);
}

// Initialize colors and MLX window
bool init_colors_and_window(t_game *game, t_config *config)
{
    // Store colors - fixed the color byte order to match MLX requirements
    game->ceiling_color = (config->colors.ceiling[0] << 16) | 
                          (config->colors.ceiling[1] << 8) | 
                          (config->colors.ceiling[2]) | 
                          (255 << 24);  // Alpha is always 255 (opaque)
                          
    game->floor_color = (config->colors.floor[0] << 16) | 
                        (config->colors.floor[1] << 8) | 
                        (config->colors.floor[2]) | 
                        (255 << 24);  // Alpha is always 255 (opaque)
    
    // Initialize MLX window
    game->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D", false);
    if (!game->mlx)
        return false;
    
    // Initialize textures and image
    return init_textures_and_image(game, config);
}