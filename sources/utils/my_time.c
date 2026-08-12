#include "includes/cub3d.h"

long	my_time()
{
	long			time;
	struct timeval t;

	gettimeofday(&t, NULL);
	time = t.tv_sec * 1000 + t.tv_usec / 1000;
	return (time);
}
