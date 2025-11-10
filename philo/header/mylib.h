/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megardes <megardes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:59:39 by megardes          #+#    #+#             */
/*   Updated: 2025/11/08 21:37:32 by megardes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLIB_H
# define MYLIB_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef unsigned char	t_uc;

void	*not_calloc(size_t nmemb, size_t size);
void	not_bzero(void *s, size_t n);
int		not_atoi(char *num);
void	ft_put_str(char *str, int fd);
void	ft_put_endl(char *str, int fd);
void	ft_putnbr(int i, int fd);
int		ft_isdigit(char *in);

#endif