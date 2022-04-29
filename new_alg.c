#include "ft_bsq.h"

int	min(int a, int b, int c)
{
	int	min;

	min = b;
	if (c < a)
	{
		if (c < min)
			return (c);
		return (min);
	}
	else
	{
		if (a < min)
			return (a);
		return (min);
	}
}

void	show(t_point *Point, int **map, t_conf *conf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (j < conf->w)
		{
			if (i >= (Point->y - (Point->size - 1)) && i <= Point->y
				&& j >= (Point->x - (Point->size - 1)) && j <= Point->x)
				write(1, &(conf->full), 1);
			else if (map[i][j] == 0)
				write(1, &(conf->obstacle), 1);
			else
				write(1, &(conf->empty), 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	func_help(int **m, t_point *Point, t_conf *conf)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < conf->h)
	{
		j = 0;
		while (j < conf->w)
		{
			if (m[i][j] == 1 && i > 0 && j > 0)
			{
				m[i][j] += min(m[i - 1][j - 1], m[i - 1][j], m[i][j - 1]);
			}
			if (m[i][j] > Point->size)
			{
				Point->size = m[i][j];
				Point->x = j;
				Point->y = i;
			}
			j++;
		}
		i++;
	}
	show(Point, m, conf);
}

void	func(int **map, t_conf *conf)
{
	t_point	*Point;

	Point = (t_point *)malloc(sizeof(t_point) * 1);
	Point->x = 0;
	Point->y = 0;
	Point->size = 0;
	func_help(map, Point, conf);
	free(Point);
}
