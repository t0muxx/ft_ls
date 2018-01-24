/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 17:04:10 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/04 17:18:23 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_init_maxvalue(t_maxvalue *max)
{
	max->nblink = 0;
	max->owner = 0;
	max->group = 0;
	max->size = 0;
	max->maj = 0;
	max->min = 0;
}

void	ft_lst_manage_itoa(t_dirfile *last, t_maxvalue *max)
{
	char *ptr;

	ptr = ft_itoa(last->nblink);
	if (ft_strlen(ptr) > max->nblink)
		max->nblink = ft_strlen(ptr);
	free(ptr);
	ptr = ft_itoa(last->size);
	if (ft_strlen(ptr) > max->size)
		max->size = ft_strlen(ptr);
	free(ptr);
	ptr = ft_itoa(last->major);
	if (ft_strlen(ptr) > max->maj)
		max->maj = ft_strlen(ptr);
	free(ptr);
	ptr = ft_itoa(last->minor);
	if (ft_strlen(ptr) > max->min)
		max->min = ft_strlen(ptr);
	free(ptr);
}

void	ft_lst_manage_ln(t_dirfile **new, char *catpath)
{
	int				ret;

	ret = 2;
	if ((*new)->type == 'l')
	{
		ret = readlink(catpath, (*new)->lnpath, sizeof((*new)->lnpath) - 1);
		if (ret != -1)
		{
			(*new)->lnpath[ret] = '\0';
		}
		else
		{
			ft_putendl_fd("Erreur readlink", 2);
			exit(EXIT_FAILURE);
		}
	}
}
