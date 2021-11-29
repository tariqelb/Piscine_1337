/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 18:16:42 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/24 18:43:56 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_str(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
	int	index;

	index = 0;
	while (tab[index + 1] != 0)
	{
		if (cmp(tab[index], tab[index + 1]) > 0)
		{
			ft_swap_str(&tab[index], &tab[index + 1]);
			index = -1;
		}
		index++;
	}
}
