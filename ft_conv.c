/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:26:56 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/04 16:46:32 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		ft_ls_conv_type(const struct stat buf)
{
	if (S_ISREG(buf.st_mode) != 0)
		return ('-');
	if (S_ISDIR(buf.st_mode) != 0)
		return ('d');
	if (S_ISCHR(buf.st_mode) != 0)
		return ('c');
	if (S_ISBLK(buf.st_mode) != 0)
		return ('b');
	if (S_ISFIFO(buf.st_mode) != 0)
		return ('p');
	if (S_ISLNK(buf.st_mode) != 0)
		return ('l');
	if (S_ISSOCK(buf.st_mode) != 0)
		return ('s');
	return (0);
}

char		*ft_ls_conv_perm(const struct stat buf)
{
	static char perms[10] = {0};

	perms[0] = buf.st_mode & S_IRUSR ? 'r' : '-';
	perms[1] = buf.st_mode & S_IWUSR ? 'w' : '-';
	perms[2] = buf.st_mode & S_IXUSR ? 'x' : '-';
	perms[2] = buf.st_mode & S_ISUID ? 's' : perms[2];
	if ((buf.st_mode & S_ISUID) && (buf.st_mode & S_IRWXU) == 0)
		perms[2] = 'S';
	perms[3] = buf.st_mode & S_IRGRP ? 'r' : '-';
	perms[4] = buf.st_mode & S_IWGRP ? 'w' : '-';
	perms[5] = buf.st_mode & S_IXGRP ? 'x' : '-';
	perms[5] = buf.st_mode & S_ISGID ? 's' : perms[5];
	if ((buf.st_mode & S_ISGID) && (buf.st_mode & S_IRWXG) == 0)
		perms[5] = 'S';
	perms[6] = buf.st_mode & S_IROTH ? 'r' : '-';
	perms[7] = buf.st_mode & S_IWOTH ? 'w' : '-';
	perms[8] = buf.st_mode & S_IXOTH ? 'x' : '-';
	perms[8] = buf.st_mode & S_ISVTX ? 't' : perms[8];
	if ((buf.st_mode & S_ISVTX) && (buf.st_mode & S_IRWXO) == 0)
		perms[8] = 'T';
	perms[9] = '\0';
	return (perms);
}

t_mdate		ft_ls_conv_mdate(const char *str)
{
	t_mdate		mdate;
	char		**splited;
	int			i;

	i = 0;
	splited = ft_strsplit(str, ' ');
	ft_strcpy(mdate.day, splited[0]);
	ft_strcpy(mdate.month, splited[1]);
	ft_strcpy(mdate.daynbr, splited[2]);
	ft_strncpy(mdate.hour, splited[3], 5);
	ft_strncpy(mdate.year, splited[4], 5);
	if (mdate.year[4] == '\n')
		mdate.year[4] = '\0';
	while (splited[i] != 0)
	{
		free(splited[i]);
		i++;
	}
	free(splited);
	splited = NULL;
	return (mdate);
}
