/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 05:28:44 by aparolar          #+#    #+#             */
/*   Updated: 2021/08/16 10:54:40 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *str)
{
	char	*pstr;
	int		len;

	len = 0;
	pstr = (char *)str;
	if (pstr)
	{
		while (*pstr)
		{
			if (write(1, pstr, 1))
				len++;
			pstr++;
		}
	}
	return (len);
}
