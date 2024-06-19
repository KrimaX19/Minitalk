/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusoares <rusoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:02:13 by rusoares          #+#    #+#             */
/*   Updated: 2024/06/17 20:19:01 by rusoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac < 3 || ac > 3)
	{
		printf("Use like this:\n./client <PID> <message>\nWithout <>");
	}
	return (0);
}