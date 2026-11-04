NAME = libftprintf.a  
CC = cc
CFLAGS = -Wall -Werror -Wextra 
AR = ar rcs 
SRCS = ft_printf.c helper_fun.c print_string.c print_char.c print_pointer.c print_other.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

bonus: $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
