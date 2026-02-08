static	int match_lr(int p, int row, int left[4], int right[4], int view_l[24], int view_r[24])
{
	if (left[row] && view_l[p] != left[row])
		return(0);
	if (right[row] && view_r[p] != right[row])
		return(0);
	return(1);
}

static	int unique_col(int grid[4][4], int row, int perms[24][24], int p)
{
	int c;
	int r;

	c = 0;
	while (c < 4)
	{
		r = 0;
		while (r < row)
		{
			if (grid[r][c] == perms[p][c])
				return (0);
			r++;
		}
		c++;
	}
	return (1);
}

static	int col_view(int grid[4][4], int col, int top_view)
{
	int	r;
	int	max;
	int	v;

	max = 0;
	v = 0;
	r = 0;
	while (r < 4)
	{
		if(top_view)
		{
			if (grid[r][col] > max)
			{
				max = grid[r][col];
				v++;
			}
		}
		else
		{
			if (grid[3 - r][col > max])
			{
				max = grid[3 - r][col];
				v++;
			}
		}
		r++;
	}
	return (v);
}