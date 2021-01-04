/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:47:26 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/04 20:36:57 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

#define STRLEN(x)	printf("	src = \"%s\": org = %d, asm = %d\n", x, (int)strlen(x), ft_strlen(x));

int		ft_strlen(char const *str);

int		main(void)
{
	puts("ft_strlen test");
	STRLEN("Hello, world!");
	return (0);
}
