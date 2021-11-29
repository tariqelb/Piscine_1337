/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 17:11:53 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/26 18:59:27 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data);
t_list	*ft_create_elem(void *data);

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *list;
	t_list *curr;

	curr = *begin_list;
	list = ft_create_elem(data);
	if (*begin_list == (void *) 0)
		*begin_list = list;
	else
	{
		while (curr->next != (void *) 0)
			curr = curr->next;
		curr->next = list;
	}
}


#include <stdio.h>

int	main()
{
	t_list *begin_list;

	begin_list = (void *) 0;
	ft_list_push_front(&begin_list, "first");
	ft_list_push_front(&begin_list, "second");
	ft_list_push_front(&begin_list, "third");
	ft_list_push_front(&begin_list, "forth");
	ft_list_push_front(&begin_list, "fifth");
	ft_list_push_back(&begin_list, "tenth");
	while (begin_list)
	{
		printf("%s\n", (char *) begin_list->data);
		begin_list = begin_list->next;
	}
	return (0);
}
