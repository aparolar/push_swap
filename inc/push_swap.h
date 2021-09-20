/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:26:13 by aparolar          #+#    #+#             */
/*   Updated: 2021/09/18 09:46:54 by aparolar         ###   ########.fr       */
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
	size_t				*size;
	struct s_pa_list	**start;
	struct s_pa_list	**end;
	struct s_pa_list	*next;
	struct s_pa_list	*past;
}						t_pa_list;

typedef struct s_pa_collection
{
	int					min;
	int					max;
	int					med;
	int					chunk_size;
	int					position;
	struct s_pa_list	*a;
	struct s_pa_list	*b;
}						t_pa_collection;

/*
**  Functions
*/

/*
**    List Functions
*/

t_pa_list   *initialize_list(int value);
t_pa_list   *add_new_node(t_pa_list *tpalist, int value);
//t_pa_list	*remove_node(t_pa_list *tpalist);
t_pa_list	*insert_at_begin(t_pa_list *node, t_pa_list *target);
t_pa_list	*insert_at_end(t_pa_list *node, t_pa_list *target);
t_pa_list	*extract_node(t_pa_list *node);
size_t		ext_lst_get_size(t_pa_list *lst);
void		ext_lst_set_size(t_pa_list *lst, size_t value);
t_pa_list	*ext_lst_get_start(t_pa_list *lst);
void		ext_lst_set_start(t_pa_list *lst, t_pa_list *node);
t_pa_list	*ext_lst_get_end(t_pa_list *lst);
void		ext_lst_set_end(t_pa_list *lst, t_pa_list *node);

/*
**    Parse Functions
*/

size_t		parse_args(int argc, char **argv, t_pa_list *tpalist);

/*
**    Check Functions
*/

int			check_duplicates(t_pa_list *tpalist);

/*
**    Sort Functions
*/

void		start_sort(t_pa_collection *collection);
int			is_sorted(t_pa_list *t_pa_list);
int			is_reverse_sorted(t_pa_list *tpalist);
int			is_negatives_sorted(t_pa_list *tpalist);
int			is_neg_reverse_sorted(t_pa_list *tpalist);
int			have_negatives(t_pa_list *tpalist);
int			have_positives(t_pa_list *tpalist);
void		quikly_sort(t_pa_collection *tpc);
void		chunk_quick_sort(t_pa_collection *tpc);
int			find_node_value(t_pa_list *node, int value);
int			find_min_value(t_pa_list *node, int min_value);
int			find_max_value(t_pa_list *node);

/*
**   Sort Methods
*/

void		jamie_sort(t_pa_collection *tpc);
void		radix_sort(t_pa_collection *tpc);

/*
**    Statistic Functions
*/

void		stats_list(t_pa_collection *tpc);
void		print_lists(t_pa_collection *tpc);

/*
**    Push Swap Rules
*/

int			swap_a(t_pa_collection *tcp);
int			swap_b(t_pa_collection *tcp);
int			swap_ab(t_pa_collection *tcp);
int 		push_a(t_pa_collection *tpc);
int 		push_b(t_pa_collection *tpc);
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
void		rotate_value_b(t_pa_collection *tpc, int value);

#endif