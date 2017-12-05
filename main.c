/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 14:32:19 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 09:59:38 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft/libft.h"
#include "get_next_line.h"


int main(int argc, const char *argv[])
{
	int		fd;
	char	*buffer;
	int i = -1;

	if (argc)
	{
		if(!(fd = open(argv[1],O_RDONLY)))
		{
			ft_putstr("error\n");
			return (0);
		}
		else
		{
			while (++i < 3)
			{
				get_next_line(fd,&buffer);
				ft_putstr(buffer);
			}
		}
		return 0;
	}
}	
