#include <libft/libft.h>
#include "gf.h"

int	gf_iround(double v)
{
	if (v < 0)
		return (v - 0.5);
	return (v + 0.5);
}

int	gf_inimage(t_gf_img *img, t_gf_point *pt)
{
	return (pt->x >= 0 && pt->y >= 0
		&& pt->x < img->w && pt->y < img->h);
}
