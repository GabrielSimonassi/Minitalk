/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimonas <gsimonas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:15:01 by gsimonas          #+#    #+#             */
/*   Updated: 2022/09/13 11:18:04 by gsimonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"

void	sig_handler(int signum)
{	
	static int	c;
	static int	bit;

	if (signum == SIGUSR1)
		c = c | (1 << bit);
	bit++;
	if (bit == 8)
	{
		bit = 0;
		write(1, &c, 1);
		c = 0;
	}
}	

int	main(void)
{	
	ft_printf("-----Server initialized-----");
	ft_printf("\n%d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
		pause();
	}
	return (0);
}
