/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tclient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusoares <rusoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:24:46 by rusoares          #+#    #+#             */
/*   Updated: 2024/06/19 21:12:25 by rusoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char* argv[])
{
	int	pid;

	pid = atoi(argv[1]);
	printf("PID: %d\n", pid);
	kill (pid, SIGUSR1);
	return (0);
}