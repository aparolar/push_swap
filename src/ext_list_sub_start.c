/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_list_sub_start.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 20:30:46 by aparolar          #+#    #+#             */
/*   Updated: 2021/08/25 22:27:14 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_pa_list	*ext_lst_get_start(t_pa_list *lst)
{
	return (*lst->start);
}

void		ext_lst_set_start(t_pa_list *lst, t_pa_list *node)
{
	*lst->start = node;
}
