/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabierma <dabierma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:55:29 by dabierma          #+#    #+#             */
/*   Updated: 2025/03/17 13:55:30 by dabierma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_strncmp(char *s1, char *s2, int n)
{
    if (s1 == NULL || s2 == NULL || n <= 0)
        return(0);
    while(*s1 == *s2 && n > 0 && *s1 != '\0')
    {
        s1++;
        s2++;
        n--;
    }
    return (*s1 - *s2);
}
void putstr_fd(char *str, int fd)
{
    if (str == NULL || fd < 0)
        return ;

    if (*str != '\0')
    {
        write(fd, str, 1);
        putstr_fd(str + 1, fd);
    }
}