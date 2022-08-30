/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimonas <gsimonas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:15:01 by gsimonas          #+#    #+#             */
/*   Updated: 2022/08/27 17:25:01 by gsimonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

char msg[8];

void	handler(int sig)
{	
	
	int	i;
	
	i = 0;
	while (i < 8)
	{
		if (sig == SIGUSR1)
			msg[i] = '1';
		else if (sig == SIGUSR2)
			msg[i] = '0';
		i++;	
	}
	printf("\n%s\n", msg);
}

int	main(void)
{	
	struct sigaction sig_handler;
	sig_handler.sa_handler = &handler;
	sigaction(SIGUSR1, &sig_handler, NULL);
	sigaction(SIGUSR2, &sig_handler, NULL);
	
	printf("%d\n", getpid());
	while (1)
	{
		usleep(500);
	}
	return (0);
	
}
