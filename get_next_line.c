/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 18:09:11 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/13 17:41:43 by nerahmou    ###    #+. /#+    ###.fr     */
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

static int	ft_sub_tmp(char **line, char **tmp, int fd)
{
	char	*str;
	size_t	bck_n;

	if (!ft_strlen(tmp[fd]))
		return (0);
	if (ft_strchr(tmp[fd], '\n'))
	{
		bck_n = ft_char_pos(tmp[fd], '\n');
		str = ft_strsub(tmp[fd], 0, bck_n);
		if (!(ft_realloc(line, str)))
			return (-1);
		ft_strdel(&str);
		if (!(str = ft_strsub(tmp[fd], bck_n + 1,
						ft_strlen(tmp[fd]) - (bck_n + 1))))
			return (-1);
		ft_strdel(&tmp[fd]);
		tmp[fd] = str;
		return (1);
	}
	if (!(ft_realloc(line, tmp[fd])))
		return (-1);
	ft_strdel(&tmp[fd]);
	return (0);
}

static	int	ft_fill_line(char **line, char **tmp, int ret, int fd)
{
	size_t	back_n;
	char	buff[BUFF_SIZE + 1];
	char	*temp;

	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = 0;
		if (ft_strchr(buff, '\n'))
		{
			back_n = ft_char_pos(buff, '\n');
			if (!(ft_realloc(line, temp = ft_strsub(buff, 0, back_n))) ||
				!(tmp[fd] = ft_strsub(buff, back_n + 1, (ret - back_n) + 1)))
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
	static	char	*tmp[4600] = {0};
	int				ret;

	if (BUFF_SIZE < 1 || fd < 0 || fd >= 4600 || !line)
		return (-1);
	ret = 0;
	*line = NULL;
	if (tmp[fd] && (ret = ft_sub_tmp(line, tmp, fd)))
		return (1);
	if (ft_fill_line(line, tmp, ret, fd) == -1 || ret == -1)
		return (-1);
	if (*line)
		return (1);
	return (0);
}
