/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 17:17:32 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/23 19:01:57 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <string.h>
# include <libgen.h>
# include <sys/errno.h>
# define BUFF 20000

int		ft_strlen(char *str);
int		ft_put_error(char *str, char *av, int flag);
void	ft_close(int fd, char *av, int error, int dsp);
void	ft_display_header(int ac, char **av, int index);
int		ft_strlen_file(char *av);
int		ft_get_nbr(char *av);
int		ft_display_bytes(int fd, int limit, int bytes);
int		ft_display(int fd, char *av, int bytes);
void	ft_manage_files(int index, int ac, char **av, int bytes);

#endif
