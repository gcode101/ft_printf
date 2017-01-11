/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 13:26:05 by gcortina          #+#    #+#             */
/*   Updated: 2016/11/17 13:26:08 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <wchar.h>

int		ft_printf(const char * restrict format, ...);
void	ft_putchar(char c);
void	ft_putendl(char const *s);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr(char const *str);
int		str_conv(char *format, va_list args, int newline, char cap_s);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
char	*ft_itoa(int nb);
void	ft_memdel(void **ap);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
void	*ft_strnew(size_t size);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
int		format_reader(char **format, va_list args);
void	handle_width(char *format, char **arg, int size);
char	*get_flags(char *format);
char	*get_len_flag(char *format);
int		get_pre(char *format);
void	*ft_memset(void *b, int c, size_t len);
int		ft_isascii(int c);
void	ft_bzero(void *s, size_t n);
void	ft_putwchar(wchar_t chr);
int		handle_wchar(char *len_flag, va_list args, int newline, char *format);
int		handle_wchar_str(char *len_flag, va_list args, int newline, char *format);
int		get_width(char *format);
void	handle_flags(char *format, char *flags, char **arg, int num);
int		chr_conv(char *format, va_list args, int newline, char cap_c);
wchar_t	*ft_wstrsub(wchar_t *s, unsigned int start, size_t len);
int		ft_wstrlen(wchar_t *str);
void	*ft_wmemset(wchar_t *b, int c, size_t len);
void	handle_wchar_width(char *format, wchar_t **arg);
void	handle_wflags(char *flags, wchar_t **arg);
wchar_t	*ft_wstrdup(wchar_t *src);
int		decimal_conv(char *format, va_list args, int newline, char *long_flag);
void	ft_putnbr(int nb);
char	*ft_strcpy(char *dest, const char *src);
void	zero_flag(char **arg, int num, int space_flag);
char	*handle_dec_lenflag(char *len_flag, va_list args);
char	*ft_itoa_base(long long value, int base);
int		octal_conv(char *format, va_list args, int newline, char *long_flag);
void	modify_arg(char *format, char *flags, char **arg, int num);
int		hex_conv(char *format, va_list args, int newline, char cap_x);
int		unsigned_conv(char *format, va_list args, int newline, char *long_flag);
char	*handle_un_lenflag(char *len_flag, va_list args, int base);
int		ft_toupper(int c);
int		chr_count(char *str, char chr);
int		wchr_len(wchar_t chr);
int		shift_right(char *str, int num);
int		special_conv(char *format, int newline);
int		is_valid(char c);
void	space_flag(char **arg, int precision);
int		print_chr(char c);
int		end_of_format(char *format, int i);
int		percent_signs(const char * restrict str);
char	get_char(int index);
char 	*unsigned_itoa_short(unsigned short int value, int base);
#endif
