/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:58:18 by aparolar          #+#    #+#             */
/*   Updated: 2021/09/18 09:44:07 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_lists(t_pa_collection *tpc)
{
	t_pa_list	*node1;
	t_pa_list	*node2;

	node1 = tpc->a->next;
	node2 = tpc->b->next;
	printf("\n-------------------------------------------------\n");
	printf("%10s %10s %10s\n\n", "Lists", "a", "b");
	while (node1 || node2)
	{
		printf("%10s", " ");
		if (node1)
		{
			printf("%10d", node1->value);
			node1 = node1->next;
		}
		else
			printf("%10s", " ");
		if (node2)
		{
			printf("%10d", node2->value);
			node2 = node2->next;
		}
		else
			printf("%10s", " ");
		printf("\n");
	}
	printf("-------------------------------------------------\n");
}

void	start_sort(t_pa_collection *collection)
{
	if (!is_sorted(collection->a))
		chunk_quick_sort(collection);
		//quikly_sort(collection);
	if (!is_sorted(collection->a))
		jamie_sort(collection);
	//print_lists(collection);
}