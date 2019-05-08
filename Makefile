##
## EPITECH PROJECT, 2018
## Fairefichier
## File description:
## This is a fairefichier, made by HeyShafty
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
WHITE_C	=	"\e[97m"
DEFAULT_C	=	"\e[39m"
LIGHT_GREY	=	"\e[37m"
DARK_GREY	=	"\e[90m"
LIGHT_RED	=	"\e[91m"
LIGHT_GREEN	=	"\e[92m"
LIGHT_YELLO	=	"\e[93m"
LIGHT_BLUE	=	"\e[94m"
LIGHT_MAGEN	=	"\e[95m"
LIGHT_CYAN	=	"\e[96m"
LINE_RETURN	=	$(ECHO) ""

COLOR_THEME	=	$(BLUE_C)
DEBUG_THEME	=	$(CYAN_C)
TESTS_THEME	=	$(RED_C)

NAME	=	build
ROOT_PATH	=	./
SRC_NAME	=	src
TESTS_NAME	=	tests
INCL_NAME	=	include
SRC_PATH	=	$(ROOT_PATH)$(SRC_NAME)
INCL_PATH	=	$(ROOT_PATH)$(INCL_NAME)
TESTS_PATH	=	$(ROOT_PATH)$(TESTS_NAME)

all:	message $(NAME)

message:
	@$(LINE_RETURN)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"  ____                                  "$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)" / ___|___  _ __ _____      ____ _ _ __ "$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| |   / _ \| '__/ _ \ \ /\ / / _\` | '__|"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| |__| (_) | | |  __/\ V  V / (_| | |   "$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)" \____\___/|_|  \___| \_/\_/ \__,_|_|   "$(DEFAULT)
	@$(LINE_RETURN)

$(NAME): $(OBJ)
	@make -C asm/ -s
	@make -C corewar/ -s

clean:
	@make -C asm/ clean -s
	@make -C corewar/ clean -s

fclean:
	@make -C asm/ fclean -s
	@make -C corewar/ fclean -s

re:		fclean all

.PHONY: all $(NAME) build_libs message clean_libs clean fclean re debug tests_run
