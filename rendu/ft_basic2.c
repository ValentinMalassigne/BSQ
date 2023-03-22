/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmalassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:35:05 by vmalassi          #+#    #+#             */
/*   Updated: 2023/03/22 16:35:06 by vmalassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	length_until_char(char *str, char c)
{
	int	length;

	length = 0;
	while (str[length] && str[length] != c)
		length++;
	return (length);
}

void	put_str(char *str)
{
	while (*str)
		write(1, str++, 1);
}
