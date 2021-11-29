/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:54:18 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/12 18:19:17 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = -1;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[++i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
	}
	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	ft_power(int nbr, int power)
{
	int	result;

	result = nbr;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (--power > 0)
	{
		result = result * nbr;
	}
	return (result);
}

int	ft_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\f' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\n' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	return (i * sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	len;
	int	nbr;
	int	i;
	int	j;
	int	sign;

	sign = 1;
	len = ft_check_base(base);
	i = ft_atoi(str);
	if (i < 0)
	{
		sign = -1;
		i *= -1;
	}
	nbr = i;
	while (ft_in_base(str[i], base) >= 0)
		i++;
	j = (i - nbr) - 1;
	i = nbr;
	nbr = 0;
	while (ft_in_base(str[i], base) >= 0 && len)
	{
		nbr = nbr + ft_in_base(str[i++], base) * ft_power(len, j--);
	}
	return (nbr * sign);
}
