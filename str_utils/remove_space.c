/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 20:52:06 by yuak              #+#    #+#             */
/*   Updated: 2025/12/12 20:52:07 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

char	*remove_space(char *str)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*new;

	if (str == NULL)
		return (NULL);
	start = 0;
	len = ft_strlen(str);
	end = len;
	while (start < len && (str[start] == ' ' || str[start] == '\t'))
		start++;
	while (end > start && (str[end - 1] == ' ' || str[end - 1] == '\t'))
		end--;
	new = malloc(end - start + 1);
	if (new == NULL)
		return (ft_putstr_fd("Malloc error!", 2), NULL);
	ft_memcpy(new, str + start, end - start);
	new[end - start] = '\0';
	return (new);
}
