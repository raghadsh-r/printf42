NAME = libftprintf.a  
CC = cc
CFLAGS = -Wall -Werror -Wextra 
AR = ar rcs 
SRCS = ft_printf.c helper_fun.c print_string.c print_char.c print_pointer.c
OBJS = $(SRCS:.c=.o)
path = /home/raghad/Documents/libft/lv.2

all: $(NAME)
	make -C $(path)

bonus: $(NAME)
	make -C $(path)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	make -C $(path) clean

fclean: clean
	rm -f $(NAME)
	make -C $(path) fclean

re: fclean all

.PHONY: clean fclean re all
