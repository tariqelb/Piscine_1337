/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 17:33:20 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/25 18:02:11 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_tail.h>

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

void	ft_close(int fd, char *av, int error, int dsp)
{
	int	cls;

	cls = close(fd);
	if (cls == -1 && error == 0 && dsp == 0)
		cls = ft_put_error(strerror(errno), av, 1);
}

int	ft_put_error(char *str, char *av, int flag)
{
	int	index;

	if (flag == 1)
	{
		write(2, "tail: ", 6);
		write(2, av, ft_strlen(av));
		write(2, ": ", 2);
		index = 0;
		while (str[index] != '\0')
		{
			write(1, &str[index], 1);
			index++;
		}
		write(1, "\n", 1);
	}
	else
	{
		write(2, "tail: option requires an argument -- c\n", 39);
	}
	return (1);
}

void	ft_display_header(int ac, char **av, int index)
{
	int	i;
	int	fd;
	int	flag;

	flag = 0;
	if (ac > 3)
	{
		i = 2;
		while (i < index)
		{
			fd = open(av[i], O_RDONLY);
			if (fd > 2)
				flag = 1;
			close(fd);
			i++;
		}
		if (flag == 1)
			write(1, "\n", 1);
		write(1, "==> ", 4);
		write(1, av[index], ft_strlen(av[index]));
		write(1, " <==\n", 5);
	}
}

int	ft_strlen_file(char *av)
{
	int		size;
	int		fd;
	int		rd;
	char	tab[BUFF];

	fd = open(av, O_RDONLY);
	rd = read(fd, tab, BUFF);
	size = rd;
	while (rd > 0)
	{
		rd = read(fd, tab, BUFF);
		size += rd;
	}
	return (size);
}
