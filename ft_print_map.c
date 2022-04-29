#include "ft_bsq.h"

void	ft_printer(void)
{
	write(2, "map error\n", 10);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_map(int **map, t_conf *conf)
{
	int	i;
	int	j;

	i = -1;
	while (++i < conf->h)
	{
		j = -1;
		while (++j < conf->w)
		{
			ft_putchar(map[i][j] + '0');
		}
		ft_putchar('\n');
	}
}
