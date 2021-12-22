/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 20:01:05 by aparolar          #+#    #+#             */
/*   Updated: 2021/10/19 17:39:35 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_duplicates(t_pa_list *tpalist)
{
	t_pa_list	*tmp1;
	t_pa_list	*tmp2;

	tmp1 = tpalist->next;
	while (tmp1->next)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->value == tmp2->value)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (1);
}
