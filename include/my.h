#ifndef	MY_H_
#define	MY_H_

typedef	struct	s_struct
{
  int	x;
  int	y;
  int	width;
  int	height;
  int	size;
}		t_struct;

int	my_getnbr(char *str);
char	**my_malloc_tab(char **tab, int x, int y);
void	my_set_bsq_tab(char *str, t_struct *var, char **tab);
void	my_set_bsq(char *str, t_struct *var);
void	my_resquare(char **tab, int i, int j, t_struct *var);
void	check_square(char **tab, int i, int j, t_struct *var);
void	bsq_update_tab(char **tab, t_struct *var);
void	my_puttab(char **tab, t_struct *var, char *str);
void	my_bsq(char *str, t_struct *var);

#endif
