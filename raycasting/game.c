#include "/home/eren/Desktop/cub3d/include/cub3d.h"

// Main game loop
void game_loop(t_config *config)
{
    t_game game;
    
    // Initialize the game
    if (!init_game(&game, config))
    {
        // printf("Error: Failed to initialize game\n");
        return;
    }
    
    // Set up hooks and run game
    setup_and_run_game(&game);
}

// Set up hooks and run game
void setup_and_run_game(t_game *game)
{
    // Set up hooks
    mlx_loop_hook(game->mlx, &render_frame, game);
    mlx_loop_hook(game->mlx, &key_handler, game);
    
    // Start the main loop
    mlx_loop(game->mlx);
    
    // Clean up
    cleanup_game(game);
}

// Clean up resources
void cleanup_game(t_game *game)
{
    // Delete image
    mlx_delete_image(game->mlx, game->img);
    
    // Free textures
    int i = 0;
    while (i < 4)
    {
        mlx_delete_texture(game->textures[i]);
        i++;
    }   
    // Terminate MLX
    mlx_terminate(game->mlx);
}