/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:16:46 by rverly            #+#    #+#             */
/*   Updated: 2022/10/14 21:16:20 by rverly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<signal.h>
#include "libft/libft.h"

static void	send_signal(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 7;
		c = *str;
		while (i > -1)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(450);
			i--;
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	char	*str;
	int		pid;

	if (argc != 3 || !ft_strlen(argv[2]))
		return (1);
	pid = ft_atoi(argv[1]);
	str = ft_strdup(argv[2]);
	send_signal(pid, str);
	free(str);
	return (0);
}
