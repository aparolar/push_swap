/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_list_sub_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 20:24:05 by aparolar          #+#    #+#             */
/*   Updated: 2021/08/25 22:11:19 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

size_t	ext_lst_get_size(t_pa_list *lst)
{
	return (*lst->size);
}

void	ext_lst_set_size(t_pa_list *lst, size_t value)
{
	*lst->size = value;
}