NAME		=	push_swap

S			=	src/

O			=	obj/

I			=	inc/

SRCS		=	$Smain.c\
				$Scolor.c\
				$Sfinish.c\
				$Sfractal.c\
				$Shook.c\
				$Simage.c\
				$Sutils1.c

OBJS		=	$(SRCS:$S%.c=$O%.o)

LIBFT		=	-L lib/libft -lft

CC			=	@gcc

DBGF		=	-g3 -fsanitize=address

FLAGS		=	-Wall -Wextra -Werror

all:			$(NAME)

$(NAME):		
				git submodule init
				git submodule update
				make -s -C lib/libft
				$(CC) $(FLAGS) $(SRCS) $(LIBFT) -o $(NAME)

$O%.o:			$(OBJS)
				$(CC) $(FLAGS) -c $< -o $@

re:				fullclean
				$(MAKE)

bonus:			re

clean:
				rm -rf $O*.o

fclean:			clean		
				rm -rf $(NAME)

test:			re
				./$(NAME) 1

fullclean:		fclean
				@make fclean -s -C lib/libft 2>/dev/null

.PHONY:			all re clean fclean bonus
