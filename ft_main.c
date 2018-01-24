/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:41:39 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/04 16:41:51 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_opt opt;

	ft_ls_get_opt(&opt, argc, argv);
	ft_ls_firstcheck(&opt);
	ft_ls_freeopt(&opt);
	return (0);
}
