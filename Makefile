NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -I./libft/includes -fsanitize=address

AR = ar -rc

SRCS_DIR = ./src/algo \
		   ./src/push_swap \
		   ./src/shared \

OBJS_DIR = ./objs
INC_DIR = ./includes
LIBFT_DIR = ./libft
LIBFT = libft.a
BONUS_DIR = ./checker_bonus

SRCS = ./push_swap/push_swap.c\
	   ./shared/check_args.c \
	   ./shared/stack_management.c \
	   ./shared/special_atoi.c \
	   ./shared/fill_stack.c \
	   ./shared/median.c \
	   ./algo/five.c \
	   ./algo/hundred.c \


OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

vpath %.c $(SRCS_DIR)

RM = rm -rf

all : $(NAME)

bonus : re
	echo "Compiling bonus checker..."
	@$(MAKE) fclean -C $(BONUS_DIR)
	@$(MAKE) -C $(BONUS_DIR)
	@cp checker_bonus/checker ./checker
	echo "bonus checker has been compiled..."

$(NAME) : $(OBJS)
	echo "Compling libft..."
	@$(MAKE) -C $(LIBFT_DIR)
	echo "Libft has been compiled..."
	echo "Compiling push_swap"
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft
	echo "push_swap has been compiled..."

$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o : %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -o $@ -I $(INC_DIR) -I$(LIBFT_DIR) -c $^

clean :
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(OBJS_DIR)

fclean : clean
	@$(RM) $(NAME)
	@if [ -f ./checker ]; then $(RM) ./checker; fi;

re : fclean all
