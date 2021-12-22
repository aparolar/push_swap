/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:29:09 by aparolar          #+#    #+#             */
/*   Updated: 2021/10/20 10:27:54 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	reverse_rotate_a(t_pa_collection *tpc)
{
	t_pa_list	*node;

	ft_putstr("rra\n");
	if (*tpc->a->size < 3)
		return (0);
	node = extract_node(*tpc->a->end);
	insert_at_begin(node, tpc->a);
	return (1);
}

int	reverse_rotate_b(t_pa_collection *tpc)
{
	t_pa_list	*node;

	ft_putstr("rrb\n");
	if (*tpc->b->size < 3)
		return (0);
	node = extract_node(*tpc->b->end);
	insert_at_begin(node, tpc->b);
	return (1);
}

int	reverse_rotate_ab(t_pa_collection *tpc)
{
	int			ret;
	t_pa_list	*node;

	ft_putstr("rrr\n");
	ret = 0;
	if (*tpc->a->size >= 3)
	{
		node = extract_node(*tpc->a->end);
		insert_at_begin(node, tpc->a);
		ret++;
	}
	if (*tpc->b->size >= 3)
	{
		node = extract_node(*tpc->b->end);
		insert_at_begin(node, tpc->b);
		ret++;
	}
	return (ret);
}
