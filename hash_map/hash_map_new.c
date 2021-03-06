/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_map_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:48:23 by dbutterw          #+#    #+#             */
/*   Updated: 2021/02/23 16:48:23 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash_map.h"
#include "ft_mem.h"

t_hash_map	*ft_hash_map_new(size_t n_buckets, \
	size_t (*hasher)(const void *), \
	int (*cmp)(const void *, const void *), \
	void (*del)(t_hash_pair *))
{
	t_hash_map	*table;
	size_t		cnt;

	if (!hasher || !cmp || !n_buckets)
		return (NULL);
	table = ft_xmalloc(sizeof(t_hash_map));
	table->buckets = (t_list **)ft_xmalloc(sizeof(t_list *) * n_buckets);
	cnt = 0;
	while (cnt < n_buckets)
		table->buckets[cnt++] = NULL;
	table->hasher = hasher;
	table->cmp = cmp;
	table->del = del;
	table->buckets_size = n_buckets;
	return (table);
}
