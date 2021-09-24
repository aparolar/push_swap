/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 20:26:52 by aparolar          #+#    #+#             */
/*   Updated: 2021/09/23 18:23:33 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    two_sort_a(t_pa_collection *tpc)
{
	t_pa_list   *node;

	node = ext_lst_get_start(tpc->a)->next;
	if (!is_sorted(tpc->a) && node && node->value > node->next->value)
		swap_a(tpc);
}

void    three_sort_a(t_pa_collection *tpc)
{
	t_pa_list   *node;

	node = ext_lst_get_start(tpc->a)->next;
	if (node)
	{
		if (node->value == find_max_value(tpc->a))
			rotate_a(tpc);
		node = ext_lst_get_start(tpc->a)->next;
		if (node->next->value == find_max_value(tpc->a))
			reverse_rotate_a(tpc);
		node = ext_lst_get_start(tpc->a)->next;
		if (node->value > node->next->value)
			swap_a(tpc);
	}
} 

void    five_sort_a(t_pa_collection *tpc)
{
	t_pa_list   *node;
	
	two_sort_a(tpc);
	if (!is_sorted(tpc->a))
	{
		while (ext_lst_get_size(tpc->a) > 4)
		{
			rotate_value(tpc, find_max_value(tpc->a));
			push_b(tpc);
		}
		three_sort_a(tpc);
		while (tpc->b->next)
		{
			push_a(tpc);
			rotate_a(tpc);
		}
	}
}

static int find_near_value(t_pa_list *lst, int value)
{
	t_pa_list	*node;
	int			near;

	near = find_max_value(*lst->start);
	node = (*lst->start);
	while (node)
	{
		if (node->value > value && node->value < near)
			near = node->value;
		node = node->next;
	}
	return(near);
}

void	two_stacks_simple_sort(t_pa_collection *tpc)
{
	while (*tpc->a->size > 4)
	{
		if (find_min_value(tpc->a, INT_MIN) != tpc->a->next->value && 
			find_max_value(tpc->a) != tpc->a->next->value)
			push_b(tpc);
		else
			rotate_a(tpc);
		print_lists(tpc);
		if (*tpc->b->size > 2)
		{
			if ((*tpc->b->end)->value > tpc->b->next->value)
			{
				reverse_rotate_b(tpc);
				reverse_rotate_b(tpc);
				swap_b(tpc);
			}
			if (tpc->b->next->value > tpc->b->next->next->value)
				swap_b(tpc);
		}
		print_lists(tpc);
	}
	three_sort_a(tpc);
	print_lists(tpc);
	while (*tpc->b->size > 1)
	{
		if (tpc->b->next->value > tpc->a->next->value && 
			tpc->b->next->value < tpc->a->next->next->value)
		{
			rotate_a(tpc);
			push_a(tpc);
		}
		else if (tpc->b->next->value < tpc->a->next->value &&
				tpc->b->next->value > (*tpc->a->end)->value)
			push_a(tpc);
		if ((*tpc->b->end)->value < tpc->a->next->value && 
			(*tpc->b->end)->value > (*tpc->a->end)->value)
		{
			reverse_rotate_b(tpc);
			push_a(tpc);			
		}
		else if (tpc->b->next)
			rotate_value(tpc, find_near_value(tpc->a, tpc->b->next->value));
			//reverse_rotate_a(tpc);
		//rotate_b(tpc);
		print_lists(tpc);
	}
	rotate_value(tpc, find_min_value(tpc->a, INT_MIN));
}