/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:28:54 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/26 14:44:15 by tel-bouh         ###   ########.fr       */
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

int	ft_include(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_power(int nb, int power)
{
	int	result;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (nb == 0)
		return (0);
	result = 1;
	while (power--)
		result = result * nb;
	return (result);
}

int	ft_sign(char *nbr)
{
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	while (nbr[i] == '\t' || nbr[i] == '\f' || nbr[i] == '\v'
		|| nbr[i] == '\r' || nbr[i] == '\n' || nbr[i] == ' ')
		i++;
	while (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			sign = sign * -1;
		i++;
	}
	return (sign);
}

int	ft_to_base_ten(char *nbr, char *base, int index_i)
{
	int	index_j;
	int	base_len;
	int	dec_nbr;
	int	nbr_len;

	base_len = 0;
	nbr_len = index_i;
	dec_nbr = 0;
	while (base[base_len] != '\0')
		base_len++;
	while (nbr[nbr_len] != '\0')
		nbr_len++;
	while (index_i < nbr_len)
	{
		index_j = 0;
		while (base[index_j] != nbr[index_i])
			index_j++;
		if (ft_include(nbr[index_i], base) == 0)
			return (-1);
		dec_nbr += (index_j * ft_power(base_len, (nbr_len - 1 - index_i)));
		index_i++;
	}
	return (dec_nbr);
}
