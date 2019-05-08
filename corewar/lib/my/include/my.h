/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** Header for libmy.a
*/

#ifndef MY_H_
#define MY_H_

#include <stddef.h>

void *free_em(size_t n, ...);
int my_atoi(char const *str);
void my_free_fields(char **array);
int my_intlen(int nb);
char *my_itoa(int nb);
char **my_remove_ptr_fromarray(char **array, char *ptr);
char **my_realloc_array(char **array);
char *my_revstr(char *str);
char *my_str_addchar(char const *str, char const c, int index);
int my_str_ends_with(const char *str, const char *end);
int my_str_isnum(char const *str, int neg);

#endif /* MY_H_ */
