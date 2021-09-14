/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:11:49 by aparolar          #+#    #+#             */
/*   Updated: 2021/09/02 17:21:49 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	radix_sort(t_pa_collection *tpc)
{
	unsigned int	mask;
	unsigned int	neg_mask;
	int				sorted;
	int				have_neg;
	t_pa_list		*a;

	mask = 1;
	sorted = 0;
	neg_mask = INT_MIN;
	while (mask < (unsigned int)neg_mask)
	{
		a = ext_lst_get_start(tpc->a)->next;
		while (a)
		{
			if (a->value >= 0 && (a->value & mask) == 0)
			{
				rotate_value(tpc, a->value);
				push_b(tpc);
				a = ext_lst_get_start(tpc->a)->next;
			}
			else
				a = a->next;
		}
		sorted = is_reverse_sorted(ext_lst_get_start(tpc->b));
		have_neg = have_positives(ext_lst_get_start(tpc->a));
		while (ext_lst_get_start(tpc->b)->next)
			push_a(tpc);
		if (sorted && !have_neg)
			break;
		mask = mask << 1;
	}
	/*
	mask = 1;
	while (mask > 0)
	{
		a = ext_lst_get_start(tpc->a)->next;
		while (a)
		{
			if (a->value < 0 && (a->value & mask) == mask)
			{
				rotate_value(tpc, a->value);
				push_b(tpc);
				a = ext_lst_get_start(tpc->a)->next;
			}
			else
				a = a->next;
		}
		sorted = is_sorted(ext_lst_get_start(tpc->b));
		have_neg = have_negatives(tpc->a);
		while (ext_lst_get_start(tpc->b)->next)
		{
			if (ext_lst_get_size(tpc->b) > 1 && sorted && !have_neg)
				reverse_rotate_b(tpc);
			push_a(tpc);
		}
		if (sorted && !have_neg)
			break ;
		mask = (mask << 1);
	}*/
}