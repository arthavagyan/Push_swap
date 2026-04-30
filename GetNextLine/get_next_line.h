/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyeghiaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 19:09:06 by tyeghiaz          #+#    #+#             */
/*   Updated: 2026/03/26 20:08:18 by tyeghiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

size_t	ft_strlcat(char *dst, char *src, size_t size);

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr( char *s, int c);
char	*ft_read_and_fill_reminder(int fd, char *reminder);
char	*ft_extract_line(char *reminder);
char	*ft_clean_reminder(char *reminder);
char	*get_next_line(int fd);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif
