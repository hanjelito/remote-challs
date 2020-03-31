/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hv_rgb2hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-gon <juan-gon@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 09:42:16 by juan-gon          #+#    #+#             */
/*   Updated: 2020/03/31 11:26:09 by juan-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

size_t	ft_strlen(const char *c)
{
	int count;

	count = 0;
	while (c[count])
		count++;
	return (count);
}
char	get_digit(int num)
{
	if (num < 10)
		return ('0' + num);
	else
		return ('a' + num - 10);
}
char	*ft_itoa_base(unsigned int n, int base)
{
	char			*str;
	unsigned int	size;
	unsigned int	num;

	num = n;
	size = 1;
	while (num >= (unsigned int)base)
	{
		size++;
		num /= base;
	}
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	num = n;
	while (size--)
	{
		str[size] = get_digit(num % base);
		num = num / base;
	}
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	len;
	size_t	count;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2));
	if (!(dst = (char *)malloc(sizeof(char)
					* (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	count = 0;
	while (count < len)
	{
		if (count < (len - ft_strlen(s2)))
			dst[count] = s1[count];
		else
			dst[count] = s2[count - ft_strlen(s1)];
		count++;
	}
	dst[count] = '\0';
	return (dst);
}

char *hex(int dat)
{

	long int i;
	char *str;

	i = dat;
	str = ft_itoa_base(i, 16);
    if(dat < 10)
        return ft_strjoin("0", str);
    return str;
}

char *hv_rgb2hex(int r, int g, int b)
{
    return ft_strjoin("#", ft_strjoin(hex(r),
        ft_strjoin(hex(g),hex(b))));
}