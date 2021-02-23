/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strequ.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:46:25 by dbutterw          #+#    #+#             */
/*   Updated: 2021/02/23 16:46:25 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
		if (ft_strcmp(s1, s2) == 0)
			return (1);
	if (!s1 && !s2)
		return (1);
	return (0);
}
