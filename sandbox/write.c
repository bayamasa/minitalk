#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int	main()
{	
	const void *a = "h";

	write(1, a, 1);
	return (0);
}
