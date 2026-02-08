
/*check if the clues match the value of the row view*/
static	int match_lr(int p, int row, int left_clue[4], int right_clue[4], int view_l[24], int view_r[24])
{
	if (left_clue[row] && (view_l[p] != left_clue[row]))
		return(0);
	if (right_clue[row] && (view_r[p] != right_clue[row]))
		return(0);
	return(1);
}
/*check if there are duplicate columns*/
static	int unique_col(int grid[4][4], int row, int perms[24][24], int p)
{
	int c;
	int r;

	c = 0;
	while (c < 4)
	{
		r = 0;
		while (r < row) /*only check already filled spaces*/
		{
			if (grid[r][c] == perms[p][c])
				return (0);
			r++;
		}
		c++;
	}
	return (1);
}
/*calculate view when all rows are filled top_view is pseudo boolean 1=topview 0=botview*/
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
			/*bottom view just reverse the index r*/
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
/*Check if column clues match result*/
static	int check_table(int grid[4][4], int	top_clue[4], int bot_clue[4])
{
	int c;

	c = 0;
	while (c < 4)
	{
		if (top_clue[c] && col_view(grid, c, 1) != top_clue[c])
			return (0);
		if (bot_clue[c] && col_view(grid, c, 0) != bot_clue[c])
			return (0);
		c++;
	}
	return (1);
}