#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/my.h"

int     my_getnbr(char *str)
{
  int   var;
  int   inv;
  int   i;

  inv = 1;
  var = 0;
  i = 0;
  if (str == NULL)
    return (0);
  while ((*str < 47 || *str > 58) && *str != 0)
    {
      str++;
      i++;
    }
  if (i > 0 && *(str - 1) == 45)
    inv--;
  while (*str != 0 && *str >= '0' && *str <= '9')
    {
      var *= 10;
      var += (*str - 48);
      str++;
    }
  var *= inv;
  return (var);
}

char    **my_malloc_tab(char **tab, int x, int y)
{
  int   i;

  i = 0;
  tab = malloc(sizeof (char *) * (y + 1));
  while (i <= y)
    {
      tab[i] = malloc(sizeof (char) * (x + 1));
      i++;
    }
  return (tab);
}

void    my_set_bsq_tab(char *str, t_struct *var, char **tab)
{
  int   i;

  i = 0;
  while (str[i] != '\n')
    i++;
  i++;
  while (str[i] != 0)
    {
      if (str[i] != '\n')
        {
          tab[var->y][var->x] = str[i];
          var->x += 1;
        }
      else
        {
          var->x = 0;
          var->y += 1;
        }
      i++;
    }
  var->x = 0;
  var->y = 0;
}

void    my_set_bsq(char *str, t_struct *var)
{
  int   i;
  char  nb_l[6];

  var->x = 0;
  var->size = 1;
  i = 0;
  while (str[i] != '\n')
    {
      nb_l[i] = str[i];
      i++;
    }
  var->height = my_getnbr(nb_l);
  i++;
  var->y = i;
  while (str[i] != '\n')
    i++;
  var->width = i - var->y;
  var->y = 0;
}

void    my_resquare(char **tab, int i, int j, t_struct *var)
{
  var->x = i;
  var->y = j;
  var->size += 1;
  check_square(tab, i, j, var);
}
