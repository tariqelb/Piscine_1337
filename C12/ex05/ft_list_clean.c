/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 19:01:15 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/26 19:16:43 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

#include <stdio.h>

void	ft_list_push_front(t_list **begin_list, void *data);
void	free_fct(void *data)
{
	free(data);
}

void	ft_list_clear(t_list *begin_list, void	(*free_fct)(void *))
{
	t_list	*curr;

	curr = begin_list;
	while (begin_list)
	{
		begin_list = begin_list->next;
		free_fct(curr->data);
	}
	printf("%s\n", (char *) begin_list->data);
}


int	main()
{
	t_list *begin_list;
	typedef void (*fun)(void *);
	fun  f;

	f = free_fct;
	begin_list = (void *) 0;
	ft_list_push_front(&begin_list, "first");
	ft_list_push_front(&begin_list, "second");
	ft_list_push_front(&begin_list, "third");
	ft_list_push_front(&begin_list, "forth");
	ft_list_push_front(&begin_list, "fifth");
	ft_list_clear(begin_list, f);
	while (begin_list)
	{
		printf("%s\n", (char *) begin_list->data);
		begin_list = begin_list->next;
	}
	return (0);
}
