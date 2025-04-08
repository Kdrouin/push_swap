/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadrouin <kadrouin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 03:32:39 by kadrouin          #+#    #+#             */
/*   Updated: 2025/04/06 18:37:44 by kadrouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdbool.h>

int		ft_strlen(char *str);
bool	is_digit(char c);
int		ft_search_format(char c, va_list args);
int		ft_printf(const char *format, ...);
int		ft_putstr(const char *c);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putunbr(unsigned int n);
int		ft_putptr(va_list args, int count);
int		ft_putnbr_base(unsigned long long n, char *base);

#endif
