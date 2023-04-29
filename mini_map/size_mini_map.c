/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <yboughan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:46:07 by yboughan          #+#    #+#             */
/*   Updated: 2023/03/19 13:47:17 by yboughan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	get_width(char **map)
{
	int	i;
	int	len;
	int	max_len;

	i = 0;
	max_len = 0;
	while (map[i])
	{
		len = 0;
		while (map[i][len])
			len++;
		if (max_len < len)
			max_len = len;
		i++;
	}
	return (max_len);
}

int	get_length(char **map)
{
	int	len;

	len = 0;
	while (map[len])
		len++;
	return (len);
}
