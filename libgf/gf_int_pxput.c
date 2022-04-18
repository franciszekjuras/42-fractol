#include "gf.h"

void	gf_int_img_pxput4(t_gf_img *img, t_gf_point pt, int good_color)
{
	int	*adr;

	adr = img->adr + img->lnlen * pt.y;
	adr += pt.x;
	*adr = good_color;
}
