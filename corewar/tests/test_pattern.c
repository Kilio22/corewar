/*
** EPITECH PROJECT, 2019
** test_pattern.c
** File description:
** Just a pattern, copy pasta this
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

static void redirect_criterion(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(yes, empty_test)
{
    redirect_criterion();
    cr_assert(1);
}
