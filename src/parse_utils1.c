/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 10:59:09 by aparolar          #+#    #+#             */
/*   Updated: 2021/12/22 11:52:42 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../lib/libft/libft.h"

static void	assign_indexs(t_pa_list *lst)
{
	t_pa_list	*node;
	int			index;
	int			value;

	index = 0;
	value = INT_MIN;
	while (index++ < *lst->size)
	{
		node = lst->next;
		while (node)
		{
			if (find_min_value(node, value) == node->value)
			{
				node->index = index;
				value = node->value;
				break ;
			}
			node = node->next;
		}
	}
}

static char	*get_one_line_args(int argc, char **argv)
{
	char	*tmp;
	char	*ret;
	int		i;

	i = 2;
	ret = ft_strdup(argv[1]);
	while (i < argc)
	{
		tmp = ret;
		ret = ft_strjoin(ret, " ");
		free(tmp);
		tmp = ret;
		ret = ft_strjoin(ret, argv[i]);
		free(tmp);
		i++;
	}
	return (ret);
}

static char	*is_number(char *str)
{
	int	digit;

	digit = 0;
	while (*str)
	{
		if (*str == '-' && !ft_isdigit(*(str + 1)))
			break ;
		else if (*str == '-' && ft_isdigit(*(str + 1)))
			str = str;
		else if (ft_isdigit(*str))
			digit++;
		else if (*str == ' ')
			break ;
		else
		{	
			digit = 0;
			break ;
		}
		str++;
	}
	if (digit > 0)
		return (str);
	return (0);
}

static int	is_valid_number(char *str)
{
	char	*end;
	char	*svalue;

	end = str;
	while (*end && *end != ' ')
		end++;
	svalue = ft_strrem(str, 0, end - str);
	if (ft_is_valid_aint(svalue))
	{
		free(svalue);
		return (1);
	}
	else
	{
		free(svalue);
		return (0);
	}
}

static int	parse_arg(char *args, t_pa_list *tpalist)
{
	char	*value;
	long	number;
	int		ret;

	ret = 0;
	while (*args)
	{
		if (*args == ' ')
			args++;
		else
		{
			value = is_number(args);
			number = ft_atol(args);
			if (is_valid_number(args))// value && number >= INT_MIN && number <= INT_MAX)
			{
				if (tpalist)
					add_new_node(tpalist, (int)number);
				args = value;
				ret++;
			}
			else
				return (0);
		}
	}
	return (ret);
}

size_t	parse_args(int argc, char **argv, t_pa_list *tpalist)
{
	int		ret;
	char	*args;

	ret = 0;
	if (argc < 2)
		return (ret);
	else
	{
		args = get_one_line_args(argc, argv);
		ret = parse_arg(args, tpalist);
		assign_indexs(tpalist);
		free(args);
		return (ret);
	}
}
