/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 10:34:21 by aparolar          #+#    #+#             */
/*   Updated: 2021/08/26 10:17:35 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_pa_list	*insert_at_begin(t_pa_list *node, t_pa_list *target)
{
	/*if (!target->start->next)
	{
		node = insert_at_end(node, target);
	}
	else
	{*/
		node->start = target->start;
		node->end = target->end;
		if (!ext_lst_get_start(target)->next)
			ext_lst_set_end(target, node);//node->end = node;
		//else
		//	ext_lst_set_end(target, //node->end = target->start->end;
		//target->end = node->end;
		node->past = ext_lst_get_start(target);
		node->next = ext_lst_get_start(target)->next;
		if (node->next)
			node->next->past = node;
		ext_lst_get_start(target)->next = node;
		node->size = target->size;
		*node->size += 1;
	//}
	return (node);
}

t_pa_list	*insert_at_end(t_pa_list *node, t_pa_list *target)
{
	node->next = 0;
	node->start = target->start;
	node->end = target->end;
	node->past = ext_lst_get_end(target);
	node->past->next = node;
	ext_lst_set_end(target, node);
	node->size = target->size;
	*node->size += 1;
	return (node);
}

t_pa_list	*extract_node(t_pa_list *node)
{
	if (node == ext_lst_get_end(node))
		ext_lst_set_end(node, node->past);
	if (node->next)
		node->next->past = node->past;
	node->past->next = node->next;
	*node->size -= 1;
	node->next = 0;
	node->end = 0;
	node->past = 0;
	node->start = 0;
	node->size = 0;
	return (node);
}