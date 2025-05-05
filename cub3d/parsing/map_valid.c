#include "/home/rallali/Desktop/cub3d/include/cub3d.h"

int validate_map_walls(t_map *map)
{
    int y = 0, x, len;
    while (y < map->height)
    {
        x = 0;
        len = ft_strlen(map->grid[y]);
        while (x < len)
        {
            if ((y == 0 || y == map->height - 1 || x == 0 || x == len - 1) &&
                map->grid[y][x] != '1' && !is_space_or_tab(map->grid[y][x]))
            {
                write(2, "Error: Invalid map border\n", 27);
                return (1);
            }
            x++;
        }
        y++;
    }
    return (0);
}

int validate_player_position(t_map *map)
{
    int y = 0, x, player_count = 0;
    while (y < map->height)
    {
        x = 0;
        while (map->grid[y][x])
        {
            if (ft_strchr("NSEW", map->grid[y][x]))
            {
                player_count++;
                map->player_dir = map->grid[y][x];
                map->player_x = x;
                map->player_y = y;
                map->grid[y][x] = '0';
            }
            x++;
        }
        y++;
    }
    if (player_count != 1)
        return (write(2, "Error: Map must contain exactly one player\n", 43), 1);
    return (0);
}
