
static int	view_count(int a[4])
{
	int i;
	int max;
	int v;

	i = 0;
	max = 0;
	v = 0;
	while (i < 4)
	{
		if (a[i] > max)
		{
			max = a[i];
			v++;
		}
		i++;
	}
	return(v);
}

static	void set_perm(int dest[4], int a, int b, int c, int d)
{
	dest[0] = a;
	dest[1] = b;
	dest[2] = c;
	dest[3] = d;
}

static void	init_perm_table(int perms[24][4])
{
	set_perm(perms[0], 1,2,3,4);
	set_perm(perms[1], 1,2,4,3);
	set_perm(perms[2], 1,3,2,4);
	set_perm(perms[3], 1,3,4,2);
	set_perm(perms[4], 1,4,2,3);
	set_perm(perms[5], 1,4,3,2);
	set_perm(perms[6], 2,1,3,4);
	set_perm(perms[7], 2,1,4,3);
	set_perm(perms[8], 2,3,4,1);
	set_perm(perms[9], 2,3,1,4);
	set_perm(perms[10], 2,4,3,1);
	set_perm(perms[11], 2,4,1,3);
	set_perm(perms[12], 3,1,2,4);
	set_perm(perms[13], 3,1,4,2);
	set_perm(perms[14], 3,2,1,4);
	set_perm(perms[15], 3,2,4,1);
	set_perm(perms[16], 3,4,1,2);
	set_perm(perms[17], 3,4,2,1);
	set_perm(perms[18], 4,3,2,1);
	set_perm(perms[19], 4,3,1,2);
	set_perm(perms[20], 4,2,1,3);
	set_perm(perms[21], 4,2,3,1);
	set_perm(perms[22], 4,1,3,2);
	set_perm(perms[23], 4,1,2,3);
}
void	init_perms(int perms[24][4], int view_l[24],int view_r[24])
{
	int i;
	int tmp[4];

	init_perm_table(perms);
	i = 0;
	while (i < 24)
	{
		view_l[i] = view_count(perms[i]);
		tmp[0] = perms[i][3];
		tmp[1] = perms[i][2];
		tmp[2] = perms[i][1];
		tmp[3] = perms[i][0];
		view_r[i] = view_count(tmp);
		i++;
	}
}