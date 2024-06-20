/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tserver.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusoares <rusoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:27:14 by rusoares          #+#    #+#             */
/*   Updated: 2024/06/20 18:51:43 by rusoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int pid_cl = 0;

void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		kill(pid_cl, SIGUSR1);
		write(1 , "SIGNAL RECEIVED\n", 16);
	}
}
int	main(int ac, char **av)
{
	int	pid;
	// int	pid_client;
	int* client_pid;

	pid = getpid();
	printf("PID: %d\n", pid_cl);
	printf("PID: %d\n", pid);
	printf("PID: %d\n", pid_cl);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	printf("Enter Client PID:");
	scanf("%d", client_pid);
	pid_cl = *client_pid;
	printf("PID: %d\n", pid_cl);
	while (1)
	{
	}
	return(0);
}