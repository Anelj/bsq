#include "ft_bsq.h"

int	**ft_create_map_and_first_element(char *tmp, t_conf *conf)
{
	int		**map;
	int		i;

	map = ft_create_map(conf);
	if (map != NULL)
		*map = ft_create_map_elem(conf->w);
	if (map == NULL || map[0] == NULL)
		return (NULL);
	i = 0;
	while (i < conf->w)
	{
		if (tmp[i] == conf->obstacle)
			map[0][i] = 0;
		else
			map[0][i] = 1;
		i++;
	}
	free(tmp);
	return (map);
}

int	**ft_create_map(t_conf *conf)
{
	int		**map;
	int		i;

	map = NULL;
	if (conf->h <= 2147483647 / 8 - 8)
	{	
		map = malloc((conf->h + 1) * 8);
	}
	if (map == NULL)
		return (NULL);
	i = 0;
	while (i < conf->h)
	{
		map[i] = NULL;
		i++;
	}
	map[conf->h] = NULL;
	return (map);
}

void	ft_clear_map(int **map, t_conf *conf)
{
	int	i;

	i = 0;
	if (map != NULL)
	{
		while (i < conf->h)
		{
			free(map[i]);
			i++;
		}
		free(map[i]);
		free(map);
	}
	if (conf != NULL)
		free(conf);
}

int	*ft_create_map_elem(int w)
{
	int	*map_elem;

	map_elem = NULL;
	map_elem = malloc(sizeof(int) * w);
	return (map_elem);
}

t_conf	*ft_create_conf(void)
{
	t_conf	*conf;

	conf = malloc(sizeof(t_conf));
	if (conf == NULL)
		return (NULL);
	conf->h = 0;
	conf->w = 0;
	conf->empty = 0;
	conf->obstacle = 0;
	conf->full = 0;
	return (conf);
}
