/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 19:31:27 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/26 16:04:45 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*list;

	list = (void *) 0;
	list = (t_list *) malloc(sizeof(t_list));
	if (list != (void *) 0)
	{
		list->data = data;
		list->next = (void *) 0;
	}
	return (list);
}

#include <stdio.h>

int	main()
{
	t_list *list;

	list = (void *) 0;
	list = ft_create_elem("Inchalah");
	printf("%s\t%s\n", (char *) list->data, (char *) list->next);
	return (0);
}
