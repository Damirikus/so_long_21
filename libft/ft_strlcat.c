/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdominqu <sdominqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:54:36 by sdominqu          #+#    #+#             */
/*   Updated: 2021/07/27 18:54:39 by sdominqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	len_src;
	size_t	len_dst;

	len_dst = ft_strlen(dest);
	len_src = ft_strlen((char *)src);
	if (n != 0)
	{
		if (n < len_dst)
			return (len_src + n);
		else
		{
			len_src = ft_strlcpy(dest + len_dst, src, n - len_dst);
			return (len_src + len_dst);
		}
	}
	return (len_src);
}
