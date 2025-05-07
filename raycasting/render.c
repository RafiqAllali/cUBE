#include "/home/eren/Desktop/cub3d/include/cub3d.h"

// Draw ceiling and floor
void draw_ceiling_floor(t_game *game)
{
    uint32_t *pixels = (uint32_t *)game->img->pixels;
    
    // Draw ceiling
    int ceiling_y = 0;
    while (ceiling_y < SCREEN_HEIGHT / 2)
    {
        int ceiling_x = 0;
        while (ceiling_x < SCREEN_WIDTH)
        {
            pixels[ceiling_y * SCREEN_WIDTH + ceiling_x] = game->ceiling_color;
            ceiling_x++;
        }
        ceiling_y++;
    }
    
    // Draw floor
    int floor_y = SCREEN_HEIGHT / 2;
    while (floor_y < SCREEN_HEIGHT)
    {
        int floor_x = 0;
        while (floor_x < SCREEN_WIDTH)
        {
            pixels[floor_y * SCREEN_WIDTH + floor_x] = game->floor_color;
            floor_x++;
        }
        floor_y++;
    }
}

// Normalize angle to [0, 2π)
void normalize_angle(double *angle)
{
    if (*angle < 0)
        *angle += PI2;
    if (*angle >= PI2)
        *angle -= PI2;
}

// Main render function
void render_frame(void *param)
{
    t_game *game = (t_game *)param;
    
    // Cast rays to render the 3D view
    cast_rays(game);
}