/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:15:34 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/24 17:44:06 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DO_OP_H
# define FT_DO_OP_H

# include <unistd.h>

typedef void	(*t_funptr[5])(int, int);

void	ft_putnbr(int nb);
int		ft_atoi(char *str);
int		ft_oper(char *op);
void	ft_add(int nbr1, int nbr2);
void	ft_sub(int nbr1, int nbr2);
void	ft_div(int nbr1, int nbr2);
void	ft_mult(int nbr1, int nbr2);
void	ft_mod(int nbr1, int nbr2);

#endif
