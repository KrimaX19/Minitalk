/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tclient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusoares <rusoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:24:46 by rusoares          #+#    #+#             */
/*   Updated: 2024/06/25 22:07:32 by rusoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	message(unsigned int pid_server, unsigned char msg)
{
	int	nbits;

	nbits = 8;
	while (msg)
	{
		while (--nbits >= 0)
		{
			if (msg &  (1 << 1))
				kill(pid_server, SIGUSR1);
			else
				kill(pid_server, SIGUSR2);
			usleep (300);
		}
	}
}

void	signal_handler(int sig)
{
	char ok[] = {0xE2, 0x9C, 0x93};
	
	if (sig == SIGUSR1)
	{
		write(1, ok, 3);
		write(1 , "  Message Received by the server\n", 33);
	}
}

int	main(int argc, char* argv[])
{
	int	pidserver;
	// int	pid;
	int	i = 0;
	// int	msg;
	// char ok[] = {0xE2, 0x9C, 0x93};
	const char *str;
	
	// pid = getpid();
	pidserver = atoi(argv[1]);
	str = argv[2];
	// msg = 0;
	// printf("PID: %d\n", pid);
	// sleep(10);
	while (str[i])
	{
		message(pidserver, str[i++]);
	}
	message(pidserver, '\0');
	// if (msg == 1)
	// {
	// 	write(1, ok, 3);
	// 	write(1, "  Message Sent\n", 15);
	// }
	// else
	// 	write (1, "Failed to send\n", 15);
	// signal(SIGUSR1, signal_handler);
	// sleep(10);
	return (0);
}