NAME = push_swap

SRCS = command.c \
       command2.c \
       functions.c \
       implement.c \
       push_swap.c \
       main_sort.c \
       main_sort2.c \
       main_sort3.c \
       main_functions.c \
       utility.c \
       storage_nation.c

OBJS = $(SRCS:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

PRINTF_DIR := printf
PRINTF := libftprintf.a
PRINTF_LIB := $(PRINTF_DIR)/$(PRINTF)

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(PRINTF_DIR) -lftprintf -fsanitize=address

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR) all

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
