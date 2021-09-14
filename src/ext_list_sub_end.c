/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_list_sub_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 20:41:26 by aparolar          #+#    #+#             */
/*   Updated: 2021/08/25 22:30:46 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_pa_list   *ext_lst_get_end(t_pa_list *lst)
{
	return (*lst->end);
}

void        ext_lst_set_end(t_pa_list  *lst, t_pa_list *node)
{
	*lst->end = node;
}