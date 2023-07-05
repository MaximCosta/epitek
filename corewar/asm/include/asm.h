/*
** EPITECH PROJECT, 2021
** template
** File description:
** template
*/

#ifndef ASM_H
    #define ASM_H
    #include "../../common/include/common.h"

typedef struct s_parsing parsing_t;
typedef struct s_label label_t;

struct s_label {

    char *name;
    int offset;

};

struct s_parsing {

    int file_fd;
    bool quotted;
    bool has_name;
    char name[PROG_NAME_LENGTH + 1];
    int prog_size;
    bool has_comment;
    char comment[COMMENT_LENGTH + 1];
    list_t *labels;

};

void compile_asm(char *filename, parsing_t *parsing);
void handle_header_name_line(char *line, char **splitted, parsing_t *parsing);
void handle_header_comment_line(char *line, char **splitted,
    parsing_t *parsing);
void create_compiled_file(char *filename, parsing_t *parsing);
void first_handle_instruction_line(char *line, parsing_t *parsing);
void handle_header_line(char *line, parsing_t *parsing);
void increment_prog_size(parsing_t *parsing, int len);
bool can_be_param_type(args_type_t types, args_type_t type);
int get_param_type(parsing_t *parsing, char *str);
int get_mnemonique_index(char *str);
bool is_label_declaration(char *str);
bool is_label_char(char c);
bool already_exist_label(list_t *labels, char *label);
bool is_valid_label_name(char *label);
void check_file_content(parsing_t *parsing, FILE *file);
void compile_header(parsing_t *parsing);
bool has_multiple_operation(char *line);
void store_labels(parsing_t *parsing, FILE *file);
void compile_code(parsing_t *parsing, FILE *file);
int write_params(parsing_t *parsing, char *line,
    int mnem_index, int *curr_byte);
int get_label_offset(list_t **labels, char *label);
bool is_index(char *instruction, int parami);

#endif // ASM_H
