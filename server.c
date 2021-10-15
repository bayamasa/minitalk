/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:19:08 by mhirabay          #+#    #+#             */
/*   Updated: 2021/10/14 17:19:41 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"


int sig_handler()
{
	write(1, "hello", 5);
	return (1);
}

void print()
{
	write(1, "hello", 5);
}

int main ()
{
	pid_t				pid;
	struct sigaction	act;

	pid = getpid();
	printf("pid = %d\n", pid);
	memset(&act, 0, sizeof(act));
	act.sa_handler = print;
	int rc = sigaction(SIGUSR1, &act, NULL);
	if(rc < 0)
	{
		printf("Error: sigaction() %s\n", "test");
		exit(1);
	}
	while(1) {
		printf("I'm working...\n");
		sleep(1);
    }
}
