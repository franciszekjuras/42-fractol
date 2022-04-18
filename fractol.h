#ifndef FRACTOL_H
# define FRACTOL_H

# include <libgf/gf.h>
# include <libgf/cplx.h>

typedef struct s_data
{
	t_gf_point	center;
	t_cplx		pos;
	double		ppx;
}	t_data;

#endif