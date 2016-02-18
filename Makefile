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
