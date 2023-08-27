#include "minirt.h"

int	main(void)
{
	t_cor	vec = {1, 1, 0};
	t_cor	dir = {2, 1, 0};
	dir = vec_norm(dir);
	float	result = vec_dot(vec, dir);
	// printf("dot: %f\n", result);
	// t_cor	ori = {5, -2, 0};
	// t_cor	cenDir = {0, 1, 0};
	// float	result = vec_dot(ori, cenDir);
	// printf("dot: %f\n", result);
}