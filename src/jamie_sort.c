/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jamie_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 11:55:25 by aparolar          #+#    #+#             */
/*   Updated: 2021/09/18 09:33:17 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	jamie_sort(t_pa_collection *tpc)
{
	int	min;
	
	while (ext_lst_get_start(tpc->a)->next)
	{
		if (is_sorted(tpc->a) && is_reverse_sorted(tpc->b))
			break ;
		min = find_min_value(tpc->a->next, INT_MIN);
		rotate_value(tpc, min);
		push_b(tpc);
	}
	while (ext_lst_get_start(tpc->b)->next)
		push_a(tpc);
}