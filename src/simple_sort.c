/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 20:26:52 by aparolar          #+#    #+#             */
/*   Updated: 2021/10/20 10:49:19 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	two_sort_a(t_pa_collection *tpc)
{
	t_pa_list	*node;

	node = tpc->a->next;
	if (!is_sorted(tpc->a) && node && node->value > node->next->value)
		swap_a(tpc);
}

void	three_sort_a(t_pa_collection *tpc)
{
	t_pa_list	*node;

	node = tpc->a->next;
	if (node)
	{
		if (node->value == find_max_value(tpc->a))
			rotate_a(tpc);
		node = tpc->a->next;
		if (node->next->value == find_max_value(tpc->a))
			reverse_rotate_a(tpc);
		node = tpc->a->next;
		if (node->value > node->next->value)
			swap_a(tpc);
	}
}

void	five_sort_a(t_pa_collection *tpc)
{
	two_sort_a(tpc);
	if (!is_sorted(tpc->a))
	{
		while (*tpc->a->size > 4)
		{
			rotate_value(tpc, find_min_value(tpc->a, INT_MIN));
			push_b(tpc);
		}
		three_sort_a(tpc);
		while (tpc->b->next)
			push_a(tpc);
	}
}
