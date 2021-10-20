/*
** EPITECH PROJECT, 2021
** test_my_printf.c
** File description:
** test for the fonction my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void my_printf(char *fmt, ...);

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, simple_string, .init = redirect_all_std)
{
    my_printf("Hello World");
    cr_assert_stdout_eq_str("Hello World");
}

Test(my_printf, flags_for_string, .init = redirect_all_std)
{
    my_printf("%s", "YES Life");
    cr_assert_stdout_eq_str("YES Life");
}

Test(my_printf, flags_for_digit, .init = redirect_all_std)
{
    my_printf("%d", 42);
    cr_assert_stdout_eq_str("42");
}

Test(my_printf, flags_for_char, .init = redirect_all_std)
{
    my_printf("%c", 'T');
    cr_assert_stdout_eq_str("T");
}

Test(my_printf, create_new_line, .init = redirect_all_std)
{
    my_printf("Bonjour\n");
    cr_assert_stdout_eq_str("Bonjour\n");
}

Test(my_printf, add_modulo, .init = redirect_all_std)
{
    my_printf("%%");
    cr_assert_stdout_eq_str("%");
}

Test(my_printf, flag_unsigned, .init = redirect_all_std)
{
    my_printf("%u", 4294967295);
    cr_assert_stdout_eq_str("4294967295");
}

Test(my_printf, two_flag_with_str, .init = redirect_all_std)
{
    my_printf("%s%dAstek42", "Salut les loups", 42);
    cr_assert_stdout_eq_str("Salut les loups42Astek42");
}

Test(my_printf, ten_to_binary, .init = redirect_all_std)
{
    my_printf("%b", 10);
    cr_assert_stdout_eq_str("1010");
}
