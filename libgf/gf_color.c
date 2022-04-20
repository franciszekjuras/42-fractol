#include <math.h>
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

/**
 * Conversion from hsl to (rgb) t_gf_color.
 * All parameters are in [0, 1] range.
 * 
 * @param h hue
 * @param s saturation
 * @param l lightness
 * @return t_gf_color 
 */
t_gf_color	gf_hsl(double h, double s, double l)
{
	double	c;
	double	x;
	double	m;

	h = 6. * fmod(h, 1.);
	c = (1. - fabs(2 * l - 1.)) * s * 255.;
	x = c * (1. - fabs(fmod(h, 2.) - 1.));
	m = (l * 255. - c / 2.);
	c = round(c + m);
	x = round(x + m);
	m = round(m);
	if (h < 1.)
		return (gf_rgb(c, x, m));
	else if (h < 2.)
		return (gf_rgb(x, c, m));
	else if (h < 3.)
		return (gf_rgb(m, c, x));
	else if (h < 4.)
		return (gf_rgb(m, x, c));
	else if (h < 5.)
		return (gf_rgb(x, m, c));
	else
		return (gf_rgb(c, m, x));
}

/**
 * Conversion from hsv to (rgb) t_gf_color.
 * All parameters are in [0, 1] range.
 * 
 * @param h hue
 * @param s saturation
 * @param l lightness
 * @return t_gf_color 
 */
t_gf_color	gf_hsv(double h, double s, double v)
{
	double	c;
	double	x;
	double	m;

	h = 6. * fmod(h, 1.);
	c = s * v * 255.;
	x = c * (1. - fabs(fmod(h, 2.) - 1.));
	m = (v * 255. - c);
	c = round(c + m);
	x = round(x + m);
	m = round(m);
	if (h < 1.)
		return (gf_rgb(c, x, m));
	else if (h < 2.)
		return (gf_rgb(x, c, m));
	else if (h < 3.)
		return (gf_rgb(m, c, x));
	else if (h < 4.)
		return (gf_rgb(m, x, c));
	else if (h < 5.)
		return (gf_rgb(x, m, c));
	else
		return (gf_rgb(c, m, x));
}
