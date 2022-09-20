/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimonas <gsimonas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:52:28 by gsimonas          #+#    #+#             */
/*   Updated: 2022/09/20 12:59:44 by gsimonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"

int	chartobin(char c, int pid_dest)
{
	int	bit;

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
	if (argc == 3)
	{	
		pid_dest = ft_atoi(argv[1]);
		len = ft_strlen(argv[2]);

		while (count < len)
		{	
			chartobin(argv[2][count], pid_dest);
			count++;
		}
	}
	return (0);
}
