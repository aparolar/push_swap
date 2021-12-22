/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iputnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 21:09:18 by aparolar          #+#    #+#             */
/*   Updated: 2021/08/16 10:53:41 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iputnbr(int n)
{
	int		len;
	long	no;
	char	c;

	no = n;
	len = 0;
	if (no < 0)
	{
		ft_putchar('-');
		no = -n;
		len++;
	}
	if (no > 0)
	{
		c = (no % 10) + 48;
		no /= 10;
		len += ft_iputnbr(no);
		ft_putchar(c);
		len++;
	}
	return (len);
}
