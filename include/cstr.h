/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:14:01 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/19 04:38:42 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CSTR_H
# define CSTR_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <stdint.h>
# include "structs.h"
# include "ctype.h"
# include "alloc.h"
# include "mem.h"

int				ft_tolower(int c);

int				ft_toupper(int c);

size_t			ft_strlen(const char *restrict str)\
					__attribute__((__nonnull__(1)));

char			*ft_strdup(const char *str)\
					__attribute__((__nonnull__(1)));

char			*ft_strchr(const char *haystack, int needle)\
					__attribute__((__nonnull__(1)));

char			*ft_strchr_small(const char *haystack, int needle)\
					__attribute__((__nonnull__(1)));

char			*ft_strrchr(const char *haystack, int needle)\
					__attribute__((__nonnull__(1)));

size_t			ft_strlcpy(char *dest, const char *src, size_t n)\
					__attribute__((__nonnull__(1, 2)));

size_t			ft_strlcat(char *dest, const char *src, size_t n)\
					__attribute__((__nonnull__(1, 2)));

int				ft_strncmp(const char *s1, const char *s2, size_t n)\
					__attribute__((__nonnull__(1, 2)));

char			*ft_strnstr(const char *haystack, const char *needle,
					size_t n)\
					__attribute__((__nonnull__(1, 2)));

char			*ft_strtrim(const char *str, const char *set)\
					__attribute__((__nonnull__(1, 2)));

char			*ft_strmapi(char const *str, char (*f)(unsigned int, char))\
					__attribute__((__nonnull__(1, 2)));

void			ft_striteri(char *str, void (*f)(unsigned int, char *))\
					__attribute__((__nonnull__(1, 2)));

char			*ft_strjoin(const char *s1, const char *s2)\
					__attribute__((__nonnull__(1, 2)));

char			*ft_substr(const char *s, unsigned int start, size_t len)\
					__attribute__((__nonnull__(1)));

char			**ft_split(const char *str, char set)\
					__attribute__((__nonnull__(1)));

int				ft_strcmp(const char *a, const char *b)\
					__attribute__((__nonnull__(1, 2)));

t_u8			ft_isnumeric(const char *__restrict__ s)\
					__attribute__((__nonnull__(1)));

int				ft_s_isblob(char *s)\
					__attribute__((__nonnull__(1)));

#endif
