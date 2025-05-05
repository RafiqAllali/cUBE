#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include "/home/rallali/Desktop/cub3d/MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <stdint.h>

typedef struct s_player {
    float x;
    float y;
    float angle;
} t_player;

typedef struct s_game {
    mlx_t *mlx;
    mlx_image_t *img_map;
    t_player player;
} t_game;
#endif // CUB3D_H