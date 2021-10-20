/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:19:37 by aparolar          #+#    #+#             */
/*   Updated: 2021/10/20 10:48:43 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	free_all(t_pa_collection *tpc)
{
	t_pa_list	*node;
	t_pa_list	*tmp_node;

	free(tpc->a->size);
	free(tpc->b->size);
	node = *tpc->a->end;
	free(tpc->a->end);
	free(tpc->a->start);
	while (node)
	{
		tmp_node = node->past;
		free(node);
		node = tmp_node;
	}
	node = *tpc->b->end;
	free(tpc->b->end);
	free(tpc->b->start);
	while (node)
	{
		tmp_node = node->past;
		free(node);
		node = tmp_node;
	}
}

static void	initialize_lists(t_pa_collection *tpc)
{
	tpc->a = initialize_list(0);
	tpc->b = initialize_list(1);
	tpc->chunk = 5;
	tpc->chunk_size = tpc->chunk;
	tpc->position = 0;
}

int	main(int argc, char **argv)
{
	t_pa_collection	lists;
	int				parse_ret;

	initialize_lists(&lists);
	parse_ret = parse_args(argc, argv, lists.a);
	if (parse_ret < *lists.a->size - 1
		|| *lists.a->size == 1
		|| !check_duplicates(lists.a))
		ft_putstr_fd("Error\n", STDERR_FILENO);
	else
		start_sort(&lists);
	free_all(&lists);
	return (0);
}
