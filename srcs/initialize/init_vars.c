#include "../cub3d.h"

/* Initializes MLX and the Window configurations */
static void	init_mlx_window(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIN_W, WIN_H, "cub3d");
}

char	**read_map()
{
	int fd;
	char *buffer;
	char **map;
	int i = 0;

	fd = open("maps/dummy.cub", O_RDWR);
	buffer = malloc(100000);
	map = ft_calloc(100, sizeof(char *));
	while ((buffer = get_next_line(fd)) != NULL)
		map[i++] = buffer;
	return (map);
}

static void	init_map(t_vars *vars)
{
	vars->map.n_img.ptr = NULL;
	vars->map.e_img.ptr = NULL;
	vars->map.s_img.ptr = NULL;
	vars->map.w_img.ptr = NULL;
	vars->map.d_img.ptr = NULL;
	vars->map.map = read_map();
	vars->map.c_rgb.hex = -1;
	vars->map.f_rgb.hex = -1;
	vars->map.main = ft_calloc(1, sizeof(t_img));
	vars->map.mini = ft_calloc(1, sizeof(t_img));
	vars->map.imgw.ptr = mlx_new_image(vars->mlx, WIN_W, WIN_H);
	vars->map.size.x = 42;
	vars->map.size.y = 20;
	// vars->map.door_state = D_OPEN;
	// vars->map.imgw.addr = mlx_get_data_addr(vars->map.imgw.ref, &vars->map.imgw.bpp,
	// 		&vars->map.imgw.sl, &vars->map.imgw.end);
}

static void	init_player(t_vars *vars)
{
	// vars->player.mpos.x = 13;
	// vars->player.mpos.y = 9;
	vars->player.pos.x = 13 * MINI_PX; // 2D - Centre of MLX window
	vars->player.pos.y = 11 * MINI_PX; // 2D
	vars->player.dir.x = cos(-PI/2) * 120; // N
	vars->player.dir.y = sin(-PI/2) * 120; // N
	vars->player.rotate = -PI/2;
	return ;
}

/**
 * @brief Master initialize function for mlx, map and player. 
 * 
 * @param vars Master struct
 */
void	init_vars(t_vars *vars)
{
	init_mlx_window(vars);
	init_map(vars);
	init_player(vars);
}