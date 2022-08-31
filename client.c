/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimonas <gsimonas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:52:28 by gsimonas          #+#    #+#             */
/*   Updated: 2022/08/31 14:32:54 by gsimonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int	chartobin(char c, int pid_dest)
{
	int bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			kill(pid_dest, SIGUSR1);
		else
			kill(pid_dest, SIGUSR2);
		bit++;
		usleep(300);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	pid_dest;
	int	len;
	int	count;

	count = 0;
	pid_dest = atoi(argv[1]);
	len = strlen(argv[2]);
	if (argc)
	{
		while (count < len)
		{	
			chartobin(argv[2][count], pid_dest);
			count++;
		}
	}
	return (0);
}
