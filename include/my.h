/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** my.h
*/

#include <stdarg.h>

#ifndef MYH
    #define MYH
int my_putchar(char c, int precision, int specifier);
int my_isneg(int nb);
int my_put_nbr(long long nb, int precision, int specifier);
void my_swap(int *a, int *b);
int my_putstr(char const *str, int precision, int specifier);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_show_word_array(char *const *tab);
char * my_strdup(char const *src);
char ** my_str_to_word_array(char const *str);
int send_to_str(va_list list, int precision, int specifier);
int send_to_putchar(va_list list, int precision, int specifier);
int send_to_putnbr(va_list list, int precision, int specifier);
int send_to_e(va_list list, int precision, int specifier);
int send_to_eup(va_list list, int precision, int specifier);
int send_to_f(va_list list, int precision, int specifier);
int send_to_g(va_list list, int precision, int specifier);
int send_to_gup(va_list list, int precision, int specifier);
char *int_to_str(int x);
char * double_str(double nb, int precision);
int percent_p(void *ptr, int precision, int specifier);
int send_to_percent_p(va_list list, int precision, int specifier);
int puissance_de_10(int a);
int trouverpuissance(int nb);
int print_double(double nb, int precision, int specifier);
char * double_to_str(double nb, int precision);
char * double_to_str_no_point(double nb, int precision);
int percent_e(double nb, int precision, int min, int specifier);
int my_putnbr_base(unsigned long long nb, char const *base,
    int precision, int specifier);
int percent_g(double nb, int precision, int min, int specifier);
int send_to_o(va_list list, int precision, int specifier);
int send_to_xmaj(va_list list, int precision, int specifier);
int send_to_x(va_list list, int precision, int specifier);
int send_to_u(va_list list, int precision, int specifier);
int send_to_b(va_list list, int precision, int specifier);
int errors_gestion(const char *format, va_list list, int *i, int result);
static int (* const tabf[])(va_list, int, int) = {send_to_putnbr,
    send_to_putnbr, send_to_putchar, send_to_str, send_to_percent_p, send_to_e,
    send_to_eup, send_to_f, send_to_g, send_to_gup,
    send_to_x, send_to_xmaj, send_to_o, send_to_u, send_to_b};
#endif
