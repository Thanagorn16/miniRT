#include "minirt.h"

long int	get_elapse_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

int	main(void)
{
	// t_cor	vec = {1, 1, 0};
	// t_cor	dir = {2, 1, 0};
	// dir = vec_norm(dir);
	// float	result = vec_dot(vec, dir);
	// printf("dot: %f\n", result);
	// t_cor	ori = {5, -2, 0};
	// t_cor	cenDir = {0, 1, 0};
	// float	result = vec_dot(ori, cenDir);
	// printf("dot: %f\n", result);
	float	a = 1.520;
	float	b;

	long int start = get_elapse_time();
	int i = 0;

	while (i < 1080 )
	{
		int j = 0;
		while (j < 1920)
		{
			b = a * ((float)i / 1920);
			j++;
		}
		i++;
	}
	printf("b : %f\n", b);
	printf("take time : %ld ms\n", (get_elapse_time() - start) / 1000);
}