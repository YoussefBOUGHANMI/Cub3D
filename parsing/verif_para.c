/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_para.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <yboughan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:37:21 by pschemit          #+#    #+#             */
/*   Updated: 2023/03/19 18:55:30 by yboughan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	ft_verif_ex_0(t_cub3d *data, char **line)
{
	if (((ft_strcmp(line[0], "no") == 0) && (data->no != NULL))
		|| ((ft_strcmp(line[0], "so") == 0) && (data->so != NULL))
		|| ((ft_strcmp(line[0], "we") == 0) && (data->we != NULL))
		|| ((ft_strcmp(line[0], "ea") == 0) && (data->ea != NULL))
		|| ((ft_strcmp(line[0], "C") == 0) && (data->c != NULL))
		|| ((ft_strcmp(line[0], "F") == 0) && (data->f != NULL)))
	{
		printf("double %s\n", line[0]);
		return (-1);
	}
	return (1);
}

int	ft_verif_ex(t_cub3d *data, char **line)
{
	if (ft_strcmp(line[0], "NO") == 0)
		data->no = ft_path(line[1]);
	else if (ft_strcmp(line[0], "SO") == 0)
		data->so = ft_path(line[1]);
	else if (ft_strcmp(line[0], "WE") == 0)
		data->we = ft_path(line[1]);
	else if (ft_strcmp(line[0], "EA") == 0)
		data->ea = ft_path(line[1]);
	else if (ft_strcmp(line[0], "F") == 0)
		data->f = ft_path_fc(line[1]);
	else if (ft_strcmp(line[0], "C") == 0)
		data->c = ft_path_fc(line[1]);
	else
		return (-1);
	return (1);
}

int	ft_verif_para_bis(t_cub3d *data, char	**line)
{
	if ((ft_verif_ex_0(data, line) == -1)
		|| (ft_verif_ex(data, line) == -1))
	{
		free_double_tab(line);
		return (1);
	}
	return (0);
}

int	ft_verif_para(t_cub3d *data)
{
	int		i;
	int		t;
	char	**line;

	t = 0;
	i = 0;
	while (data->p_cub[i])
	{
		line = ft_split(data->p_cub[i]);
		if (line[0])
		{
			if (ft_verif_para_bis(data, line) == 1)
				return (-1);
			else
				t++;
		}
		free_double_tab(line);
		i++;
		if (t == 6)
			break ;
	}
	if (t != 6 || data->c == NULL || data->f == NULL)
		return (-1);
	return (i);
}

int	ft_find_cub(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.' && str[i + 1] == 'c' && str[i + 2] == 'u'
			&& str[i + 3] == 'b' && str[i + 4] == '\0')
			return (1);
		i++;
	}
	return (0);
}
