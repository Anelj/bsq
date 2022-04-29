#include "ft_bsq.h"

int	main(int ac, char **av)
{
	int	i;
	int	fd;

	i = 1;
	if (ac == 1)
	{
		if (ft_read(0))
			ft_printer();
		close(0);
	}
	while (i < ac)
	{
		fd = open(av[i], O_RDONLY);
		if (fd != -1)
		{
			if (ft_read(fd))
				ft_printer();
			close(fd);
		}
		else
			ft_printer();
		i++;
		if (i <= ac - 1)
			write(1, "\n", 1);
	}
}
