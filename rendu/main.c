/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmalassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:54:50 by vmalassi          #+#    #+#             */
/*   Updated: 2023/03/21 17:54:52 by vmalassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char *argv[])
{
	int	i;

	if (argc < 2)
	{
		solve_inputs();
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			solve_file(argv[i]);
			if (i++ < argc - 1)
				put_str("\n");
		}
	}
	return (0);
}
