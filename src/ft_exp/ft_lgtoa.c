/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lgtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 10:21:45 by geargenc          #+#    #+#             */
/*   Updated: 2022/08/31 13:02:11 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char		*ft_lgtoa(long n)
{
	char	*result;
	int		i;
	long	power;

	power = 1;
	i = (n < 0) ? 2 : 1;
	while (n / power >= 10 || n / power <= -10)
	{
		power *= 10;
		i++;
	}
	if (!(result = (char *)ft_malloc_exit(i + 1)))
		return (NULL);
	if (n < 0)
		result[0] = '-';
	i = (n < 0) ? 1 : 0;
	while (power != 0)
	{
		result[i] = n / power % 10 * ((n < 0) ? -1 : 1) + '0';
		power /= 10;
		i++;
	}
	result[i] = '\0';
	return (result);
}
