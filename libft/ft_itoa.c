/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 15:48:06 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/28 15:48:26 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		lennum(int num, int *i)
{
	int	ret;

	ret = 0;
	*i = 0;
	if (num < 0)
	{
		num = -num;
		ret++;
	}
	else if (num == 0)
		return (1);
	while (num)
	{
		num /= 10;
		ret++;
	}
	return (ret);
}

char			*ft_itoa(int n)
{
	char	*ret;
	int		i;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = lennum(n, &i);
	if (!(ret = ft_strnew((size_t)len)))
		return (NULL);
	if (n < 0)
	{
		n = -n;
		ret[0] = '-';
	}
	while (n)
	{
		ret[len - i++ - 1] = n % 10 + '0';
		n /= 10;
	}
	if (i == 0)
	{
		ret[0] = '0';
		ret[1] = '\0';
	}
	return (ret);
}
