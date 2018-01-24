/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:18:27 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/05 10:18:22 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_usage(int i, int j, char **arv)
{
	ft_putstr_fd(FT_LS, 2);
	ft_putstr_fd("illegal option ", 2);
	ft_putstr_fd("-- ", 2);
	ft_putchar_fd(arv[i][j], 2);
	ft_putendl_fd("", 2);
	ft_putendl_fd("usage: ft_ls [-artlR1g] [file ...]", 2);
}

void	ft_ls_perr(char *path)
{
	char *str;

	if ((str = (char *)malloc(sizeof(char) *
	(ft_strlen(FT_LS) + ft_strlen(path) + 5))) == NULL)
	{
		ft_putendl("some malloc failed");
		exit(EXIT_FAILURE);
	}
	ft_bzero(str, ft_strlen(FT_LS) + ft_strlen(path) + 5);
	ft_strcat(str, FT_LS);
	if (ft_strlen(path) == 0)
		ft_strcat(str, "open");
	else
		ft_strcat(str, path);
	perror(str);
	free(str);
	if (ft_strlen(path) == 0)
		exit(EXIT_FAILURE);
}

void	ft_sort_optdir(char **dir, int dirnbr)
{
	int		swap;
	int		i;
	char	*temp;

	swap = TRUE;
	while (swap == TRUE)
	{
		swap = FALSE;
		i = 0;
		while (i < dirnbr - 1)
		{
			if (ft_strcmp(dir[i], dir[i + 1]) > 0)
			{
				temp = dir[i];
				dir[i] = dir[i + 1];
				dir[i + 1] = temp;
				swap = TRUE;
			}
			i++;
		}
	}
}

int		ft_get_dirnbr(char **dir)
{
	int i;

	i = 0;
	while (dir[i])
	{
		i++;
	}
	return (i);
}

void	ft_delete_in_tab(char **dir, int index)
{
	int		dirnbr;
	char	*temp;

	dirnbr = ft_get_dirnbr(dir);
	temp = dir[index];
	while (index + 1 < dirnbr)
	{
		dir[index] = dir[index + 1];
		index++;
	}
	dir[index] = 0;
	free(temp);
}
