/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:14:45 by tstrassb          #+#    #+#             */
/*   Updated: 2022/12/19 13:14:45 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstapply(t_list *l, t_list *s,
	void *(*f)(void *), void (*d)(void *))
{
	if (l)
	{
		s = ft_lstnew(f(l->content));
		if (!s)
		{
			ft_lstclear(&s, d);
			return (NULL);
		}
		s->next = ft_lstapply(l->next, s->next, f, d);
	}
	return (s);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;

	start = NULL;
	start = ft_lstapply(lst, start, f, del);
	return (start);
}