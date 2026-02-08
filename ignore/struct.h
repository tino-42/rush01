#ifndef SKYSCRAPER_H
#define SKYSCRAPER_H

#include <unistd.h>

struct s_ctx
{
	int	top[4];
	int	bot[4];
	int	left[4];
	int	right[4];

	int	grid[4][4];
	int	used[4][4];

	int	perms[24][4];
	int	view_l[24];
	int	view_r[24];

	int	row_cand[4][24];
	int	row_cand_n[4];
	int	row_order[4];
};

void	init_perms(struct s_ctx *c);
#endif