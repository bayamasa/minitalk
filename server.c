/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:19:08 by mhirabay          #+#    #+#             */
/*   Updated: 2021/10/20 23:07:18 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	sigfunc(int sig, siginfo_t *info, void *ucontext)
{
	g_sigattr.count += 1;
	if (sig == SIGUSR1 && g_sigattr.count <= 6)
	{
		g_sigattr.bit <<= 1;
	}
	else if (sig == SIGUSR2 && g_sigattr.count <= 6)
	{
		g_sigattr.bit |= 1;
		g_sigattr.bit <<= 1;
	}
	if (g_sigattr.count == 7)
	{
		if (sig == SIGUSR2)
			g_sigattr.bit |= 1;
		write(1, &g_sigattr.bit, 1);
		g_sigattr.bit = 0;
		g_sigattr.count = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	act;
	int					rc;

	pid = getpid();
	printf("pid = %d\n", pid);
	memset(&act, 0, sizeof(act));
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = sigfunc;
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
		sleep(10);
	}
}
