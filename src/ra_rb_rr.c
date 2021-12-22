/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:29:09 by aparolar          #+#    #+#             */
/*   Updated: 2021/10/19 17:48:07 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	rotate_a(t_pa_collection *tpc)
{
	t_pa_list	*node;

	ft_putstr("ra\n");
	if (*tpc->a->size < 3)
		return (0);
	node = extract_node(tpc->a->next);
	insert_at_end(node, tpc->a);
	return (1);
}

int	rotate_b(t_pa_collection *tpc)
{
	t_pa_list	*node;

	ft_putstr("rb\n");
	if (*tpc->b->size < 3)
		return (0);
	node = extract_node(tpc->b->next);
	insert_at_end(node, tpc->b);
	return (1);
}

int	rotate_ab(t_pa_collection *tpc)
{
	int			ret;
	t_pa_list	*node;

	ft_putstr("rr\n");
	ret = 0;
	if (*tpc->a->size >= 3)
	{
		node = extract_node(tpc->a->next);
		insert_at_end(node, tpc->a);
		ret++;
	}
	if (*tpc->b->size >= 3)
	{
		node = extract_node(tpc->b->next);
		insert_at_end(node, tpc->b);
		ret++;
	}
	return (ret);
}
