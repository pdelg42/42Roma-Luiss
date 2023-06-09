/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:31:17 by aperrone          #+#    #+#             */
/*   Updated: 2023/03/24 06:56:52 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>
# include <limits.h>
# include <unistd.h>
# include <signal.h>
# include <dirent.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "listft.h"

long long	a_(char *str, int len_base);
int			ft_isdigit(char c);
int			ft_strcmp(char *s1, char *s2);
char		*ft_itoa(int n);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(const char *s1, const char *s2);
void		freestr(char *input);
size_t		ft_strlen(const char *str);
void		freematrix(char **splitted, int i);
char		*ft_strdup(const char *s1);
int			row_counter(char **matrix);
char		*ft_strchr(const char *s, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_isalpha(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
void		white(void);
void		red(void);
void		purple(void);
char		*ft_strtrim(const char *s1, const char *set);
#endif