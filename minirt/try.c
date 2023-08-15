#include <stdio.h>

void	print(int const a)
{
	printf("%d\n", a);
}

int	main(void)
{
	int		a =255;
	float	b = 0.3;
	int		c = a * b;
	printf("%d\n", c);
}
