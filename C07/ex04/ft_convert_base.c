/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 18:27:00 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/26 14:43:20 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_include(char c, char *base);
int		ft_strlen(char *str);
int		ft_power(int nb, int power);
int		ft_sign(char *nbr);
int		ft_to_base_ten(char *nbr, char *base, int index_i);
char	*ft_alocate_memory(char *base_to, char *str, int nb, char *nbr);
char	*ft_base_to(int nb, char *base_to, int sign, char *str);
int		ft_get_nbr(char *nbr, char *base_f);
int		ft_check_base(char *base);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

char	*ft_alocate_memory(char *base_to, char *str, int nb, char *nbr)
{
	int	base_len;
	int	size;

	base_len = 0;
	size = 0;
	if (nbr[0] == '-')
		size = 1;
	while (base_to[base_len] != '\0')
		base_len++;
	while (nb > 0)
	{
		nb = nb / base_len;
		size++;
	}
	str = (char *) malloc(sizeof(char) * size + 1);
	return (str);
}

char	*ft_base_to(int nb, char *base_to, int sign, char *str)
{
	int		index_i;
	int		base_len;
	char	temp;

	base_len = 0;
	while (base_to[base_len] != '\0')
		base_len++;
	index_i = 0;
	while (nb > 0)
	{
		str[index_i++] = base_to[nb % base_len];
		nb = nb / base_len;
	}
	if (sign == -1)
		str[index_i++] = '-';
	str[index_i] = '\0';
	base_len = 0;
	while (base_len < index_i / 2)
	{
		temp = str[base_len];
		str[base_len] = str[index_i - 1 - base_len];
		str[index_i - 1 - base_len++] = temp;
	}
	return (str);
}	

int	ft_get_nbr(char *nbr, char *base_f)
{
	int	i;

	i = 0;
	while (nbr[i] == '\t' || nbr[i] == '\r' || nbr[i] == '\f'
		|| nbr[i] == '\n' || nbr[i] == '\v' || nbr[i] == ' ')
		i++;
	while (nbr[i] == '-' || nbr[i] == '+')
		i++;
	return (ft_to_base_ten(nbr, base_f, i));
}

int	ft_check_base(char *base)
{
	int		len;
	int		i_i;
	int		i_j;

	len = ft_strlen(base);
	i_i = 0;
	while (i_i < len - 1)
	{
		i_j = i_i + 1;
		while (i_j < len)
		{
			if (base[i_i] == base[i_j])
				return (0);
			i_j++;
		}
		i_i++;
	}
	i_i = 0;
	while (base[i_i] != '\0')
	{
		if (base[i_i] == '-' || base[i_i] == '+')
			return (0);
		i_i++;
	}
	return (1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	char	*str;
	int		sign;

	str = (void *) 0;
	if (ft_check_base(base_from) && ft_check_base(base_to))
	{
		nb = ft_get_nbr(nbr, base_from);
		if (nb == -1)
			return ((void *) 0);
		str = ft_alocate_memory(base_from, str, nb, nbr);
		if (str == (void *) 0)
			return ((void *) 0);
		sign = ft_sign(nbr);
		str = ft_base_to(nb, base_to, sign, str);
	}
	return (str);
}
