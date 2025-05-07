#include "/home/eren/Desktop/cub3d/include/cub3d.h"

// Initialize textures and image
bool init_textures_and_image(t_game *game, t_config *config)
{
    // Initialize textures
    if (!load_textures(game, config))
        return false;
    
    // Create image for rendering
    game->img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!game->img)
        return false;

    // Display the image
    if (mlx_image_to_window(game->mlx, game->img, 0, 0) < 0)
        return false;
    
    return true;
}

// Load all textures from config
bool load_textures(t_game *game, t_config *config)
{
    mlx_texture_t *north_tex = mlx_load_png(config->textures.north);
    mlx_texture_t *south_tex = mlx_load_png(config->textures.south);
    mlx_texture_t *east_tex = mlx_load_png(config->textures.east);
    mlx_texture_t *west_tex = mlx_load_png(config->textures.west);
    
    if (!north_tex || !south_tex || !east_tex || !west_tex)
        return false;
    
    // Print texture info for debugging
    // print_texture_info(north_tex, south_tex, east_tex, west_tex);
    
    game->textures[NORTH] = north_tex;
    game->textures[SOUTH] = south_tex;
    game->textures[EAST] = east_tex;
    game->textures[WEST] = west_tex;
    
    return true;
}

// Print texture information
