#include "cplx.h"

t_cplx	cplx_square(t_cplx a)
{
	t_cplx v;

	v.re = a.re * a.re - a.im * a.im;
	v.im = 2 * (a.re * a.im);
	return (v);
}

t_cplx	cplx_conj(t_cplx a)
{
	a.im = -a.im;
	return (a);
}

double	cplx_abs2(t_cplx a)
{
	return (a.re * a.re + a.im * a.im);
}
