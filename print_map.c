/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-16 16:55:21 by lyaberge          #+#    #+#             */
/*   Updated: 2026-01-16 16:55:21 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// test the possible move depending on the key press on the keyboard
// w = up -> x = 0, y = -1 
// s = down -> x = 0, y = 1
// a = left -> x = -1, y = 0
// d = right -> x = 1, y = 0
// if retour = 0 -> move possible (change position of the player)
// if retour = 1 -> move impossible (don't change the pos of the player)
// if retour = 2 -> WIN
static int	ft_key_choice(t_game *g, char *key)
{
	int	retour;

	retour = 0;
	if (*key == 'w')
		retour = ft_possible_move(g, 0, -1);
	else if (*key == 's')
		retour = ft_possible_move(g, 0, 1);
	else if (*key == 'a')
		retour = ft_possible_move(g, -1, 0);
	else if (*key == 'd')
		retour = ft_possible_move(g, 1, 0);
	return (retour);
}

// Mac : W=13, A=0, D=2, ESC=53
// linux : W=119, A=97, S=115, D=100, ESC=65307
int	ft_key_in_game(int key_choice, t_game *g)
{
	char	key;
	int		retour;

	key = 0;
	if (key_choice == 53 || key_choice == 65307)
		return (ft_close(g), 0);
	if (key_choice == 13 || key_choice == 119)
		key = 'w';
	else if (key_choice == 0 || key_choice == 97)
		key = 'a';
	else if (key_choice == 1 || key_choice == 115)
		key = 's';
	else if (key_choice == 2 || key_choice == 100)
		key = 'd';
	if (key == 0)
		return (0);
	retour = ft_key_choice(g, &key);
	if (retour == 2)
		return (ft_close_and_exit(g), 0);
	if (retour == 0)
		ft_print_map(g);
	return (0);
}

// get the string Move : nb_of_moove and then 
// to print it on the window
static char	*ft_moove_str(t_game *g)
{
	char	*move_str;
	char	*nb_of_move;

	nb_of_move = ft_itoa(g->moves);
	move_str = ft_strjoin("Moove : ", nb_of_move);
	if (!move_str)
		return (NULL);
	free(nb_of_move);
	return (move_str);
}

// condition to print the right image in the map depending
// on the keypress move
static void	ft_print_map_bis(t_game *g, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->win, g->floor_image,
		x * g->box, y * g->box);
	if (g->map[y][x] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->wall_image,
			x * g->box, y * g->box);
	else if (g->map[y][x] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->collectible_image,
			x * g->box, y * g->box);
	else if (g->map[y][x] == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->exit_image,
			x * g->box, y * g->box);
	if (x == g->player_x && y == g->player_y)
		mlx_put_image_to_window(g->mlx, g->win, g->player_image,
			x * g->box, y * g->box);
}

// print the map at every keypress
void	ft_print_map(t_game *g)
{
	int		x;
	int		y;
	char	*move_str;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			ft_print_map_bis(g, x, y);
			x++;
		}
		y++;
	}
	move_str = ft_moove_str(g);
	mlx_string_put(g->mlx, g->win, 10, 20, 0xFF007F, move_str);
	mlx_string_put(g->mlx, g->win, 11, 20, 0xFF007F, move_str);
	mlx_string_put(g->mlx, g->win, 10, 21, 0xFF007F, move_str);
	write(1, move_str, ft_strlen(move_str));
	free(move_str);
	write(1, "\n", 1);
}
