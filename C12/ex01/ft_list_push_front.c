/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:07:56 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/26 16:19:33 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data);

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *list;

	list = ft_create_elem(data);
	if (*begin_list == (void *) 0)
		*begin_list = list;
	else
	{
		list->next = *begin_list;
		*begin_list = list;
	}
}
#include <stdio.h>
int	main()
{
	t_list *begin_list;
	ft_list_push_front(&begin_list, "first");
	ft_list_push_front(&begin_list, "second");
	ft_list_push_front(&begin_list, "third");
	ft_list_push_front(&begin_list, "forth");
	while (begin_list->next != (void *) 0)
	{
		printf("%s\n", (char *) begin_list->data);
		begin_list = begin_list->next;
	}
	return (0);
}
