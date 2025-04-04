/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:10:54 by lpaula-n          #+#    #+#             */
/*   Updated: 2024/11/03 04:47:54 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, const char *s2)
{
	char	*join;
	size_t	length;

	if (!s1 || !s2)
		return (0);
	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = malloc(sizeof(char) * (length + 1));
	if (!join)
		return (0);
	ft_strlcpy(join, s1, length + 1);
	ft_strlcat(join, s2, length + 1);
	return (join);
}
