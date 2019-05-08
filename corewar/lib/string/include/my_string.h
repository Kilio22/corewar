/*
** EPITECH PROJECT, 2019
** my_string.h
** File description:
** Header file for the string library
*/

#ifndef MY_STRING_H_
#define MY_STRING_H_

#include <stddef.h>

typedef unsigned long pack_t;
#define SIZEPACK sizeof(pack_t)
#define MASKPACK (SIZE_PACK - 1)

size_t my_strlen(const char *s);
size_t my_strnlen(const char *s, size_t maxlen);
size_t my_linelen(const char *s);
size_t my_arraylen(void **array);
size_t my_strarraylen(char **array);
size_t my_arraynlen(void **array, size_t maxlen);
size_t my_strarraynlen(char **array, size_t maxlen);
void *my_memset(void *s, int c, size_t n);
void *my_memcpy(void *dest, const void *src, size_t n);
char *my_strchr(char *s, int c);
char *my_strchrnul(char *s, int c);
char *my_strcpy(char *dest, const char *src);
char *my_strncpy(char *dest, const char *src, size_t n);
char *my_strdup(const char *s);
char *my_strndup(const char *s, size_t n);
char *my_strcat(const char *left, const char *right);
char *my_strncat(const char *left, const char *right, size_t n);
char *my_strcpycat(char *dest, const char *src);
char *my_stralloc(size_t size, char c);
int my_strcmp(const char *s1, const char *s2);
int my_strncmp(const char *s1, const char *s2, size_t n);
char **my_str_towordarray(char *src, const char *delim);

#define TOLOWER(c) (c > 'A' && c < 'Z') ? c - 32 : c
int my_strcasecmp(const char *s1, const char *s2);
int my_strncasecmp(const char *s1, const char *s2, size_t n);

#endif /* !MY_STRING_H_ */
