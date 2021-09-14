NAME		=	push_swap

S			=	src/

O			=	obj/

I			=	inc/

SRCS		=	$Spush_swap.c\
				$Slist_utils1.c\
				$Slist_utils2.c\
				$Sparse_utils1.c\
				$Scheck_duplicates.c\
				$Ssort.c\
				$Ssort_utils1.c\
				$Ssort_utils2.c\
				$Ssa_sb_ss.c\
				$Spa_pb.c\
				$Sra_rb_rr.c\
				$Srra_rrb_rrr.c\
				$Sstats.c\
				$Sjamie_sort.c\
				$Sradix_sort.c\
				$Sext_list_sub_size.c\
				$Sext_list_sub_start.c\
				$Sext_list_sub_end.c\

OBJS		=	$(SRCS:$S%.c=$O%.o)

LIBFT		=	-L lib/libft -lft

CC			=	@gcc

DBGF		=	-g3 -fsanitize=address

FLAGS		=	-Wall -Wextra -Werror $(DBGF)

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
