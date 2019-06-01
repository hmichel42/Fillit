/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 17:20:00 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 18:59:06 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*delete;

	delete = *alst;
	while (delete)
	{
		del(delete->content, delete->content_size);
		free(delete);
		delete = delete->next;
	}
	*alst = NULL;
}
