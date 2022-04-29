#ifndef FT_BSQ_H
# define FT_BSQ_H

# include <stdio.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_conf
{
	int				h;
	int				w;
	unsigned char	empty;
	unsigned char	obstacle;
	unsigned char	full;
}	t_conf;

typedef struct s_point
{
	int	x;
	int	y;
	int	size;
}	t_point;

int		ft_check_mapnewline(int i, char c, char *tmp);
int		ft_check_conf_printable(t_conf *conf);
int		ft_check_conf(t_conf *conf);
int		ft_check_map_char(char c, t_conf *conf);
t_conf	*ft_create_conf(void);
int		ft_read_conf(int fd, t_conf *conf);
int		**ft_create_map(t_conf *conf);
void	ft_clear_map(int **map, t_conf *conf);
int		*ft_create_map_elem(int w);
int		**ft_create_map_and_first_element(char *tmp, t_conf *conf);
int		**ft_read_first_line_map(int fd, t_conf *conf);
int		ft_read_oth_lines_map(int fd, t_conf *conf, int **map);
void	ft_putchar(char c);
void	ft_print_map(int **map, t_conf *conf);
void	ft_printer(void);
int		ft_read(int fd);
void	func(int **map, t_conf *conf);

#endif
