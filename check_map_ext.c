/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_ext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-21 16:43:57 by lyaberge          #+#    #+#             */
/*   Updated: 2026-01-21 16:43:57 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// to check if the input is in a folder or not
static int	ft_has_slash(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '/')
			return (0);
		i++;
	}
	return (1);
}

// to check if the extension of .ber is valid in the map input
static int	ft_check_alphaber(char *av1)
{
	int	i;
	int	len_av1;

	i = 0;
	while (av1[i] != '/')
		i++;
	len_av1 = ft_strlen(av1);
	if (len_av1 <= 4)
		return (1);
	i = len_av1 - 1;
	if (av1[i] != 'r')
		return (1);
	i--;
	if (av1[i] != 'e')
		return (1);
	i--;
	if (av1[i] != 'b')
		return (1);
	i--;
	if (av1[i] != '.')
		return (1);
	return (0);
}

// to check if the extension of .ber is valid in the map input
// if it's in a folder
static int	ft_check_extension_map(char *av1)
{
	int		i;

	i = 0;
	while (av1[i] != '/')
		i++;
	if (av1[i + 1] == '.')
		return (1);
	if (ft_check_alphaber(av1) == 1)
		return (1);
	return (0);
}

// to check if the extension of .ber is valid in the map input
// if it.s not in a folder
static int	ft_check_extension_map2(char *av1)
{
	int	i;
	int	len_av1;

	i = 0;
	if (av1[i] == '.')
		return (1);
	len_av1 = ft_strlen(av1);
	if (len_av1 <= 4)
		return (1);
	i = len_av1 - 1;
	if (av1[i] != 'r')
		return (1);
	i--;
	if (av1[i] != 'e')
		return (1);
	i--;
	if (av1[i] != 'b')
		return (1);
	i--;
	if (av1[i] != '.')
		return (1);
	return (0);
}

// do different function depending on if the file input
// is in a folder or not
int	ft_decide(char *av)
{
	if (ft_has_slash(av) == 0)
	{
		if (ft_check_extension_map(av) == 1)
			return (1);
	}
	else
	{
		if (ft_check_extension_map2(av) == 1)
			return (1);
	}
	return (0);
}
