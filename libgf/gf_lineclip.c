#include "gf.h"
#include "gf_int.h"

static int	calc_tblr(t_gf_point *pt, t_gf_point corn)
{
	int	r;

	r = 0;
	if (pt->y < 0)
		r |= GF_T;
	else if (pt->y > corn.y)
		r |= GF_B;
	if (pt->x < 0)
		r |= GF_L;
	else if (pt->x > corn.x)
		r |= GF_R;
	return (r);
}

static int	pointclip(t_gf_point *p1, t_gf_point *p2, t_gf_point corn, int tblr)
{
	if (tblr & GF_T)
	{
		p1->x += (long)(p2->x - p1->x) * (0 - p1->y) / (p2->y - p1->y);
		p1->y = 0;
	}
	else if (tblr & GF_B)
	{
		p1->x += (long)(p2->x - p1->x) * (corn.y - p1->y) / (p2->y - p1->y);
		p1->y = corn.y;
	}
	else if (tblr & GF_L)
	{
		p1->y += (long)(p2->y - p1->y) * (0 - p1->x) / (p2->x - p1->x);
		p1->x = 0;
	}	
	else if (tblr & GF_R)
	{
		p1->y += (long)(p2->y - p1->y) * (corn.x - p1->x) / (p2->x - p1->x);
		p1->x = corn.x;
	}
	return (calc_tblr(p1, corn));
}

int	gf_lineclip(t_gf_img *img, t_gf_point *pt1, t_gf_point *pt2)
{
	int			tblr[2];
	t_gf_point	corn;

	corn = gf_point(img->w - 1, img->h - 1);
	tblr[0] = calc_tblr(pt1, corn);
	tblr[1] = calc_tblr(pt2, corn);
	while (1)
	{
		if (!(tblr[0] | tblr[1]))
			return (1);
		if (tblr[0] & tblr[1])
			return (0);
		if (tblr[0])
			tblr[0] = pointclip(pt1, pt2, corn, tblr[0]);
		else if (tblr[1])
			tblr[1] = pointclip(pt2, pt1, corn, tblr[1]);
	}
}
