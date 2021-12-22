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

FLAGS		=	-Wall -Wextra -Werror

$(NAME):		$(OBJS)
				git submodule init
				git submodule update
				make -s -C lib/libft
				$(CC) $(FLAGS) $(SRCS) $(LIBFT) -o $(NAME)

all:			$(NAME)

re:				fullclean
				$(MAKE)

clean:
				rm -rf $(OBJS)

fclean:			clean		
				rm -rf $(NAME)

test:			re
				./$(NAME) 1

fullclean:		fclean
				@make fclean -s -C lib/libft 2>/dev/null

.PHONY:			all re clean fclean
