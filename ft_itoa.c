/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabbenit <pabbenit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 10:41:12 by pabbenit          #+#    #+#             */
/*   Updated: 2026/10/07 14:06:59 by pabbenit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_numbers(long n)
{
	size_t	i;

	i = 1;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	fill_number(char *p, long number, size_t len, int n)
{
	while (len > 0)
	{
		len--;
		if (n < 0 && len == 0)
			p[len] = '-';
		else
		{
			p[len] = (number % 10) + '0';
			number /= 10;
		}
	}
}

char	*ft_itoa(int n)
{
	long	number;
	size_t	len;
	char	*p;

	number = n;
	if (n < 0)
		number = -number;
	len = count_numbers(number);
	if (n < 0)
		len++;
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	p[len] = '\0';
	fill_number(p, number, len, n);
	return (p);
}
