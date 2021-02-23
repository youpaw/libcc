/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_get_names.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 19:08:22 by azomega           #+#    #+#             */
/*   Updated: 2020/08/19 19:08:23 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"
#include "ft_str.h"

static const t_graph	*graph_find_entry(const t_graph *graph,
						const char *word)
{
	t_list	*found;
	t_graph	new;

	if (!word || !(*word))
		return (graph);
	new.symbol = *word;
	found = ft_lst_find(graph->childs, &new, (int (*)(const void *,
			const void *))ft_graph_cmp);
	if (!found)
		return (NULL);
	return (graph_find_entry(found->content, ++word));
}

static void				add_prefix(char **names, const char *prefix)
{
	size_t	len;

	len = ft_strlen(prefix);
	if (len)
		while (*names)
			ft_strncpy(*names++, prefix, len);
}

char					**ft_graph_get_names(const t_graph *graph,
						const char *word)
{
	const t_graph	*entry_point;
	char			**names;

	if (!graph || !(entry_point = graph_find_entry(graph, word)))
		return (NULL);
	names = ft_graph_get_suffixes(entry_point);
	add_prefix(names, word);
	return (names);
}
