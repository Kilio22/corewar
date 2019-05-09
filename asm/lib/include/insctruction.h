/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** insctruction
*/

#ifndef INSCTRUCTION_H_
#define INSCTRUCTION_H_

enum id_delimiters {
    ID_NOTHING,
    ID_SPACE,
    ID_TAB,
    ID_SEPARATOR,
    ID_COMMENT,
    ID_LABEL,
    ID_DIRECT,
    ID_NUMBER
};

enum delimiter_types {
    D_WITHOUT,
    D_NORMAL,
    D_GET,
    D_SEPARATOR,
    D_COMMENT,
    D_NUMBER
};

struct instruction {
    char *instruction;
    short id;
    short type;
    struct instruction *next;
};

struct label {
    char *name;
    int offset;
    struct label *next;
};

/* INSTRUCTIONS */
/* Create */
struct instruction *create_instruction(void);
struct instruction *create_instruction_from_line(char *line);
struct instruction **load_instructions(char **file);
/* Destroy */
void destroy_instruction(struct instruction *inst);
void destroy_instruction_list(struct instruction **list);

/* LABELS */
/* Create */
struct label *create_label(char *name, int offset);
int get_labels(struct instruction **list, struct label **head);
struct label *find_label(struct label *head, const char *name);
/* Destroy */
void destroy_labels(struct label *head);

#endif /* !INSCTRUCTION_H_ */
