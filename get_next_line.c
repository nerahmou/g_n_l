/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 18:09:11 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/10 17:09:10 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

char		*ft_realloc(char **ptr, char *content)
{
	char *tmp;

	if (!*ptr)
	{
		if (!(*ptr = ft_strsub(content, 0, ft_strlen(content))))
			return (NULL);
	}
	else
	{
		if (!(tmp = ft_strjoin(*ptr, content)))
			return (NULL);
		ft_strdel(ptr);
		*ptr = tmp;
	}
	return (*ptr);
}

static int	ft_sub_tmp(char **line, char *tmp, int fd)
{
	char	*str;
	int		bck_n;

	if (!ft_strlen(tmp))
		return (0);
	if (ft_strchr(tmp, '\n'))
	{
		bck_n = ft_char_pos(tmp, '\n');
		str = ft_strsub(tmp, 0, bck_n);
		if (!(ft_realloc(line, str)))
			return (-1);
		ft_strdel(&str);
		if (!(str = ft_strsub(tmp, bck_n + 1,
						ft_strlen(tmp) - (bck_n + 1))))
			return (-1);
		ft_strdel(&tmp);
		tmp = str;
		return (1);
	}
	if (!(ft_realloc(line, tmp)))
		return (-1);
	ft_strdel(&tmp);
	return (0);
}

static	int	ft_fill_line(char **line, char *tmp, int ret, int fd)
{
	int		back_n;
	char	buff[BUFF_SIZE + 1];
	char	*temp;
	char	*apres_back_n;

	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = 0;
		if ((apres_back_n = ft_strchr(buff, '\n')))
		{
			if (!(ft_realloc(line, temp = ft_strsub(buff, 0, back_n))))
				return (-1);
			if (!(tmp = ft_strdup(apres_back_n + 1)))
				return (-1);
			ft_strdel(&temp);
			break ;
		}
		else if (!(temp = ft_strdup(buff)) || !(ft_realloc(line, temp)))
			return (-1);
		ft_strdel(&temp);
	}
	return (ret);
}

int			get_next_line(int fd, char **line)
{
	static char	*tmp;
	int				ret;

	if (BUFF_SIZE < 1 || fd < 0 || !line)
		return (-1);
	//*line = NULL;
	if (tmp && (ret = ft_sub_tmp(line, tmp, fd)))
		return (1);
	if (ft_fill_line(line, tmp, ret, fd) == -1 || ret == -1)
		return (-1);
	if (*line)
		return (1);
	return (0);
}
