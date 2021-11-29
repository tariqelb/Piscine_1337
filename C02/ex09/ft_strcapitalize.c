/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 15:52:29 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/10 18:20:48 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_special_char(char c)
{
	if (c >= 0 && c <= 47)
		return (1);
	else if (c >= 58 && c <= 64)
		return (1);
	else if (c >= 91 && c <= 96)
		return (1);
	else if (c >= 123 && c <= 127)
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && (str[i] >= 97 && str[i] <= 122))
		{
			str[i] -= 32;
		}
		else if (str[i] >= 97 && str[i] <= 122)
		{
			if (ft_special_char(str[i - 1]))
				str[i] -= 32;
		}
		else if ((str[i] >= 65 && str[i] <= 90) && i != 0)
		{
			if (ft_special_char(str[i - 1]) == 0)
				str[i] += 32;
		}
		i++;
	}
	return (str);
}
