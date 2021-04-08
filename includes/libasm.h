/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 17:02:52 by ayzapata          #+#    #+#             */
/*   Updated: 2021/02/05 09:44:07 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

/*
**                  ID      ARG1        ARG2    ARG3    ARG4    ARG5    ARG5
**  syscall        rax     rdi         rsi     rdx     r10     r8      r9  
**  sys_read       0       fd          &buff   len
**  sys_write      1       fd          &buff   len
**  sys_open       2       file        flags   mode
**  sys_close      3       fd
**  sys_exit       60      nbr error code

**  fd = 0: stdin, 1: stdout, 2: stderror
*/

size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *dest, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_write(int fd, const void *buf, size_t count);;
ssize_t		ft_read(int fd, void *buf, size_t count);
char		*ft_strdup(const char *src);

#endif