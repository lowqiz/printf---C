
/*
** EPITECH PROJECT, 2025
** printf
** File description:
** printf
*/

#include <stdarg.h>
#include "include/my.h"

static int print0(int y, int result)
{
    for (; y > 0; y--)
        result += my_putchar(' ', 0, 0);
    return result;
}

static int detect_m(const char *format, va_list list, int *i)
{
    char temp[20] = {0};

    if (format[*i] == '-'){
        *i = *i + 1;
        if (format[*i + 1] == '*') {
            *i = *i + 1;
            return va_arg(list, int);
        }
        for (int y = 0; ((format[*i] >= '0' && format[*i] <= '9')
                && y < 19); y++) {
            temp[y] = format[*i];
            *i = *i + 1;
        }
        while (format[*i] == '+' || format[*i] == ' ')
            *i = *i + 1;
        return my_getnbr(temp);
    }
    return 0;
}

static int detect_flags(const char *format, int *i, int *result)
{
    int alr_written = 0;

    if (format[*i] == '+'){
        *result = *result + my_putchar('+', 0, 0);
        alr_written++;
        *i = *i + 1;
        while (format[*i] == '+' || format[*i] == ' ')
            *i = *i + 1;
    }
    if (format[*i] == ' '){
        *result = *result + my_putchar(' ', 0, 0);
        alr_written++;
        *i = *i + 1;
        while (format[*i] == '+' || format[*i] == ' ')
            *i = *i + 1;
    }
    return alr_written;
}

static int detect_flags2(const char *format, va_list list, int *i, int *result)
{
    char temp[20] = {0};
    int alr_written;

    alr_written = detect_flags(format, i, result);
    if (format[*i] == '0'){
        *i = *i + 1;
        if (format[*i + 1] == '*'){
            *i = *i + 1;
            return va_arg(list, int);
        }
        for (int y = 0; (format[*i] >= '0' && format[*i] <= '9'
                && y < 19); y++) {
            temp[y] = format[*i];
            *i = *i + 1;
        }
        while (format[*i] == '+' || format[*i] == ' ')
            *i = *i + 1;
        return my_getnbr(temp) - alr_written;
    }
    return alr_written;
}

static int detect_specifiers2(const char *format, int *i, int specifier)
{
    if (format[*i] == 'l' && format[*i + 1] != 'l' && format[*i - 1] != 'l') {
        specifier = 1;
        *i = *i + 1;
    }
    return specifier;
}

int detect_specifiers(const char *format, int *i)
{
    int specifier = 0;

    specifier = detect_specifiers2(format, i, specifier);
    if (format[*i] == 'l' && format[*i + 1] == 'l' && format[*i - 1] != 'l')
        *i = *i + 2;
    if (format[*i] == 'q')
        *i = *i + 1;
    if (format[*i] == 'h' && format[*i + 1] == 'h' && format[*i - 1] != 'h')
        *i = *i + 2;
    if (format[*i] == 'h') {
        specifier = 4;
        *i = *i + 1;
    }
    if (format[*i] == 'h' && format[*i + 1] == 'h' && format[*i - 1] != 'h') {
        specifier = 5;
        *i = *i + 2;
    }
    return specifier;
}

int detect_precision(const char *forma, va_list list, int *i, int *result)
{
    char temp[20] = {0};
    int precision = 0;

    precision = detect_flags2(forma, list, i, result);
    if (precision > 1)
        return precision;
    if (forma[*i] == '.'){
        *i = *i + 1;
        if (forma[*i] == '*'){
            *i = *i + 1;
            precision = (va_arg(list, int));
            return precision;
        }
        for (int y = 0; (forma[*i] >= '0' && forma[*i] <= '9' && y < 19); y++) {
            temp[y] = forma[*i];
            *i = *i + 1;
        }
        precision = my_getnbr(temp);
    }
    return precision;
}

int my_printf_condition(const char *format, va_list list, int result, int *i)
{
    int *a = 0;
    const char *specifier = "dicspeEfgGxXoub";
    int precision = detect_precision(format, list, i, &result);
    int tab[] = {0, 0, detect_m(format, list, i), detect_specifiers(format, i)};

    for (int j = 0; specifier[j] != '\0'; j++)
        if (format[*i] == specifier[j] || format[*i] == '.')
            tab[0] = j;
    if (format[*i] == 'n') {
        a = va_arg(list, int *);
        *a = result;
        return result;
    }
    if (format[*i] == '%')
        result += my_putchar('%', 0, 0);
    else {
        tab[1] += (*tabf[tab[0]])(list, precision, tab[3]);
        result += (tab[2] > 0) * print0(tab[2] - tab[1], result);
    }
    return result + tab[1];
}

int errors_gestion(const char *format, va_list list, int *i, int result)
{
    if (format[*i] != 'd' && format[*i] != 'i'
        && format[*i] != 'c' && format[*i] != 's'
        && format[*i] != 'p' && format[*i] != 'e'
        && format[*i] != 'E' && format[*i] != 'f'
        && format[*i] != 'g' && format[*i] != 'G'
        && format[*i] != 'x' && format[*i] != 'X'
        && format[*i] != 'o' && format[*i] != 'u'
        && format[*i] != 'b' && format[*i] != '%'
        && format[*i] != '.' && format[*i] != '-'
        && format[*i] != '+' && format[*i] != ' '
        && format[*i] != '0' && format[*i] != 'n'
        && format[*i] != 'h' && format[*i] != 'l'
        && format[*i] != 'q') {
        result += my_putchar('%', 0, 0);
        result += my_putchar(format[*i], 0, 0);
    } else if (format[*i] == '\0')
        result += my_putchar('%', 0, 0);
    else
        result = my_printf_condition(format, list, result, i);
    return result;
}

int my_printf(const char *format, ...)
{
    va_list list;
    int result = 0;

    va_start(list, format);
    for (int i = 0; i < my_strlen(format); i++) {
        if (format[i] == '%') {
            i++;
            result = errors_gestion(format, list, &i, result);
        } else
            result += my_putchar(format[i], 0, 0);
    }
    va_end(list);
    return result;
}
