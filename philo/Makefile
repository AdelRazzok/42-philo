NAME          = philo
INCLUDES      = include/
HEADER        = -I $(INCLUDES)
SRC_DIR       = src/
OBJ_DIR       = obj/

CC            = gcc
CFLAGS        = -Wall -Wextra -Werror -pthread

SRC_FILES     = main error utils threads philos routine mutex_handler

SRC           = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ           = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJ_CACHE     = .cache_exists

#####

all:			$(NAME)

$(NAME):		$(OBJ)
					$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
					@echo "philo compiled!"


$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_CACHE)
					@echo "Compiling $<"
					@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJ_CACHE):
					@mkdir -p $(OBJ_DIR)

clean:
					@rm -rf $(OBJ_DIR)
					@echo "philo object files cleaned!"

fclean:			clean
					@rm -f $(NAME)
					@echo "philo executable files cleaned!"

re:				fclean all
					@echo "Cleaned and rebuilt everything for philo!"

.PHONY:			all clean fclean re
