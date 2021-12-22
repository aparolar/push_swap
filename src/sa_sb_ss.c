/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:11:48 by aparolar          #+#    #+#             */
/*   Updated: 2021/10/20 10:29:28 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	swap_a(t_pa_collection *tpc)
{
	ft_putstr("sa\n");
	if (*tpc->a->size < 3)
		return (0);
	insert_at_begin(
		extract_node(tpc->a->next->next), tpc->a);
	return (1);
}

int	swap_b(t_pa_collection *tpc)
{
	ft_putstr("sb\n");
	if (*tpc->b->size < 3)
		return (0);
	insert_at_begin(
		extract_node(tpc->b->next->next), tpc->b);
	return (1);
}

int	swap_ab(t_pa_collection *tpc)
{
	ft_putstr("ss\n");
	if (*tpc->a->size >= 3)
		insert_at_begin(
			extract_node(tpc->a->next->next), tpc->a);
	if (*tpc->b->size >= 3)
		insert_at_begin(
			extract_node(tpc->b->next->next), tpc->b);
	return (1);
}
