#include "/home/rallali/Desktop/cub3d/include/cub3d.h"

int is_space_or_tab(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

int is_wall_or_walkable(char c)
{
    return (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

char *ft_strtrim(const char *s1, const char *set)
{
    size_t start = 0, end, i = 0;
    char *str;

    if (!s1 || !set)
        return (NULL);
    while (s1[start] && ft_strchr(set, s1[start])) start++;
    end = ft_strlen(s1);
    while (end > start && ft_strchr(set, s1[end - 1])) end--;
    str = malloc(end - start + 1);
    if (!str) return (NULL);
    while (start < end) str[i++] = s1[start++];
    str[i] = '\0';
    return (str);
}
