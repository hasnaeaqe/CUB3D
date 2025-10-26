/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haqajjef <haqajjef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 11:37:13 by haqajjef          #+#    #+#             */
/*   Updated: 2025/10/26 09:55:04 by haqajjef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ft_free(t_garbage **list, char *type)
{
	t_garbage	*tmp;

	if (ft_strncmp(type, "FREE", 4) == 0)
	{
		while (*list)
		{
			tmp = (*list)->next;
			free((*list)->ptr);
			(*list)->ptr = NULL;
			free(*list);
			*list = NULL;
			(*list) = tmp;
		}
		list = NULL;
	}
}

t_garbage	*new_node(void *s)
{
	t_garbage	*new;

	new = malloc(sizeof(t_garbage));
	if (!new)
		return (NULL);
	new->ptr = s;
	new->next = NULL;
	return (new);
}

void	add_back_list(t_garbage **list, t_garbage *new)
{
	t_garbage	*node;

	if (!list || !new)
		return ;
	if (!(*list))
	{
		*list = new;
		return ;
	}
	node = *list;
	while (node->next)
		node = node->next;
	if (node)
		node->next = new;
}

void	*ft_malloc(size_t size, char *type)
{
	static t_garbage	*list;
	t_garbage			*node;
	void				*ptr;

	ptr = NULL;
	if (ft_strncmp(type, "MALLOC", 4) == 0)
	{
		ptr = malloc(size);
		if (!ptr)
			exit(1);
		node = new_node(ptr);
		add_back_list(&list, node);
	}
	else
		ft_free(&list, type);
	return (ptr);
}
