/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 18:32:49 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/22 17:07:06 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

void	ft_show_tab(struct s_stock_str *par);

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

char	*ft_get_str(char *str, char *av)
{
	int	index;

	index = 0;
	while (av[index] != '\0')
	{
		str[index] = av[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		len;

	len = ft_strlen(src);
	dest = (void *) 0;
	dest = (char *) malloc(sizeof(char) * (len + 1));
	if (dest == (void *) 0)
		return ((void *) 0);
	len = 0;
	while (src[len] != '\0')
	{
		dest[len] = src[len];
		len++;
	}
	dest[len] = '\0';
	return (dest);
}

struct	s_stock_str	*ft_strs_to_tab(int	ac, char **av)
{
	int			i;
	t_stock_str	*stock;

	stock = (void *) 0;
	stock = (t_stock_str *) malloc(sizeof(t_stock_str) * (ac + 1));
	if (stock == (void *) 0)
		return (stock);
	i = 0;
	while (i < ac)
	{	
		stock[i].size = ft_strlen(av[i]);
		stock[i].str = (void *) 0;
		stock[i].str = (char *) malloc(sizeof(char) * (stock[i].size + 1));
		if (stock[i].str != ((void *) 0))
			stock[i].str = ft_get_str(stock[i].str, av[i]);
		stock[i].copy = ft_strdup(stock[i].str);
		i++;
	}
	stock[i].str = 0;
	return (stock);
}

int	main(int ac, char **av)
{
	t_stock_str *stock;

	stock = ft_strs_to_tab(ac, av);
	ft_show_tab(stock);
	return (0);
}
