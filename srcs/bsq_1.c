/*
** bsq_1.c for bsq_1 in
**
** Made by Dylan RESTELLI
** Login   <restel_d@epitech.net>
**
** Started on  Mon Dec 21 15:24:32 2015 Dylan RESTELLI
** Last update Thu Feb 18 18:07:57 2016 restel_d
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/my.h"

#define FAIL_OPEN "camarchepas\n"

void	check_square(char **tab, int i, int j, t_struct *var)
{
  int	i_bis;
  int	j_bis;
  int	check;

  if (var->x + var->size <= var->width && var->y + var->size <= var->height)
    {
      check = 0;
      j_bis = j;
      while (j_bis < (j + var->size))
	{
	  i_bis = i;
	  while (i_bis < (i + var->size))
	    {
	      if (tab[j_bis][i_bis] != '.')
		{
		  check = 1;
		  i_bis = i + var->size;
		  j_bis = j + var->size;
		}
	      else
		i_bis++;
	    }
	  j_bis++;
	}
      check == 0 ? my_resquare(tab, i, j, var) : 0;
    }
}

void	bsq_update_tab(char **tab, t_struct *var)
{
  int	i;
  int	j;

  j = var->y;
  while (j < (var->y + var->size - 1))
    {
      i = var->x;
      while (i < (var->x + var->size - 1))
	{
	  tab[j][i] = 'x';
	  i++;
	}
      j++;
    }
}

void	my_puttab(char **tab, t_struct *var, char *str)
{
  int	j;

  j = 0;
  while(j < var->height)
    {
      if (tab[j][0] != 0)
	{
	  write(1, tab[j], var->width);
	  write(1, "\n", 1);
	}
      j++;
    }
  j = 0;
  while (j <= var->height)
    {
      free(tab[j]);
      j++;
    }
  free(tab);
  free(str);
}

void	my_bsq(char *str, t_struct *var)
{
  char	**tab;
  int	i;
  int	j;

  my_set_bsq(str, var);
  tab = my_malloc_tab(tab, var->width, var->height);
  my_set_bsq_tab(str, var, tab);
  var->y = 0;
  var->size = 0;
  j = 0;
  while (j < var->height)
    {
      i = 0;
      while(i < var->width)
	{
	  if (tab[j][i] == '.')
	    check_square(tab, i, j, var);
	  i++;
	}
      j++;
    }
  bsq_update_tab(tab, var);
  my_puttab(tab, var, str);
}

int	main(int ac, char **av)
{
  char *buff;
  struct stat	sb;
  char *tmp;
  int  fd;
  t_struct	var;

  stat(av[1], &sb);
  if ((fd = open(av[1], O_RDONLY)) == -1)
    {
      write(2, FAIL_OPEN, 12);
      return (-1);
    }
  buff = malloc(sizeof (char) * (sb.st_size + 1));
  read(fd, buff, sb.st_size);
  my_bsq(buff, &var);
  close(fd);
}
