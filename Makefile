##
## Makefile for makefile in 
## 
## Made by Dylan RESTELLI
## Login   <restel_d@epitech.net>
## 
## Started on  Mon Dec 21 15:28:49 2015 Dylan RESTELLI
## Last update Mon Dec 21 15:29:22 2015 Dylan RESTELLI
##

CC      =       gcc

RM      =       rm -f

NAME	=	bsq

SRCS	=	bsq_1.c \
		bsq_2.c

OBJS	=	$(SRCS:.c=.o)

all     :        $(NAME)

$(NAME) :        $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean   :
	$(RM) $(OBJS)

fclean  :       clean
	$(RM) $(NAME)

re      :     fclean all
