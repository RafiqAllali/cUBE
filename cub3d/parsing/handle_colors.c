#include "/home/rallali/Desktop/cub3d/include/cub3d.h"

int check_how_many_commas(char *line)
{
    int commas = 0;
    while (*line)
        if (*line++ == ',') commas++;
    return (commas);
}

void fill_and_validate_color(char **rgb_values, int color[3], int *color_set)
{
    int i = 0;
    char *trimmed;

    while (i < 3)
    {
        trimmed = ft_strtrim(rgb_values[i], " \t\n\r");
        color[i] = ft_atoi(trimmed);
        free(trimmed);
        free(rgb_values[i]);
        if (color[i] < 0 || color[i] > 255)
        {
            write(2, "Error: Color values must be 0-255\n", 34);
            color[0] = -1; // mark as error
            return;
        }
        i++;
    }

    free(rgb_values);

    if (color[0] != -1)
        (*color_set)++;
}

void parse_color(char *line, int color[3], int *color_set)
{
    if (*color_set > 0)
    {
        write(2, "Error: Duplicate color definition\n", 33);
        return;
    }

    while (*line == ' ')
        line++;

    if (check_how_many_commas(line) != 2)
    {
        write(2, "Error: Incorrect comma count\n", 29);
        return;
    }

    char **rgb_values = ft_split(line, ',');
    if (!rgb_values)
    {
        write(2, "Error: Invalid color format\n", 28);
        return;
    }

    int count = 0;
    while (rgb_values[count])
        count++;

    if (count != 3)
    {
        write(2, "Error: Color needs 3 values\n", 28);
        while (count--) // free individual strings
            free(rgb_values[count]);
        free(rgb_values);
        return;
    }

    fill_and_validate_color(rgb_values, color, color_set);
}

int check_colors_availability(t_config *config)
{
    return (config->colors.floor_set > 1 || config->colors.cell_set > 1);
}
