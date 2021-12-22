/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:24:25 by aparolar          #+#    #+#             */
/*   Updated: 2021/10/20 10:28:37 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	push_a(t_pa_collection *tpc)
{
	ft_putstr("pa\n");
	if (!tpc->b->next)
		return (0);
	insert_at_begin(extract_node(tpc->b->next), tpc->a);
	return (1);
}

int	push_b(t_pa_collection *tpc)
{
	ft_putstr("pb\n");
	if (!tpc->a->next)
		return (0);
	insert_at_begin(extract_node(tpc->a->next), tpc->b);
	return (1);
}
