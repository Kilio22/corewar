/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** parsing
*/

#ifndef PARSING_H_
#define PARSING_H_

typedef struct champion_params {
    char *fp;
    int nb;
    int adress;
} champion_params_t;

typedef struct parsing {
    int dump;
    int nb_used[MAX_CHAMPIONS];
    champion_params_t **params;
} parsing_t;

champion_params_t **realloc_params(champion_params_t **old);
int check_flag(char const *str);
int manage_adress(size_t *i, char const **tab, parsing_t *parsing,
int *current);
int manage_nb(size_t *i, char const **tab, parsing_t *parsing, int *current);
int manage_dump(size_t *i, char const **tab, parsing_t *parsing, int *current);
int add_champ(char const *fp, parsing_t *parsing, int *current);
int parse_args(int ac, char const *argv[], parsing_t *parsing);
void destroy_args(parsing_t *parsing);

extern const char *flags[];
typedef int (* const parsing_functions_t)(size_t *, char const **, parsing_t *,
int *);
extern parsing_functions_t tab_ftcs[];

#endif /* !PARSING_H_ */
