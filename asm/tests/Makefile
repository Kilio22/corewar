##
## EPITECH PROJECT, 2018
## Fairefichier
## File description:
## Fairefichier that does the tests_run rule
##

ECHO	=	/bin/echo -e
DEFAULT	=	"\e[0m"
BOLD_T	=	"\e[1m"
DIM_T	=	"\e[2m"
UNDLN_T	=	"\e[4m"
BLACK_C	=	"\e[30m"
RED_C	=	"\e[31m"
GREEN_C	=	"\e[32m"
YELLO_C	=	"\e[33m"
BLUE_C	=	"\e[34m"
MAGEN_C	=	"\e[35m"
CYAN_C	=	"\e[36m"
DEFAULT_C	=	"\e[39m"
LIGHT_RED	=	"\e[91m"
LIGHT_GREEN	=	"\e[92m"
LIGHT_YELLO	=	"\e[93m"
LIGHT_BLUE	=	"\e[94m"
LIGHT_MAGEN	=	"\e[95m"
LIGHT_CYAN	=	"\e[96m"
LINE_RETURN	=	$(ECHO) ""

NAME	=	unit_tests
ROOT_PATH	=	../
SRC_NAME	=	src
TESTS_NAME	=	tests
INCL_NAME	=	include
SRC_PATH	=	$(ROOT_PATH)$(SRC_NAME)
INCL_PATH	=	$(ROOT_PATH)$(INCL_NAME)
TESTS_PATH	=	$(ROOT_PATH)$(TESTS_NAME)

SRC_TESTS	=	test_pattern.c

SRCS	=	$(SRC:%=$(SRC_PATH)/%) $(SRC_TESTS)
OBJ	=	$(SRCS:.c=.test_o)
LIB_PATHS_FLAG	=	$(LIB_PATHS:%=-L$(ROOT_PATH)%)

CFLAGS	=	-Wall -Wextra -Werror -I $(INCL_PATH) --coverage
LDFLAGS	=	$(LIB_PATHS_FLAG) $(LIBRARIES) -lcriterion

all:	message $(NAME)

message:
	@$(LINE_RETURN)
	@$(ECHO) $(BOLD_T)\\$(COLOR_THEME)" _   _       _ _     _____         _"$(DEFAULT)
	@$(ECHO) $(BOLD_T)\\$(COLOR_THEME)"| | | |_ __ (_) |_  |_   _|__  ___| |_ ___"$(DEFAULT)
	@$(ECHO) $(BOLD_T)\\$(COLOR_THEME)"| | | | '_ \| | __|   | |/ _ \/ __| __/ __|"$(DEFAULT)
	@$(ECHO) $(BOLD_T)\\$(COLOR_THEME)'| |_| | | | | | |_    | |  __/\__ \ |_\__ \\'$(DEFAULT)
	@$(ECHO) $(BOLD_T)\\$(COLOR_THEME)" \___/|_| |_|_|\__|   |_|\___||___/\__|___/\n"$(DEFAULT)
	@$(LINE_RETURN)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) && \
		$(ECHO) $(BOLD_T)$(GREEN_C)"\n[✔] COMPILED:" $(DEFAULT)$(LIGHT_GREEN) "$(NAME)\n"$(DEFAULT) || \
		$(ECHO) $(BOLD_T)$(RED_C)"[✘] "$(UNDLN_T)"BUILD FAILED:" $(LIGHT_RED) "$(NAME)\n"$(DEFAULT)
	@./$(NAME)

clean:
	@$(RM) $(OBJ:%=%.gcno)
	@$(RM) $(OBJ:%=%.gcda)
	@$(ECHO) $(RED_C)$(DIM_T)"[clean]  "$(DEFAULT) \
		$(BOLD_T)$(RED_C)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"$(NAME)'s coverage files"$(DEFAULT)
	@$(RM) $(OBJ)
	@$(ECHO) $(RED_C)$(DIM_T)"[clean]  "$(DEFAULT) \
		$(BOLD_T)$(RED_C)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"$(NAME)'s object files"$(DEFAULT)

fclean:	clean
	@$(RM) $(NAME)
	@$(ECHO) $(RED_C)$(DIM_T)"[fclean] "$(DEFAULT) \
		$(BOLD_T)$(RED_C)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"Binary $(NAME)"$(DEFAULT)

re:		fclean all

%.test_o: %.c
	@$(CC) -c $(CFLAGS) -o $@ $< && \
		$(ECHO) $(DIM_T) "cc $(CFLAGS) -c "$<\\$(COLOR_THEME)" -o "$@ $(DEFAULT) || \
		$(ECHO) "\n"$(MAGEN_C) $(UNDLN_T)$(BOLD_T)"cc $(CFLAGS) -c "$<" -o "$@$(DEFAULT)"\n"

.PHONY: all $(NAME) message clean fclean re
