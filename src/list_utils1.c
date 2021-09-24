/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:15:05 by aparolar          #+#    #+#             */
/*   Updated: 2021/09/20 21:01:03 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_pa_list   *initialize_list(int value)
{
	t_pa_list   *tpalist;

	tpalist = (t_pa_list *)ft_calloc(1, sizeof(t_pa_list));
	tpalist->value = value;
	tpalist->size = ft_calloc(1, sizeof(size_t));
	tpalist->start = ft_calloc(1, sizeof(char *));
	tpalist->end = ft_calloc(1, sizeof(char *));
	*tpalist->size = 1;
	tpalist->past = 0;
	tpalist->next = 0;
	*tpalist->start = tpalist;
	*tpalist->end = tpalist;
	return (tpalist);
}

t_pa_list   *add_new_node(t_pa_list *tpalist, int value)
{
	t_pa_list   *new;

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
/*
t_pa_list	*remove_node(t_pa_list *tpalist)
{
	t_pa_list	*tmp;

	tmp = tpalist;
	if (*tpalist->size > 1)
	{
		if (tpalist->end == tpalist)
			tpalist->past->end = tpalist->past;
		if (tpalist->start == tpalist)
			tpalist->next->start = tpalist->next;
		if (!tpalist->next)
			tpalist->next->past = tpalist->past;
		if (!tpalist->past)
			tpalist->past->next = tpalist->next;
		*tpalist->size -= 1;
		tpalist = tpalist->start;
		free(tmp);
	}
	else
	{
		free(tpalist->size);
		free(tpalist);
		tpalist = 0;
	}
	return (tpalist);
}*/