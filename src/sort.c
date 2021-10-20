/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:58:18 by aparolar          #+#    #+#             */
/*   Updated: 2021/10/19 17:41:33 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	start_sort(t_pa_collection *collection)
{
	if (*collection->a->size == 3)
		two_sort_a(collection);
	else if (*collection->a->size == 4)
		three_sort_a(collection);
	else if (*collection->a->size > 4 && *collection->a->size < 10)
		five_sort_a(collection);
	else if (!is_sorted(collection->a))
		radix_sort(collection);
}
