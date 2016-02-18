##
## Makefile for makefile in 
## 
## Made by Dylan RESTELLI
## Login   <restel_d@epitech.net>
## 
## Started on  Mon Dec 21 15:28:49 2015 Dylan RESTELLI
## Last update Thu Feb 18 18:07:15 2016 restel_d
##

CC      =       gcc

RM      =       rm -f

NAME	=	bsq

SRCS	=	srcs/bsq_1.c \
		srcs/bsq_2.c

OBJS	=	$(SRCS:.c=.o)

all     :        $(NAME)

$(NAME) :        $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean   :
	$(RM) $(OBJS)

fclean  :       clean
	$(RM) $(NAME)

re      :     fclean all
