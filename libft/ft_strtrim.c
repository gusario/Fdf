/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobert- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:53:09 by srobert-          #+#    #+#             */
/*   Updated: 2018/12/07 19:11:39 by srobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		len;
	int		i;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s) - 1;
	while (ft_strchr("\n\t ", s[len]))
		len--;
	len++;
	while ((i < len) && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	len = len - i;
	if (len < 0)
		len = 0;
	str = ft_strsub(s, i, len);
	if (!str)
		return (NULL);
	str[len] = '\0';
	return (str);
}
