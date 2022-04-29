#include "ft_bsq.h"

int	ft_check_mapnewline(int i, char c, char *tmp)
{
	if (i == 0 || c != '\n')
	{
		free(tmp);
		return (1);
	}
	return (0);
}

int	ft_check_conf_printable(t_conf *conf)
{
	if (conf->empty >= 32 && conf->obstacle <= 126
		&& conf->obstacle >= 32 && conf->obstacle <= 126
		&& conf->full >= 32 && conf->obstacle <= 126)
		return (0);
	return (1);
}

int	ft_checkcmp_conf(t_conf *conf)
{
	if (conf->empty == conf->obstacle || conf->empty == conf->full
		|| conf->full == conf->obstacle)
		return (1);
	return (0);
}

int	ft_check_conf(t_conf *conf)
{
	if (ft_check_conf_printable(conf) || ft_checkcmp_conf(conf))
		return (1);
	return (0);
}

int	ft_check_map_char(char c, t_conf *conf)
{
	if (c != conf->empty && c != conf->obstacle)
		return (1);
	return (0);
}
