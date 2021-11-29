/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:39:55 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/26 16:46:23 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data);
t_list	*ft_list_last(t_list *begin_list)
{
	while (begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
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
	printf("%s\n", (char *) (ft_list_last(begin_list))->data);
	return (0);
}
