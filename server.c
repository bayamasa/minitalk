/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:19:08 by mhirabay          #+#    #+#             */
/*   Updated: 2021/10/15 22:30:54 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int sig_handler()
{
	write(1, "hello", 5);
	return (1);
}

void sigfunc(int sig, siginfo_t *info, void *ucontext)
{
	if (sig == SIGUSR1)
	{
		g_sigattr.bit <<= 1;
		g_sigattr.count += 1;
	}
	else if (sig == SIGUSR2)
	{
		g_sigattr.bit <<= 1;
		g_sigattr.bit |= 1;
		g_sigattr.count += 1;
	}
	if (g_sigattr.count == 8)
	{
		write(1, g_sigattr.bit, 1);
		g_sigattr.count = 0;
	}
}

int main()
{
	pid_t				pid;
	struct sigaction	act;
	int					rc;

	pid = getpid();
	printf("pid = %d\n", pid);
	memset(&act, 0, sizeof(act));
	act.sa_handler = sigfunc;
	act.sa_flags = SA_SIGINFO;
	rc = sigaction(SIGUSR1, &act, NULL);
	if (rc < 0)
	{
		printf("Error: sigaction() %s\n", "test");
		exit(1);
	}
	rc = sigaction(SIGUSR2, &act, NULL);
	if (rc < 0)
	{
		printf("Error: sigaction() %s\n", "test");
		exit(1);
	}
	while (1)
	{
		printf("I'm working...\n");
		sleep(1);
	}
}
