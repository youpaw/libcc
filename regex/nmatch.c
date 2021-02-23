/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmatch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:35:38 by dbutterw          #+#    #+#             */
/*   Updated: 2020/01/06 14:39:22 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_nmatch(char *s1, char *s2)
{
	if (!*s1 && !*s2)
		return (1);
	if (*s1 && *s2 == '*')
		return (ft_nmatch(s1 + 1, s2) + ft_nmatch(s1, s2 + 1));
	if (!*s1 && *s2 == '*')
		return (ft_nmatch(s1, s2 + 1));
	if (*s1 == *s2 && *s1 && *s2)
		return (ft_nmatch(s1 + 1, s2 + 1));
	return (0);
}
