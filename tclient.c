/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tclient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusoares <rusoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:24:46 by rusoares          #+#    #+#             */
/*   Updated: 2024/06/19 22:04:29 by rusoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
		write(1 , "MESSAGE RECEIVED BY THE SERVER\n", 31);
}

int	main(int argc, char* argv[])
{
	int	pid;

	pid = atoi(argv[1]);
	signal(SIGUSR1, signal_handler);
	printf("PID: %d\n", pid);
	kill (pid, SIGUSR1);
	sleep(2);
	return (0);
}