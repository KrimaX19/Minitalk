/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Teste_Cliente.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusoares <rusoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:06:08 by rusoares          #+#    #+#             */
/*   Updated: 2024/06/27 22:21:20 by rusoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
void	send_message(int pid, const char *message)
{
	
}

void	signal_handler(int signal)
{
	write(1, "Message Received by the server\n", 31);
	exit(0);
}

int	main(int ac, char **av)
{
	int					server_pid;
	const char			*message;
	struct sigaction	sa;

	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	server_pid = av[1];
	message = av[2];
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	send_message(server_pid, message);
	if (ac != 3)
	{
		write(1, "Use in this format: <server-pid> <message>\n", 44);
		return (1);
	}
	while (1)
	{
		pause();
	}
	return (0);
}
