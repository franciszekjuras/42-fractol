#include <mlx/mlx.h>
#include "gf.h"

int	gf_ctoi(t_gf_color color)
{
	return ((color.r << 16) + (color.g << 8) + color.b);
}

t_gf_color	gf_rgb(int r, int g, int b)
{
	t_gf_color	color;

	color.a = 0;
	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_gf_grad	gf_grad(t_gf_color beg, t_gf_color end, double ibeg, double iend)
{
	t_gf_grad	g;
	double		idif;

	if (ibeg <= iend)
	{
		g.beg = beg;
		g.end = end;
		g.ibeg = ibeg;
		g.iend = iend;
	}
	else{
		g.beg = end;
		g.end = beg;
		g.ibeg = iend;
		g.iend = ibeg;
	}
	idif = g.iend - g.ibeg;
	// g.va = (g.end.a - g.beg.a) / idif;
	g.vr = (g.end.r - g.beg.r) / idif;
	g.vg = (g.end.g - g.beg.g) / idif;
	g.vb = (g.end.b - g.beg.b) / idif;
	return (g);
}

t_gf_color	gf_color_grad(double i, t_gf_grad *grad)
{
	t_gf_color	c;
	double 		di;

	if (i <= grad->ibeg)
		return (grad->beg);
	if (i >= grad->iend)
		return (grad->end);
	di = (i - grad->ibeg);
	c = grad->beg;
	c.a += (int)(di * grad->va);
	c.r += (int)(di * grad->vr);
	c.g += (int)(di * grad->vg);
	c.b += (int)(di * grad->vb);
	return (c);
}
