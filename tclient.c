/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tclient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusoares <rusoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:24:46 by rusoares          #+#    #+#             */
/*   Updated: 2024/06/20 18:07:54 by rusoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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
	int	pid;
	char ok[] = {0xE2, 0x9C, 0x93};
	
	pid = getpid();
	pidserver = atoi(argv[1]);
	printf("PID: %d\n", pid);
	sleep(10);
	signal(SIGUSR1, signal_handler);
	write(1, ok, 3);
	write(1, "  Message Sent\n", 15);
	kill (pidserver, SIGUSR1);
	sleep(10);
	return (0);
}