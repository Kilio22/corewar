/*
** EPITECH PROJECT, 2019
** my_stdio.h
** File description:
** Header file for the stdio library
*/

#ifndef MY_STDIO_H_
#define MY_STDIO_H_

#include <stddef.h>
#include <stdio.h>

/* get_next_line */
#define READ_SIZE 4096
char *get_next_line(int fd);

int my_dprintf(int fd, const char *format, ...);
int my_dputc(int c, int fd);
size_t my_dputs(const char *s, int fd);
int my_fputc(int c, FILE *fp);
size_t my_fputs(const char *s, FILE *fp);
int my_printf(const char *format, ...);
int my_putchar(int c);
int my_putnbr(int nb);
size_t my_puts(const char *s);
size_t my_putstr(const char *s);
void my_show_wordarray(char **array);

#endif /* !MY_STDIO_H_ */
