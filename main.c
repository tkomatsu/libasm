/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:47:26 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/08 16:15:30 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

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

int		test_write(int fd, const void *buf, size_t nbyte)
{
	ssize_t	org, ft;
	int		err;

	write(fd, "***************\n", 16);
	write(fd, "org = ", 7);
	org = write(fd, buf, nbyte);
	err = errno;
	write(fd, "\nft = ", 6);
	ft = ft_write(fd, buf, nbyte);
	write(fd, "\n", 1);
	if (org == ft && err == errno)
		printf("\033[32m[OK]\033[39m ");
	else
		printf("\033[31m[NG]\033[39m ");
	return ((int)(org - ft));
}

int		test_read(int fd_org, int fd_ft)
{
	ssize_t	org, ft;
	char	buf1[100], buf2[100];
	int		nbyte = 100;

	org = read(fd_org, buf1, nbyte);
	ft = ft_read(fd_ft, buf2, nbyte);
	if (org == ft && !memcmp(buf1, buf2, nbyte))
		printf("\033[32m[OK]\033[39m ");
	else
		printf("\033[31m[NG]\033[39m ");
	return ((int)(org - ft));
}

int		test_strdup(const char *src)
{
	char	*dst1, *dst2;
	int		err;

	dst1 = strdup(src);
	err = errno;
	dst2 = ft_strdup(src);
	if (!strcmp(dst1, dst2) && err == errno)
	{
		printf("\033[32m[OK]\033[39m ");
		return (0);
	}
	else
	{
		printf("\033[31m[NG]\033[39m ");
		return (1);
	}
}

int		main(void)
{
	char	*src[6] = {"foo", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris tristique dui at tellus blandit vulputate. In hac habitasse platea dictumst. In a nibh", "", "\n", "\n\n", "safwe11234{ewrq1231"};
	char	*s2[6] = {"bar", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris tristique dui at tellus blandit vulputate. In hac habitasse platea dictumst. In a nibh", "", "\n", "\n\n", "safwe11234{ewrq12"};
	char	buf[300];
	int		ret[10];
	int		fd, fd_ft;

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

	/* WRITE TEST */
	puts("--------------------------------------------------------------------------------");
	puts("FT_WRITE TEST :");
	fd = open("./write.log" ,O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	for (int i = 0; i < 6; i++)
		ret[i] = test_write(fd, (const void*)src[i], strlen(src[i]));
	ret[6] = test_write(1345, (const void*)src[0], strlen(src[0]));
	puts("");
	for (int i = 0; i < 6; i++)
		if (ret[i])
			printf("NG: %s\n", src[i]);
	close(fd);

	/* READ TEST */
	puts("--------------------------------------------------------------------------------");
	puts("FT_READ TEST :");
	fd = open("./write.log" ,O_RDONLY);
	fd_ft = open("./write.log" ,O_RDONLY);
	ret[0] = test_read(fd, fd_ft);
	ret[1] = test_read(123, 123);
	close(fd);
	close(fd_ft);
	puts("");

	/* STRDUP TEST */
	puts("--------------------------------------------------------------------------------");
	puts("FT_STRDUP TEST :");
	for (int i = 0; i < 6; i++)
		ret[i] = test_strdup((const char*)src[i]);
	puts("");
	for (int i = 0; i < 6; i++)
		if (ret[i])
			printf("NG: %s\n", src[i]);

	puts("--------------------------------------------------------------------------------");

	return (0);
}
