/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:15:05 by aparolar          #+#    #+#             */
/*   Updated: 2021/10/24 19:21:19 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_pa_list	*initialize_list(int value)
{
	t_pa_list	*tpalist;

	tpalist = (t_pa_list *)ft_calloc(1, sizeof(t_pa_list));
	tpalist->value = value;
	tpalist->size = ft_calloc(1, sizeof(int));
	tpalist->start = ft_calloc(1, sizeof(char *));
	tpalist->end = ft_calloc(1, sizeof(char *));
	*tpalist->size = 1;
	tpalist->past = 0;
	tpalist->next = 0;
	tpalist->index = 0;
	*tpalist->start = tpalist;
	*tpalist->end = tpalist;
	return (tpalist);
}

t_pa_list	*add_new_node(t_pa_list *tpalist, int value)
{
	t_pa_list	*new;

	new = (t_pa_list *)ft_calloc(1, sizeof(t_pa_list));
	new->value = value;
	new->size = tpalist->size;
	*new->size = *new->size + 1;
	new->start = tpalist->start;
	new->end = tpalist->end;
	new->past = *tpalist->end;
	new->past->next = new;
	*new->end = new;
	return (new);
}

t_pa_list	*insert_at_begin(t_pa_list *node, t_pa_list *target)
{
	node->start = target->start;
	node->end = target->end;
	if (!(*target->start)->next)
		*target->end = node;
	node->past = *target->start;
	node->next = (*target->start)->next;
	if (node->next)
		node->next->past = node;
	(*target->start)->next = node;
	node->size = target->size;
	*node->size += 1;
	return (node);
}

t_pa_list	*insert_at_end(t_pa_list *node, t_pa_list *target)
{
	node->next = 0;
	node->start = target->start;
	node->end = target->end;
	node->past = *target->end;
	node->past->next = node;
	*target->end = node;
	node->size = target->size;
	*node->size += 1;
	return (node);
}

t_pa_list	*extract_node(t_pa_list *node)
{
	if (node == *node->end)
		*node->end = node->past;
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
