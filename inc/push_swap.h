/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:26:13 by aparolar          #+#    #+#             */
/*   Updated: 2021/12/28 10:17:20 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../lib/libft/libft.h"

/*
**  Structures
*/

typedef struct s_pa_list
{
	int					value;
	int					index;
	int					*size;
	struct s_pa_list	**start;
	struct s_pa_list	**end;
	struct s_pa_list	*next;
	struct s_pa_list	*past;
}						t_pa_list;

typedef struct s_pa_collection
{
	struct s_pa_list	*a;
	struct s_pa_list	*b;
}						t_pa_collection;

/*
**  Functions
*/

/*
**    List Functions
*/

t_pa_list	*initialize_list(int value);
t_pa_list	*add_new_node(t_pa_list *tpalist, int value);
t_pa_list	*insert_at_begin(t_pa_list *node, t_pa_list *target);
t_pa_list	*insert_at_end(t_pa_list *node, t_pa_list *target);
t_pa_list	*extract_node(t_pa_list *node);

/*
**    Parse Functions
*/

size_t		parse_args(int argc, char **argv, t_pa_list *tpalist);
void		assign_indexs(t_pa_list *lst);

/*
**    Check Functions
*/

int			check_duplicates(t_pa_list *tpalist);

/*
**    Sort Functions
*/

void		start_sort(t_pa_collection *collection);
int			is_sorted(t_pa_list *t_pa_list);
int			find_node_value(t_pa_list *node, int value);
int			find_min_value(t_pa_list *node, int min_value);
int			find_max_value(t_pa_list *node);

/*
**   Sort Methods
*/

void		radix_sort(t_pa_collection *tpc);
void		two_sort_a(t_pa_collection *tpc);
void		three_sort_a(t_pa_collection *tpc);
void		five_sort_a(t_pa_collection *tpc);

/*
**    Push Swap Rules
*/

int			swap_a(t_pa_collection *tcp);
int			swap_b(t_pa_collection *tcp);
int			swap_ab(t_pa_collection *tcp);
int			push_a(t_pa_collection *tpc);
int			push_b(t_pa_collection *tpc);
int			rotate_a(t_pa_collection *tpc);
int			rotate_b(t_pa_collection *tpc);
int			rotate_ab(t_pa_collection *tpc);
int			reverse_rotate_a(t_pa_collection *tpc);
int			reverse_rotate_b(t_pa_collection *tpc);
int			reverse_rotate_ab(t_pa_collection *tpc);

/*
**    Advanced Swap Rules
*/

void		rotate_value(t_pa_collection *tpc, int value);

#endif