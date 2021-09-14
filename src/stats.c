/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 11:07:13 by aparolar          #+#    #+#             */
/*   Updated: 2021/08/25 11:23:54 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    stats_list(t_pa_collection *tpc)
{
	long		med;
	t_pa_list   *node;

	med = 0;
	tpc->min = 0;
	tpc->max = 0;
	tpc->med = 0;
	node = tpc->a->next;
	while (node)
	{
		if (node->value < tpc->min)
			tpc->min = node->value;
		if (node->value > tpc->max)
			tpc->max = node->value;
		med += node->value;
		node = node->next;
	}
	tpc->med = med / (int)(*tpc->a->size - 1);
}