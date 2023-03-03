/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yghari <yghari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:24:02 by yghari            #+#    #+#             */
/*   Updated: 2022/01/11 23:54:35 by yghari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<signal.h>
#include<unistd.h>
#include<stdio.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	return (nbr * sign);
}

void	anotherfbchar(char c, int pid)
{
	int	j;
	int	b;

	b = 0;
	j = 7;
	while (j >= 0)
	{
		b = ((c >> j) & 1);
		if (b == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		j--;
		usleep(250);
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac != 3)
		write(1, "Naah it dosent work like that try [client] [pid] [msg]",
			sizeof("Naah it dosent work like that try [client] [pid] [msg]"));
	else
	{
		pid = ft_atoi(av[1]);
		while (av[2][i])
		{
			anotherfbchar(av[2][i], pid);
			i++;
		}
	}
	write (1, "msg recieved", sizeof("msg recieved"));
}
