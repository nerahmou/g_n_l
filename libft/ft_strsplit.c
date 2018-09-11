/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 13:50:51 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 20:18:35 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_compteur(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

static void	ft_trans(char const *str, char *tab, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
}

static int	ft_calcul(char const *str, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
			j++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (j);
}

static char	**ft_add(char const *s, char c, char **tab)
{
	int	j;
	int	i;
	int	a;
	int	len;

	a = ft_calcul(s, c);
	i = 0;
	j = -1;
	while (++j < a)
	{
		while (s[i] == c)
			i++;
		len = ft_compteur(s + i, c);
		tab[j] = (char*)malloc(sizeof(*tab) * (len + 1));
		if (!tab[j])
			return (0);
		ft_trans(s + i, tab[j], len);
		i = i + len;
	}
	tab[j] = 0;
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	int		a;
	char	**tab;

	if (s)
	{
		a = ft_calcul(s, c);
		tab = (char**)malloc(sizeof(tab) * (a + 1));
		if (!tab)
			return (tab);
		return (ft_add(s, c, tab));
	}
	return (NULL);
}
