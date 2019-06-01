/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 16:24:46 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 23:03:25 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*elem;

	if (!(elem = ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (content != NULL && content_size != 0)
	{
		if (!(elem->content = ft_memalloc((content_size))))
			return (NULL);
		ft_memcpy((elem->content), content, content_size);
		elem->content_size = content_size;
	}
	else
	{
		elem->content = NULL;
		elem->content_size = 0;
	}
	elem->next = NULL;
	return (elem);
}
