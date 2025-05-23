#include "cub3d.h"
void	read_map(int fd, t_config *config)
{
	char	*line;
	char	*trimmed;
	int		i = 0;
	int		map_started = 0;

	while ((line = get_next_line(fd)) != NULL)
	{
		trimmed = ft_strtrim(line, "\n");
		free(line);
		if (map_started && trimmed[0] == '\0')
		{
			free(trimmed);
			trimmed = ft_strdup(" ");
		}
		else if (trimmed[0] == '\0' || trimmed[0] == '#')
		{
			free(trimmed);
			continue;
		}
		if (handle_textures(trimmed, config, &map_started)
			|| handle_colors(trimmed, config, &map_started)
			|| handle_map_line(trimmed, config, &map_started, &i))
			free(trimmed);
		else
			return (write(2, "Error: Invalid line in map file\n", 32), free(trimmed));
	}
	config->map.height = i;
}
int check_availaibility(t_config *config)
{
    if (!config->textures.north)
       return (1);
    else if (!config->textures.south)
        return (1);
    else if (!config->textures.east)
        return (1);
    else if (!config->textures.west)
        return (1);
    return (0);
}
int parsing(t_config *config, char *filename)
{
    int fd;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (1); 
    config->map.grid = malloc(sizeof(char *) * MAX_MAP_HEIGHT);
    if (config->map.grid == NULL)
    {
        write(2, "Error: Memory allocation failed\n", 31);
        close(fd);
        return (1);
    }

    read_map(fd, config);
    if (check_availaibility(config) == 1 || check_colors_availability(config))
    {
        write(2,"Error: invalid map\n",19);
        return (1);
    }

    if (validate_configuration(config) ||
        validate_map_walls(&config->map) ||
        validate_player_position(&config->map))
    {
        write(2, "Error: Invalid configuration\n", 30);
        return (1);
    }
    store_map_dimensions(&config->map);
    close(fd);
    return (0);
}

void init_data(t_config *config)
{
    config->textures.north = NULL;
    config->textures.south = NULL;
    config->textures.west = NULL;
    config->textures.east = NULL;
    config->colors.floor[0] = -1;
    config->colors.floor[1] = -1;
    config->colors.floor[2] = -1;
    config->colors.floor[3] = -1;
    config->colors.ceiling[0] = -1;
    config->colors.ceiling[1] = -1;
    config->colors.ceiling[2] = -1;
    config->colors.ceiling[3] = -1;
    config->map.grid = NULL;
    config->map.width = 0;
    config->map.height = 0;
    config->map.player_dir = 0;
    config->map.player_x = 0;
    config->map.player_y = 0;
    config->colors.floor_set = 0;
    config->colors.cell_set = 0;
}

int main(int ac, char **av)
{
    t_config config;

    if (ac != 2 || check_extension(av[1]) == 1)
    {
        write(2, "Error: Usage: ./cub3D <map.cub>\n", 32);
        return (1);
    }
    init_data(&config);
    if (parsing(&config, av[1]) == 1)
        return (1);
    
    // Start the game loop with parsed configuration
    game_loop(&config);
    
    // Clean up
    free_map_grid(&config.map);
    free(config.textures.north);
    free(config.textures.south);
    free(config.textures.east);
    free(config.textures.west);
    
    return (0);
}