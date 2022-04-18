#include "cplx.h"

void	cplx_iadd(t_cplx *a, t_cplx b)
{
	a->re += b.re;
	a->im += b.im;
}

void	cplx_isub(t_cplx *a, t_cplx b)
{
	a->re -= b.re;
	a->im -= b.im;
}

void	cplx_iscale(t_cplx *a, double s)
{
	a->re *= s;
	a->im *= s;
}
