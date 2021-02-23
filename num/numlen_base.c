/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numlen_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 23:00:17 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 23:00:19 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_numlen_base(size_t num, unsigned int base)
{
	int lng;

	if (base < 2)
		return (0);
	lng = 1;
	while (num >= base)
	{
		num /= base;
		lng++;
	}
	return (lng);
}
