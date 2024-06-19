/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusoares <rusoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:02:22 by rusoares          #+#    #+#             */
/*   Updated: 2024/06/19 19:48:58 by rusoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

/*
write
ft_printf
signal
sigemptyset
sigaddset
sigaction
kill
getpid
malloc
free
pause
sleep
usleep
exit

Server tem de mostrar o seu PID
Client tem 2 argumentos, Server PID e String para enviar

o client envia a frase e o servidor deve imprimir na tela
tem de ser rapido

tem de receber varias frases de varios clientes  sem reiniciar
so pode se utilizado UNIX signals

So posso usar 2 signals
	SIGUSR1 & SIGUSR2


1- Saber como mostrar o PID do servidor
	- basta correr o getpid() e assim diz qual o PID do processo (servidor)
2- Fazer main no client para receber 2 argumentos



Problemas:

- Tenho de validar que o PID sao numeros
- Tenho de validar o numero de argumentos
- Tenho de


o SIGUSR e um sinal combinado entre as diferentes aplicacoes por isso 
tenho de criar o que fazer com o sinal que combinar.

do lado do envio (cliente) envio o sinal 1 e do lado da rececao (server)
recebo esse signal (1 neste exemplo) e faco o que quiser com ele

*/