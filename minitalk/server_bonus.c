/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:16:54 by rverly            #+#    #+#             */
/*   Updated: 2022/10/14 20:36:04 by rverly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<signal.h>
#include "libft/libft.h"

void	action(int sig)
{
	static int	i;
	static char	c;

	c <<= 1;
	c = c | (sig == SIGUSR2);
	if (i == 7)
	{
		write(1, &c, 1);
		i = -1;
		c = 0;
	}
	i++;
}

int	main(void)
{
	int		pid;
	char	*s_pid;

	pid = getpid();
	s_pid = ft_itoa(pid);
	if (!s_pid)
		return (1);
	write(1, &"PID: ", 5);
	ft_putendl_fd(s_pid, 1);
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	while (1)
		pause();
	free(s_pid);
}
