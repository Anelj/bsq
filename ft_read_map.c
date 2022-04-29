#include "ft_bsq.h"

int	ft_read_conf(int fd, t_conf *conf)
{
	char	c;
	int		tmp;

	while (read(fd, &c, 1) > 0 && c != '\n')
	{
		tmp = conf->empty;
		if (tmp != 0 && tmp >= '0' && tmp <= '9' && conf->h >= 0)
			conf->h = conf->h * 10 + (tmp - '0');
		else if (tmp != 0)
			return (1);
		conf->empty = conf->obstacle;
		conf->obstacle = conf->full;
		conf->full = c;
	}
	if (conf->h <= 0 || conf->empty == 0
		|| conf->obstacle == 0 || conf->full == 0)
	{
		return (1);
	}
	return (0);
}

int	**ft_read_first_line_map(int fd, t_conf *conf)
{
	char	*tmp;
	char	c;
	int		i;

	tmp = malloc(25001);
	i = 0;
	while (read(fd, &c, 1) > 0 && c != '\n' && i != 25000)
	{
		if (ft_check_map_char(c, conf))
		{
			free(tmp);
			return (NULL);
		}
		tmp[i] = c;
		i++;
	}
	if (ft_check_mapnewline(i, c, tmp))
		return (NULL);
	tmp[i] = '\0';
	conf->w = i;
	return (ft_create_map_and_first_element(tmp, conf));
}

int	ft_convert_char(char c, t_conf *conf)
{
	if (c == conf->obstacle)
		return (0);
	return (1);
}

int	ft_read_oth_lines_map(int fd, t_conf *conf, int **map)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	while (++i < conf->h)
	{
		map[i] = ft_create_map_elem(conf->w);
		if (map[i] == NULL)
			return (1);
		j = 0;
		while (read(fd, &c, 1) > 0 && c != '\n' && j < conf->w)
		{
			if (ft_check_map_char(c, conf))
				return (1);
			map[i][j] = ft_convert_char(c, conf);
			j++;
		}
		if (j != conf->w || c != '\n')
			return (1);
	}
	if (read(fd, &c, 1) > 0)
		return (1);
	return (0);
}

int	ft_read(int fd)
{
	t_conf	*conf;
	char	c;
	int		**map;

	map = NULL;
	if (fd != -1)
	{
		conf = ft_create_conf();
		if (conf != NULL && read(fd, &c, 0) == 0 && ft_read_conf(fd, conf) == 0)
			map = ft_read_first_line_map(fd, conf);
		if (map == NULL || ft_read_oth_lines_map(fd, conf, map))
		{
			if (fd == 0)
			{
				while (read(0, &c, 1))
					c++;
			}
			ft_clear_map(map, conf);
			return (1);
		}
		func(map, conf);
		ft_clear_map(map, conf);
		return (0);
	}
	return (1);
}
