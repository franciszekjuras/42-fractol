#ifndef FRACTALS_H
# define FRACTALS_H

int	mandelbrot(t_cplx c, int maxit, double *params);
int	julia(t_cplx c, int maxit, double *params);
int	burning_ship(t_cplx c, int maxit, double *params);

#endif