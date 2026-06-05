/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 11:05:36 by jangonza          #+#    #+#             */
/*   Updated: 2026/06/01 11:05:40 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&str[i]);
	return (NULL);
}

void	add_new_node(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*actual_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->content = buf;
	new_node->next = NULL;
	if (!*list)
	{
		*list = new_node;
		return ;
	}
	actual_node = *list;
	while (actual_node->next)
		actual_node = actual_node->next;
	actual_node->next = new_node;
}

int	line_len(t_list *list)
{
	int	i;
	int	len;

	len = 0;
	while (list)
	{
		i = 0;
		while (((char *)list->content)[i])
		{
			len++;
			if (((char *)list->content)[i] == '\n')
				return (len);
			i++;
		}
		list = list->next;
	}
	return (len);
}

int	has_newline(t_list *list)
{
	while (list)
	{
		if (ft_strchr(list->content, '\n'))
			return (1);
		list = list->next;
	}
	return (0);
}
