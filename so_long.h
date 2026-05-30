/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-12 12:39:43 by lyaberge          #+#    #+#             */
/*   Updated: 2026-01-12 12:39:43 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "libft.h"
# include "mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

// struct for the component
typedef struct s_comp
{
	int	found_e;
	int	found_p;
	int	found_c;
}	t_comp;

// struct for the gameplay
typedef struct s_game
{
	int		fd;
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		moves;
	int		collectible_collected;
	int		collectible_total;
	void	*mlx;
	void	*win;
	void	*floor_image;
	void	*player_image;
	void	*wall_image;
	void	*collectible_image;
	void	*exit_image;
	int		box;
}	t_game;

// struct for the next possible moove of the player 
// in gameplay
typedef struct s_npp
{
	int		next_player_pos_x;
	int		next_player_pos_y;
}	t_npp;

// struct for the size of the map
typedef struct s_size
{
	int	height;
	int	width;
}	t_size;

// to check the map component
typedef struct s_found
{
	int	collectible;
	int	exit;
}	t_found;

// get_next_line
char	*ft_strjoin_and_free(char *stash, char *buf);
int		ft_index_of_n(char *s);
char	*get_next_line(int fd);

// check map wall utils
void	ft_free(char **tab);
int		ft_count_line(char *av);
int		ft_count_str_in_dtab(char **map);
int		ft_check_is_rectangle(char **map);

// check map wall
int		ft_check_wall_extern(char **map);

// check map component
int		ft_check_map_component(char **map);
int		ft_decide(char *av);

// gameplay
int		ft_count_collectible(char **map);
int		ft_possible_move(t_game *g, int possible_x, int possible_y);

// check playability
int		ft_check_playable(char **map);
int		ft_final_check(char **map);

// check playability utils
int		ft_found_player_pos(char **map, int	*x, int	*y);
char	**ft_copy_map(char **map);

// create map_tab
int		ft_open_and_create_map_tab(t_game *g, char **argv);

// main util
void	ft_print_map(t_game *g);
int		ft_key_in_game(int key_choice, t_game *g);
void	ft_close(t_game *g);
int		ft_close_and_exit(t_game *g);

#endif
