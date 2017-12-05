/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 18:09:11 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 09:21:29 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

size_t	is_back_n(char *buff)
{
	size_t length;

	length = 0;
	while (buff[length] && buff[length] != '\n')
		length++;
	return (length);
}

size_t		list_elem_length(t_list *list)
{
	size_t length;

	length = 0;
	while (list)
	{
		length += ft_strlen(list->content);
		list = list->next;
	}
	return (length);
}

char		*fill_str_list(t_list *list, size_t length)
{
	char *str;

	if (!(str = ft_strnew(length)))
		return (NULL);
	while (list)
	{
		ft_strcat(str, list->content);
		list = list->next;
	}
	return (str);
}

int		get_next_line(int fd, char **line)
{
	static char	*tmp = NULL;
	char	buff[BUFF_SIZE + 1];
	t_list	*malist;
	size_t back_n;

	malist = NULL;
	if (tmp)
	{
		ft_lstpushback_str(&malist,tmp);
		ft_strdel(&tmp);
	}
	while(read(fd, buff, BUFF_SIZE))
	{
		back_n = is_back_n(buff);
		if ((back_n < BUFF_SIZE))
		{
				tmp = ft_strsub(buff, back_n + 1 , BUFF_SIZE);
				buff[back_n] = 0;
				ft_lstpushback_str(&malist,buff);
			break;
		}
		else
		{	
			buff[BUFF_SIZE] = 0;
			ft_lstpushback_str(&malist,buff);
		}
	}
	ft_lstdisplay_str(malist);
	*line = fill_str_list(malist, list_elem_length(malist));
	return (1);
}
