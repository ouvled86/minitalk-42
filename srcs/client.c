/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:32:06 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/05/09 11:57:05 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_bit(pid_t pid, unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i--;
	}
}

static void	send_string(pid_t pid, unsigned char *str)
{
	int	i;

	i = 0;
	while (str[i])
		send_bit(pid, str[i++]);
	send_bit(pid, str[i]);
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0)
		{
			ft_printf("\nInvalid PID\n");
			return (1);
		}
		ft_printf("%d\n", pid);
		send_string(pid, (unsigned char *)av[2]);
		return (0);
	}
	ft_printf("\nClient format is: $ ./client [PID][MSG]\n");
	return (1);
}
