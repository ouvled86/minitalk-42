/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:33:04 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/02/12 15:58:29 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum, siginfo_t *info, void *context)
{
	static int		bits;
	static int		c;
	static pid_t	pid;

	(void)context;
	if (!pid)
		pid = info->si_pid;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		bits = 0;
		c = 0;
	}
	if (signum == SIGUSR1)
		c = c << 1 | 1;
	else
		c = c << 1 | 0;
	bits++;
	if (bits == 8)
	{
		ft_printf("%c", c);
		bits = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	pid = getpid();
	ft_printf("This process' PID is: %d\n", pid);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("Error: Sigaction failed!\n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("Error: Sigaction failed!\n");
	while (1)
		pause();
	return (0);
}
