/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yghari <yghari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 02:21:10 by yghari            #+#    #+#             */
/*   Updated: 2022/01/11 22:59:31 by yghari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<signal.h>
#include<unistd.h>
#include<stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	n;

	if (nb < 0)
	{
		ft_putchar('-');
		n = -nb;
	}
	else
		n = nb;
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
	}
}
// void	ft_ok(int sig)
// {
// 	if(sig == SIGUSR2)
// 		write (1,"MESSAGE RECIEVED", sizeof("MESSAGE RECIEVED"));
// }

void	fbchar(int signal, siginfo_t *sig_info, void *context)
{
	static int		c;
	static int		i;
	static pid_t	pid;

	(void) *context;
	if (pid != sig_info->si_pid)
	{
		i = 0;
		c = 0;
	}
	if (signal == SIGUSR2)
		c += (1 << (7 - i));
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	pid = sig_info->si_pid;
}

int	main(void)
{
	int					pid;
	struct sigaction	sg;

	sg.sa_sigaction = &fbchar;
	sg.sa_flags = SA_SIGINFO;
	pid = getpid();
	if (pid <= 0)
		return (0);
	write (1, "SERVER PID IS : ", sizeof("SERVER PID IS : "));
	ft_putnbr(pid);
	write (1, "\n", 1);
	sigaction (SIGUSR1, &sg, NULL);
	sigaction (SIGUSR2, &sg, NULL);
	while (1)
	{
		pause();
	}
}
