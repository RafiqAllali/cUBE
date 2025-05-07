#include "/home/eren/Desktop/cub3d/include/cub3d.h"

void store_map_dimensions(t_map *map)
{
    int y = 0, max_width = 0, current_width;
    while (y < map->height)
    {
        current_width = ft_strlen(map->grid[y]);
        if (current_width > max_width)
            max_width = current_width;
        y++;
    }
    map->width = max_width;
}

void free_map_grid(t_map *map)
{
    int i = 0;
    while (i < map->height)
        free(map->grid[i++]);
    free(map->grid);
}
