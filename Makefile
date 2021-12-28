NAME		=	push_swap

S			=	src/

I			=	inc/

SRCS		=	$Spush_swap.c\
				$Slist_utils1.c\
				$Sparse_utils1.c\
				$Scheck_duplicates.c\
				$Ssort.c\
				$Ssort_utils1.c\
				$Ssa_sb_ss.c\
				$Spa_pb.c\
				$Sra_rb_rr.c\
				$Srra_rrb_rrr.c\
				$Sradix_sort.c\
				$Ssimple_sort.c\

OBJS		=	$(SRCS:.c=.o)

LIBFT		=	-L lib/libft -lft

CC			=	@gcc

DBGF		=	-g3 -fsanitize=address

FLAGS		=	-Wall -Wextra -Werror $(DBGF)

$(NAME):		$(OBJS)
				make -s -C lib/libft
				$(CC) $(FLAGS) $(SRCS) $(LIBFT) -o $(NAME)

all:			$(NAME)

re:				fullclean
				$(MAKE)

clean:
				rm -rf $(OBJS)
				@make clean -s -C lib/libft 2>/dev/null

fclean:			clean
				rm -rf $(NAME)
				@make fclean -s -C lib/libft 2>/dev/null

test:			re
				./$(NAME) 1

fullclean:		fclean
				@make fclean -s -C lib/libft 2>/dev/null

git_push:		fullclean
				git add .
				git status
				git commit -m "Update $(shell date)"
				git push

.PHONY:			all re clean fclean
