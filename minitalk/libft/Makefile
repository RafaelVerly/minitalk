NAME		= libft.a
CC			= cc
CFLAGS	    = -Wall -Wextra -Werror
LIB			= ar -rc
LIB1		= ranlib

RM			= rm -f

INCS		= libft.h
SRCS		= 	ft_strlen.c ft_itoa.c ft_calloc.c \
				ft_atoi.c ft_bzero.c \
				ft_strdup.c \
				ft_putchar_fd.c ft_putendl_fd.c \
				
				

OBJS 		= 	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(INCS)
			$(LIB) $(NAME) $(OBJS)
			$(LIB1) $(NAME)

.c.o:	
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:	
			$(RM) $(OBJS)

fclean:		clean	
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re 
