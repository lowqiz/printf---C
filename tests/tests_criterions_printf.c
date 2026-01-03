/*
** EPITECH PROJECT, 2025
** tests unitaires
** File description:
** criterion
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int my_printf(const char *format, ...);

Test(my_printf, percent_d, .init = cr_redirect_stdout)
{
    int rturn = my_printf("Value : %d", 42);
    cr_assert_stdout_eq_str("Value : 42");
    cr_assert_eq(rturn, 10);
}

Test(my_printf, percent_d_isneg, .init = cr_redirect_stdout)
{
    int rturn = my_printf("Num : %d", -123);
    cr_assert_stdout_eq_str("Num : -123");
    cr_assert_eq(rturn, 10);
}

Test(my_printf, percent_d_null, .init = cr_redirect_stdout)
{
    int rturn = my_printf("Zero:%d", 0);
    cr_assert_stdout_eq_str("Zero:0");
    cr_assert_eq(rturn, 6);
}

Test(my_printf, percent_d_big, .init = cr_redirect_stdout)
{
    int rturn = my_printf("Big : %d", 11111111);
    cr_assert_stdout_eq_str("Big : 11111111");
    cr_assert_eq(rturn, 14);
}

Test(my_printf, percent_d_values, .init = cr_redirect_stdout)
{
    int rturn = my_printf("%d,%d,%d", 5, -5, 50);
    cr_assert_stdout_eq_str("5,-5,50");
    cr_assert_eq(rturn, 7);
}

/* POURCENT I*/

Test(my_printf, percent_i, .init = cr_redirect_stdout)
{
    int rturn = my_printf("Value : %i", 42);
    cr_assert_stdout_eq_str("Value : 42");
    cr_assert_eq(rturn, 10);
}

Test(my_printf, percent_i_isneg, .init = cr_redirect_stdout)
{
    int rturn = my_printf("Num : %i", -123);
    cr_assert_stdout_eq_str("Num : -123");
    cr_assert_eq(rturn, 10);
}

Test(my_printf, percent_i_null, .init = cr_redirect_stdout)
{
    int rturn = my_printf("Zero:%i", 0);
    cr_assert_stdout_eq_str("Zero:0");
    cr_assert_eq(rturn, 6);
}

Test(my_printf, percent_i_big, .init = cr_redirect_stdout)
{
    int rturn = my_printf("Big : %i", 11111111);
    cr_assert_stdout_eq_str("Big : 11111111");
    cr_assert_eq(rturn, 14);
}

Test(my_printf, percent_i_values, .init = cr_redirect_stdout)
{
    int rturn = my_printf("%i,%i,%i", 5, -5, 50);
    cr_assert_stdout_eq_str("5,-5,50");
    cr_assert_eq(rturn, 7);
}

/* POURCENT C*/

Test(my_printf, percent_c_maj, .init = cr_redirect_stdout)
{
    int rturn = my_printf("%c", 'A');
    cr_assert_stdout_eq_str("A");
    cr_assert_eq(rturn, 1);
}

Test(my_printf, percent_c_min, .init = cr_redirect_stdout)
{
    int rturn = my_printf("%c", 'z');
    cr_assert_stdout_eq_str("z");
    cr_assert_eq(rturn, 1);
}

Test(my_printf, percent_c_backslash, .init = cr_redirect_stdout)
{
    int rturn = my_printf("char [%c]", '\n');
    cr_assert_stdout_eq_str("char [\n]");
    cr_assert_eq(rturn, 8);
}

Test(my_printf, percent_c_multiple, .init = cr_redirect_stdout)
{
    int rturn = my_printf("%c-%c-%c", 'a', 'b', 'c');
    cr_assert_stdout_eq_str("a-b-c");
    cr_assert_eq(rturn, 5);
}

Test(my_printf, percent_c_ascii, .init = cr_redirect_stdout)
{
    int rturn = my_printf("Code : %c", 65);
    cr_assert_stdout_eq_str("Code : A");
    cr_assert_eq(rturn, 8);
}

/* POURCENT S*/

Test(my_printf, percent_s, .init = cr_redirect_stdout)
{
    int rturn = my_printf("Hello %s", "world");
    cr_assert_stdout_eq_str("Hello world");
    cr_assert_eq(rturn, 11);
}

Test(my_printf, percent_s_empty, .init = cr_redirect_stdout)
{
    int rturn = my_printf("Empty:%s", "");
    cr_assert_stdout_eq_str("Empty:");
    cr_assert_eq(rturn, 6);
}

Test(my_printf, percent_s_with_spaces, .init = cr_redirect_stdout)
{
    int rturn = my_printf("Archi : %s ?", "M. Volpi");
    cr_assert_stdout_eq_str("Archi : M. Volpi ?");
    cr_assert_eq(rturn, 18);
}

Test(my_printf, percent_s_multiple, .init = cr_redirect_stdout)
{
    int rturn = my_printf("%s%s", "abc", "XYZ");
    cr_assert_stdout_eq_str("abcXYZ");
    cr_assert_eq(rturn, 6);
}

/* POURCENT %*/

Test(my_printf, percent, .init = cr_redirect_stdout)
{
    int ret = my_printf("100%% ok");
    cr_assert_stdout_eq_str("100% ok");
    cr_assert_eq(ret, 7);
}

Test(my_printf, percent_only, .init = cr_redirect_stdout)
{
    int ret = my_printf("%%");
    cr_assert_stdout_eq_str("%");
    cr_assert_eq(ret, 1);
}

Test(my_printf, percent_double, .init = cr_redirect_stdout)
{
    int ret = my_printf("%%%%");
    cr_assert_stdout_eq_str("%%");
    cr_assert_eq(ret, 2);
}

Test(my_printf, percent_mixed_with_d, .init = cr_redirect_stdout)
{
    int ret = my_printf("%d%%", 42);
    cr_assert_stdout_eq_str("42%");
    cr_assert_eq(ret, 3);
}

Test(my_printf, percent_with_d, .init = cr_redirect_stdout)
{
    int ret = my_printf("%%d");
    cr_assert_stdout_eq_str("%d");
    cr_assert_eq(ret, 2);
}

/* PRECISION */

Test(my_printf, precision_1, .init = cr_redirect_stdout)
{
    int rturn = my_printf("Val : %.3d", 5);
    cr_assert_stdout_eq_str("Val : 005");
    cr_assert_eq(rturn, 9);
}

Test(my_printf, precision_2, .init = cr_redirect_stdout)
{
    int rturn = my_printf("Num : %.6d", 123);
    cr_assert_stdout_eq_str("Num : 000123");
    cr_assert_eq(rturn, 12);
}

Test(my_printf, precision_3, .init = cr_redirect_stdout)
{
    int rturn = my_printf("%.2d", 12345);
    cr_assert_stdout_eq_str("12345");
    cr_assert_eq(rturn, 5);
}

Test(my_printf, precision_4, .init = cr_redirect_stdout)
{
    int rturn = my_printf("Val : %.*d", 4, 12);
    cr_assert_stdout_eq_str("Val : 0012");
    cr_assert_eq(rturn, 10);
}

Test(my_printf, precision_5, .init = cr_redirect_stdout)
{
    int rturn = my_printf("X:%.0dY", 0);
    cr_assert_stdout_eq_str("X:0Y");
    cr_assert_eq(rturn, 4);
}

/* POURCENT x et X */

Test(my_printf, percent_x_simple, .init = cr_redirect_stdout)
{
    int rturn = my_printf("Hex : %x", 255);
    cr_assert_stdout_eq_str("Hex : ff");
    cr_assert_eq(rturn, 8);
}

Test(my_printf, percent_x_zero, .init = cr_redirect_stdout)
{
    int rturn = my_printf("Val:%x", 0);
    cr_assert_stdout_eq_str("Val:0");
    cr_assert_eq(rturn, 5);
}

Test(my_printf, percent_x_large, .init = cr_redirect_stdout)
{
    int rturn = my_printf("Big : %x", 4095);
    cr_assert_stdout_eq_str("Big : fff");
    cr_assert_eq(rturn, 9);
}

Test(my_printf, percent_X_simple, .init = cr_redirect_stdout)
{
    int rturn = my_printf("HEX : %X", 48879);
    cr_assert_stdout_eq_str("HEX : BEEF");
    cr_assert_eq(rturn, 10);
}

Test(my_printf, percent_x_multiple, .init = cr_redirect_stdout)
{
    int rturn = my_printf("%x-%X-%x", 10, 255, 4096);
    cr_assert_stdout_eq_str("a-FF-1000");
    cr_assert_eq(rturn, 9);
}

/* POURCENT o */

Test(my_printf, percent_o_simple, .init = cr_redirect_stdout)
{
    int rturn = my_printf("Oct : %o", 10);
    cr_assert_stdout_eq_str("Oct : 12");
    cr_assert_eq(rturn, 8);
}

Test(my_printf, percent_o_zero, .init = cr_redirect_stdout)
{
    int rturn = my_printf("Val:%o", 0);
    cr_assert_stdout_eq_str("Val:0");
    cr_assert_eq(rturn, 5);
}

Test(my_printf, percent_o_large, .init = cr_redirect_stdout)
{
    int rturn = my_printf("Big : %o", 4095);
    cr_assert_stdout_eq_str("Big : 7777");
    cr_assert_eq(rturn, 11);
}

Test(my_printf, percent_o_multiple, .init = cr_redirect_stdout)
{
    int rturn = my_printf("%o-%o-%o", 8, 64, 512);
    cr_assert_stdout_eq_str("10-100-1000");
    cr_assert_eq(rturn, 11);
}

Test(my_printf, percent_o_mixed, .init = cr_redirect_stdout)
{
    int rturn = my_printf("d:%d o:%o", 15, 15);
    cr_assert_stdout_eq_str("d:15 o:17");
    cr_assert_eq(rturn, 9);
}

/* POURCENT u */

Test(my_printf, percent_u, .init = cr_redirect_stdout)
{
    int rturn = my_printf("Value : %u", 42);
    cr_assert_stdout_eq_str("Value : 42");
    cr_assert_eq(rturn, 10);
}

Test(my_printf, percent_u_null, .init = cr_redirect_stdout)
{
    int rturn = my_printf("Zero:%u", 0);
    cr_assert_stdout_eq_str("Zero:0");
    cr_assert_eq(rturn, 6);
}

Test(my_printf, percent_u_big, .init = cr_redirect_stdout)
{
    int rturn = my_printf("Big : %u", 11111111);
    cr_assert_stdout_eq_str("Big : 11111111");
    cr_assert_eq(rturn, 14);
}

Test(my_printf, percent_u_values, .init = cr_redirect_stdout)
{
    int rturn = my_printf("%u,%u,%u", 5, 5, 50);
    cr_assert_stdout_eq_str("5,5,50");
    cr_assert_eq(rturn, 6);
}

/* POURCENT n

Test(my_printf, percent_n, .init = cr_redirect_stdout)
{
    int rturn = my_printf("Loris%nLoris");
    cr_assert_stdout_eq_str("LorisLoris");
    cr_assert_eq(rturn, 10);
}

Test(my_printf, percent_n_zero, .init = cr_redirect_stdout)
{
    int rturn = my_printf("Zero:%n");
    cr_assert_stdout_eq_str("Zero:");
    cr_assert_eq(rturn, 5);
}

Test(my_printf, percent_n_empty, .init = cr_redirect_stdout)
{
    int rturn = my_printf("%n");
    cr_assert_stdout_eq_str("");
    cr_assert_eq(rturn, 0);
}
*/

/* POURCENT e & E */

Test(my_printf, percent_e, .init = cr_redirect_stdout)
{
    int rturn = my_printf("%e", 42.22);
    cr_assert_stdout_eq_str("4.222000e+01");
    cr_assert_eq(rturn, 12);
}

Test(my_printf, percent_E, .init = cr_redirect_stdout)
{
    int rturn = my_printf("%E", 42.22);
    cr_assert_stdout_eq_str("4.222000E+01");
    cr_assert_eq(rturn, 12);
}

Test(my_printf, percent_e_less, .init = cr_redirect_stdout)
{
    int rturn = my_printf("%e", -42.22);
    cr_assert_stdout_eq_str("-4.222000e+01");
    cr_assert_eq(rturn, 13);
}

Test(my_printf, percent_E_less, .init = cr_redirect_stdout)
{
    int rturn = my_printf("%E", -42.22);
    cr_assert_stdout_eq_str("-4.222000E+01");
    cr_assert_eq(rturn, 13);
}

/* POURCENT f*/

Test(my_printf, percent_f, .init = cr_redirect_stdout)
{
    int rturn = my_printf("%f", 42.22);
    cr_assert_stdout_eq_str("42.220000");
    cr_assert_eq(rturn, 9);
}

Test(my_printf, percent_f_less, .init = cr_redirect_stdout)
{
    int rturn = my_printf("%f", -42.22);
    cr_assert_stdout_eq_str("-42.220000");
    cr_assert_eq(rturn, 10);
}

/* SPECIFIER */

Test(my_printf, specifier1, .init = cr_redirect_stdout)
{
    int rturn = my_printf("%lld", 42);
    cr_assert_stdout_eq_str("42");
    cr_assert_eq(rturn, 2);
}

Test(my_printf, specifier2, .init = cr_redirect_stdout)
{
    int rturn = my_printf("%hhd", 42);
    cr_assert_stdout_eq_str("42");
    cr_assert_eq(rturn, 2);
}

Test(my_printf, specifier3, .init = cr_redirect_stdout)
{
    int rturn = my_printf("%hd", 42);
    cr_assert_stdout_eq_str("42");
    cr_assert_eq(rturn, 2);
}

Test(my_printf, specifier4, .init = cr_redirect_stdout)
{
    int rturn = my_printf("%qd", 42);
    cr_assert_stdout_eq_str("42");
    cr_assert_eq(rturn, 2);
}
