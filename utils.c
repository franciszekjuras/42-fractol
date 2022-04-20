#include <stdlib.h>
#include <math.h>
#include <libgf/gf.h>
#include "fractol.h"

int	close_app(t_gf_ctx *ctx)
{
	(void) ctx;
	exit(0);
	return (0);
}

t_cplx	pt_to_z(t_gf_point pt, t_data *data)
{
	t_cplx	z;

	z.re = ((pt.x - data->center.x) * data->ppx);
	z.im = (-(pt.y - data->center.y) * data->ppx);
	cplx_iadd(&z, data->pos);
	return (z);
}

t_gf_color	color_fun(int it)
{
	double	t;

	t = 0.08 * it;
	t = log10(t + 10.);
	return (gf_hsl(t, 0.8, 0.5 + 0.2 * cos(6 * t)));
}
