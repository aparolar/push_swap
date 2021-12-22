/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:11:49 by aparolar          #+#    #+#             */
/*   Updated: 2021/10/19 17:44:51 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	radix_sort(t_pa_collection *tpc)
{
	int				max_bits;
	int				i;
	int				j;
	int				size;

	size = *tpc->a->size - 1;
	max_bits = 0;
	while ((size >> max_bits) != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits && !is_sorted(tpc->a))
	{
		j = -1;
		while (++j < size && !is_sorted(tpc->a))
		{
			if (((tpc->a->next->index >> i) & 1) == 1)
				rotate_a(tpc);
			else
				push_b(tpc);
		}
		while (tpc->b->next)
			push_a(tpc);
	}
}
