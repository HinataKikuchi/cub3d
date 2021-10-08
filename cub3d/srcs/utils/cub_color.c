#include	"../../include/cub3d.h"

int		create_trgb(int t, int r, int g, int b)
{
	int ret;

	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;

	ret = (t << 24 | r << 16 | g << 8 | b);
	return (ret);
}

double	cub_abs(double n)
{
	if (n < 0)
		return ((-1) * n);
}
