/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tserver.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusoares <rusoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:27:14 by rusoares          #+#    #+#             */
/*   Updated: 2024/06/19 22:25:24 by rusoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
		write(1 , "SIGNAL RECEIVED\n", 16);
}
int	main()
{
	int	pid;
	int	pid_client;
	
	pid = getpid();
	printf("PID: %d\n", pid);
	signal(SIGUSR1, signal_handler);
	if (SIGUSR1 == 1)
		pkill('usersignal', SIGUSR1);
	while (1)
	{
		
	}
	return(0);
}