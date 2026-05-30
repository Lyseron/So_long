/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-13 10:35:03 by lyaberge          #+#    #+#             */
/*   Updated: 2026-01-13 10:35:03 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_init_gameplay(char **argv, t_game *g)
{
	g->height = ft_count_line(argv[1]);
	g->width = ft_strlen(g->map[0]);
	g->collectible_collected = 0;
	g->collectible_total = ft_count_collectible(g->map);
	g->moves = 0;
	g->box = 64;
}

static void	ft_init_image(t_game *g)
{
	int	width;
	int	height;

	g->player_image = mlx_xpm_file_to_image(g->mlx,
			"sprites/player.xpm", &width, &height);
	g->floor_image = mlx_xpm_file_to_image(g->mlx,
			"sprites/floor.xpm", &width, &height);
	g->wall_image = mlx_xpm_file_to_image(g->mlx,
			"sprites/wall.xpm", &width, &height);
	g->collectible_image = mlx_xpm_file_to_image(g->mlx,
			"sprites/collect.xpm", &width, &height);
	g->exit_image = mlx_xpm_file_to_image(g->mlx,
			"sprites/exit.xpm", &width, &height);
}

// to free the graphique/malloc/fd ressources when the game is over
// or in case of a issue or when the game is closed
void	ft_close(t_game *g)
{
	if (g->mlx != NULL && g->floor_image != NULL)
		mlx_destroy_image(g->mlx, g->floor_image);
	if (g->mlx != NULL && g->wall_image != NULL)
		mlx_destroy_image(g->mlx, g->wall_image);
	if (g->mlx != NULL && g->collectible_image != NULL)
		mlx_destroy_image(g->mlx, g->collectible_image);
	if (g->mlx != NULL && g->exit_image != NULL)
		mlx_destroy_image(g->mlx, g->exit_image);
	if (g->mlx != NULL && g->player_image != NULL)
		mlx_destroy_image(g->mlx, g->player_image);
	if (g->mlx != NULL && g->win != NULL)
		mlx_destroy_window(g->mlx, g->win);
	if (g->map != NULL)
		ft_free(g->map);
	if (g->mlx != NULL)
	{
		// mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
}

static int	ft_main_bis(char **argv, t_game *g)
{
	if (ft_decide(argv[1]) == 1)
		return (write(2, "Error extenxion map\n", 20), 1);
	g->fd = ft_open_and_create_map_tab(g, argv);
	if (g->fd == -1)
		return (write(2, "Error reading/opening map\n", 26), 1);
	close(g->fd);
	if (ft_final_check(g->map) == 1)
		return (ft_free(g->map), write(2, "Error map\n", 10), 1);
	return (0);
}

int	ft_close_and_exit(t_game *g)
{
	ft_close(g);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	g;

	if (argc != 2)
		return (write(2, "Error: wrong number of imput\n", 29), 1);
	if (ft_main_bis(argv, &g) == 1)
		return (1);
	ft_init_gameplay(argv, &g);
	ft_found_player_pos(g.map, &g.player_x, &g.player_y);
	g.mlx = mlx_init();
	if (!g.mlx)
		return (ft_free(g.map), 1);
	ft_init_image(&g);
	if (!g.floor_image || !g.wall_image || !g.exit_image
		|| !g.collectible_image || !g.player_image)
		return (ft_close(&g), write(2, "Error with the images\n", 22), 1);
	g.win = mlx_new_window(g.mlx, g.width * g.box,
			g.height * g.box, "so_long");
	if (!g.win)
		return (ft_close(&g), 1);
	ft_print_map(&g);
	mlx_hook(g.win, 2, 1L << 0, ft_key_in_game, &g);
	mlx_hook(g.win, 17, 0, ft_close_and_exit, &g);
	mlx_loop(g.mlx);
	return (0);
}
