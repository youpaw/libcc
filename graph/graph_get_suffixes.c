/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_get_suffixes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:48:47 by dbutterw          #+#    #+#             */
/*   Updated: 2021/02/23 16:48:47 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"
#include "ft_mem.h"

static size_t	graph_get_size(const t_graph *graph)
{
	size_t	size;
	t_list	*iter;

	size = 0;
	if (graph->symbol == '\0' && graph->index > 0)
		size++;
	iter = graph->childs;
	while (iter)
	{
		size += graph_get_size(iter->content);
		iter = iter->next;
	}
	return (size);
}

static char	**alloc_arr(size_t size)
{
	char	**ret;

	ret = (char **) ft_xmalloc(sizeof(char *) * (size + 1));
	ret[size] = NULL;
	return (ret);
}

static char	**mv_arr(char **dest, t_graph *graph)
{
	char	**suf;
	char	**head;

	suf = ft_graph_get_suffixes(graph);
	head = suf;
	while (*suf)
		*dest++ = *suf++;
	free(head);
	return (dest);
}

char	**ft_graph_get_suffixes(const t_graph *graph)
{
	char	**head;
	char	**ret;
	size_t	size;
	t_list	*iter;

	if (graph->symbol == '\0' && graph->index > 0)
	{
		ret = alloc_arr(1);
		ret[0] = (char *)ft_xmalloc(sizeof(char) * graph->index);
		ret[0][graph->index - 1] = '\0';
		return (ret);
	}
	ret = alloc_arr(graph_get_size(graph));
	head = ret;
	iter = graph->childs;
	while (iter)
	{
		ret = mv_arr(ret, iter->content);
		iter = iter->next;
	}
	size = graph_get_size(graph);
	if (graph->index > 0)
		while (size-- > 0)
			head[size][graph->index - 1] = graph->symbol;
	return (head);
}
