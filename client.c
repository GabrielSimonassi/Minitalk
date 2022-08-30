/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimonas <gsimonas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:52:28 by gsimonas          #+#    #+#             */
/*   Updated: 2022/08/27 16:08:54 by gsimonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <string.h>

void	chartobin(char c, int pid_dest)
{
	int i;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
			kill(pid_dest, SIGUSR1);
		else
			kill(pid_dest, SIGUSR2);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int	pid_dest;
	int	len;
	int	count;

	count = 0;
	len = strlen(argv[2]);
	pid_dest = atoi(argv[1]);
	while (argv[2][count] >= len)
	{	
		chartobin(argv[2][count], pid_dest);
		count++;
	}
	return (0);
}
