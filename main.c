/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:47:26 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/07 20:20:25 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char* dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
char	*ft_strdup(const char *s1);

int		test_strlen(char const *str)
{
	size_t	i, j;

	i = strlen(str);
	j = ft_strlen(str);
	if (i == j)
		printf("\033[32m[OK]\033[39m ");
	else
		printf("\033[31m[NG]\033[39m ");
	return ((int)(!(i == j)));
}

int		test_strcpy(char *dst, const char *src)
{
	char	*ret;

	ret = ft_strcpy(dst, src);
	if (!strcmp(dst, src) && !strcmp(ret, src))
		printf("\033[32m[OK]\033[39m ");
	else
	{
		printf("\033[31m[NG]\033[39m ");
		return (1);
	}
	return (0);
}

int		test_strcmp(const char *s1, const char *s2)
{
	int		org, ft;

	org = strcmp(s1, s2);
	ft = ft_strcmp(s1, s2);
	if (org == ft)
		printf("\033[32m[OK]\033[39m ");
	else
		printf("\033[31m[NG]\033[39m ");
	return ((int)(org - ft));
}

int		main(void)
{
	char	*src[6] = {"foo", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris tristique dui at tellus blandit vulputate. In hac habitasse platea dictumst. In a nibh", "", "\n", "\n\n", "safwe11234{ewrq1231"};
	char	*s2[6] = {"bar", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris tristique dui at tellus blandit vulputate. In hac habitasse platea dictumst. In a nibh", "", "\n", "\n\n", "safwe11234{ewrq12"};
	char	buf[300];
	int		ret[6];

	/* STRLEN TEST */
	puts("--------------------------------------------------------------------------------");
	puts("FT_STRLEN TEST :");
	for (int i = 0; i < 6; i++)
		ret[i] = test_strlen((const char*)src[i]);
	puts("");
	for (int i = 0; i < 6; i++)
		if (ret[i])
			printf("NG: %s\n", src[i]);

	/* STRCPY TEST */
	puts("--------------------------------------------------------------------------------");
	puts("FT_STRCPY TEST :");
	for (int i = 0; i < 6; i++)
		ret[i] = test_strcpy(buf, (const char*)src[i]);
	puts("");
	for (int i = 0; i < 6; i++)
		if (ret[i])
			printf("NG: %s\n", src[i]);

	/* STRCMP TEST */
	puts("--------------------------------------------------------------------------------");
	puts("FT_STRCMP TEST :");
	for (int i = 0; i < 6; i++)
		ret[i] = test_strcmp((const char*)src[i], (const char*)s2[i]);
	puts("");
	for (int i = 0; i < 6; i++)
		if (ret[i])
			printf("NG: %s\n", src[i]);

	puts("--------------------------------------------------------------------------------");

	return (0);
}
