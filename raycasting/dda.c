#include "/home/eren/Desktop/cub3d/include/cub3d.h"

// Setup for DDA algorithm
void setup_dda(t_game *game, double *side_dist_x, double *side_dist_y, 
               int *step_x, int *step_y, double ray_dir_x, double ray_dir_y, 
               int map_x, int map_y)
{
    // Calculate step and initial side_dist
    if (ray_dir_x < 0)
    {
        *step_x = -1;
        *side_dist_x = (game->player.x - map_x) * fabs(1 / ray_dir_x);
    }
    else
    {
        *step_x = 1;
        *side_dist_x = (map_x + 1.0 - game->player.x) * fabs(1 / ray_dir_x);
    }
    
    if (ray_dir_y < 0)
    {
        *step_y = -1;
        *side_dist_y = (game->player.y - map_y) * fabs(1 / ray_dir_y);
    }
    else
    {
        *step_y = 1;
        *side_dist_y = (map_y + 1.0 - game->player.y) * fabs(1 / ray_dir_y);
    }
}

// Perform DDA algorithm
void perform_dda(t_game *game, int *hit, int *side, int *map_x, int *map_y,
                 double *side_dist_x, double *side_dist_y, 
                 double delta_dist_x, double delta_dist_y, 
                 int step_x, int step_y)
{
    while (!(*hit))
    {
        // Jump to next map square
        if (*side_dist_x < *side_dist_y)
        {
            *side_dist_x += delta_dist_x;
            *map_x += step_x;
            *side = 0;
        }
        else
        {
            *side_dist_y += delta_dist_y;
            *map_y += step_y;
            *side = 1;
        }
        
        // Check if ray has hit a wall
        if (*map_y < 0 || *map_y >= game->map.height || 
            *map_x < 0 || *map_x >= game->map.width ||
            game->map.grid[*map_y][*map_x] == '1')
            *hit = 1;
    }
}