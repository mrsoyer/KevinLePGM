/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 16:05:58 by nhuber            #+#    #+#             */
/*   Updated: 2015/11/03 08:01:12 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putchar(char c);

int		ft_is_empty(char c)
{
	if ((c == ' ') || (c == '\n') || (c == '\t') || (c == '\0'))
		return (0);
	else
		return (1);
}

int		ft_strlen(char *str)
{
	int i;
	int str_len;

	i = 0;
	str_len = 0;
	while (str[i])
	{
		if (!(ft_is_empty(str[i + 1])) && ft_is_empty(str[i]))
		{
			str_len++;
		}
		i++;
	}
	return (str_len);
}

void	ft_size_tab(char *str, char **tab)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (ft_is_empty(str[i]) && !(ft_is_empty(str[i + 1])))
		{
			tab[k] = (char *)malloc(sizeof(char) * j + 1);
			j = -1;
			k++;
		}
		i++;
		j++;
	}
}

void	ft_filltab(char **tab, char *str, int i, int j)
{
	int k;

	k = 0;
	while (str[i])
	{
		if (k < ft_strlen(str) && ft_is_empty(str[i]))
		{
			while (ft_is_empty(str[i]))
			{
				tab[k][j] = str[i];
				i++;
				j++;
			}
			tab[k][j] = '\0';
			k++;
			j = 0;
		}
		else if (k >= ft_strlen(str))
			tab[k] = 0;
		i++;
	}
}

char	**ft_split_whitespaces(char *str)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(tab = (char **)malloc(sizeof(char*) * (ft_strlen(str) + 1))))
		return (NULL);
	ft_size_tab(str, tab);
	ft_filltab(tab, str, i, j);
	return (tab);
}
