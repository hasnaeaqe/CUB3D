/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haqajjef <haqajjef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 20:26:45 by haqajjef          #+#    #+#             */
/*   Updated: 2025/10/26 10:41:23 by haqajjef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include ".MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stdio.h>
# include <sys/time.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# define BLACK_COLOR   0x000000 
# define WHITE_COLOR  0xFFFFFF
# define COLOR_PLAYER 0xFF0000 
# define COF 64
# define COLOR_ERROR 0xFFFFFFFF

typedef enum e_texture
{
	NO,
	SO,
	WE,
	EA
}	t_texture;

typedef struct s_garbage
{
	int					type;
	void				*ptr;
	struct s_garbage	*next;
}	t_garbage;

typedef struct s_tocount
{
	int	n_no;
	int	n_so;
	int	n_we;
	int	n_ea;
	int	n_f;
	int	n_c;
}	t_tocount;

typedef struct s_textures
{
	char			*path;
	uint8_t			*pixels;
	mlx_texture_t	*tex;
}	t_textures;

typedef struct s_variables
{
	int		lineheight;
	int		drawstart;
	int		x;
	int		drawend;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	double	raydirx;
	double	sidedistx;
	double	deltadisty;
	double	raydiry;
	double	sidedisty;
	double	deltadistx;
	double	perpwalldist;
	double	camerax;
}	t_variables;

typedef struct s_parse
{
	int			offset_x;
	int			offset_y;
	uint32_t	floor_color;
	uint32_t	ceiling_color;
	int			start_map;
	int			end_map;
	char		**map_cub;
	char		*color_c;
	char		*color_f;
	char		*path_texture[4];
	char		**map;
	double		wall_hit_x;
	double		step;
	double		texPos;
	uint32_t	color;
	t_textures	textures[4];
}	t_parse;

typedef struct s_player
{
	int		mapx;
	int		mapy;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
}	t_player;

typedef struct s_keys
{
	int	up;
	int	down;
	int	left;
	int	right;
	int	a;
	int	d;
}	t_keys;

typedef struct s_data
{
	int			screenwidth;
	int			screenheight;
	int			map_width;
	int			map_height;
	void		*mlx_ptr;
	void		*mlx_win;
	void		*img;
	t_keys		keys;
	t_player	player;
	t_parse		*parse;
}	t_data;


char		*get_next_line(int fd);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		ft_putstr_fd(char *s, int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		**ft_split(char const *s, char c);
char		*ft_strtrim(char const *s1, char const *set);
void		*ft_memset(void *b, int c, size_t len);
long		ft_atoi(char *str, int *overflow);
int			ft_isdigit(int c);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		**copy_map(int fd, char *file);
int			open_file(char *file);
void		initialisation(t_tocount *occ, t_parse *parse);
int			check_occurence(t_parse *parse, t_tocount *count_oc);
void		stock_lignes(t_parse *parse);
int			parse_colors(t_parse *parse);
char		**get_map(t_parse *parse, int start, int end);
int			parse_map(t_parse *parse);
int			find_start_map(char **map);
int			find_end_map(char **map);
int			is_empty_line(char *s);
size_t		ft_len(const char *s);
void		start_raycasting(t_parse *parse);
void		initialisation_mlx(t_data *data);
int			key_press(t_data *data);
int			key_release(t_data *data);
void		close_win(void *ptr);
void		key_handler(void *ptr);
int			raycasting(t_data *data);
int			load_texture(t_parse *parse);
void		stock_lignes(t_parse *parse);
void		texture(t_data *data, t_variables *var, t_parse *parse);
uint32_t	shifting(char **s);
int			check_virgule(char *s);
int			parse_first(t_parse *parse, int start);
int			is_texture(char *s);
void		close_game(void *ptr);
void		*ft_malloc(size_t size, char *type);
#endif