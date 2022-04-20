#include <math.h>
#include <libgf/cplx.h>
#include <libgf/gf.h>
#include "fractol.h"

int	mandelbrot(t_cplx c, int maxit, double *params)
{
	int		i;
	t_cplx	z;
	double	c2;

	(void) params;
	c2 = cplx_abs2(c);
	if (c2 * (8. * c2 - 3.) <= 3. / 32. - c.re)
		return (maxit);
	c2 = cplx_abs2(cplx_sub(c, cplx(-1, 0)));
	if (c2 <= 1. / 16.)
		return (maxit);
	i = 0;
	z = cplx(0, 0);
	while (i < maxit && cplx_abs2(z) < 4.)
	{
		z = cplx_add(cplx_square(z), c);
		++i;
	}
	return (i);
}

int	julia(t_cplx c, int maxit, double *params)
{
	int		i;
	t_cplx	z;
	t_cplx	p;

	p = cplx(params[0], params[1]);
	i = -1;
	z = c;
	while (++i < maxit && cplx_abs2(z) < 4.)
		z = cplx_add(cplx_square(z), p);
	return (i);
}
