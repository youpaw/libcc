/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 19:15:01 by azomega           #+#    #+#             */
/*   Updated: 2020/08/19 19:15:02 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"
#include "ft_mem.h"
#include <stdlib.h>

t_graph	*ft_graph_new(char symbol, size_t index)
{
	t_graph	*graph;

	graph = (t_graph *)ft_xmalloc(sizeof(t_graph));
	graph->symbol = symbol;
	graph->index = index;
	graph->childs = NULL;
	return (graph);
}
