SOURCES = server.c client.c server_bonus.c client_bonus.c
OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = server client
LIBFT = libft/libft.a
BONUS = server_bonus client_bonus

all: $(LIBFT) $(NAME) 

bonus:	$(LIBFT) $(BONUS) 
	
server: server.o 
	$(CC) -o $@ $< -Llibft -lft

client: client.o
	$(CC) -o $@ $< -Llibft -lft

server_bonus: server_bonus.o
	$(CC) -o $@ $< -Llibft -lft

client_bonus: client_bonus.o
	$(CC) -o $@ $< -Llibft -lft

%.o: %.c
	$(CC) -c $(CFLAGS) $?

$(LIBFT):
	make -C libft

clean:
	rm -f $(OBJECTS)
	make -C libft clean
	
fclean: clean
	rm -f server client client_bonus server_bonus  libft/libft.a

re: fclean all

.PHONY: all bonus  clean fclean re
	
