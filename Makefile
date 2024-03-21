NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -f
SRC = mandatory/check_stack.c mandatory/chunk.c mandatory/ft_split.c mandatory/list.c mandatory/max_min.c mandatory/moves.c mandatory/push_swap.c mandatory/sorting.c mandatory/utilities.c mandatory/utilities2.c  
BONUS =	bonus/check_stack.c bonus/checker.c bonus/ft_split.c bonus/get_next_line.c bonus/list.c bonus/moves.c bonus/utilities.c  bonus/get_utilities.c bonus/user_do.c
SRC_OBJ = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(SRC_OBJ)
	$(CC) $(CFLAGS) $(SRC_OBJ) -o $(NAME)

$(NAME_BONUS): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(NAME_BONUS)

bonus/%.o: bonus/%.c bonus/checker.h
	$(CC) $(CFLAGS) -c $< -o $@

mandatory/%.o: mandatory/%.c mandatory/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(SRC_OBJ) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: clean