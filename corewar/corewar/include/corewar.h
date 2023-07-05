/*
** EPITECH PROJECT, 2021
** template
** File description:
** template
*/

#ifndef COREWAR_H
    #define COREWAR_H
    #include "../../common/include/common.h"
    #include <termios.h>
    #include <unistd.h>
    #define LEFT  68
    #define RIGHT 67
    #define DOWN  66
    #define UP    65
typedef struct s_champion champion_t;
typedef struct s_process process_t;
typedef struct s_field field_t;
typedef struct s_vm vm_t;
typedef struct s_corewar corewar_t;
typedef struct s_read_champ read_champ_t;
typedef struct instruction_s instruction_t;
typedef struct options_s options_t;

struct s_champion {

    char name[PROG_NAME_LENGTH + 1];
    char comment[COMMENT_LENGTH + 1];
    int prog_size;
    int id;
    int padding;
    int fd;
};

struct s_process {

    int registries[REG_NUMBER];
    int pos;
    int carry;
    int cycle;
    int live;
    instruction_t *instruction;
    process_t *next;

};

struct s_field {

    int owner_id;
    u_char value;

};

struct s_vm {

    field_t fields[MEM_SIZE];
    int alives[4];
    int cycles;
    int check_interval;
    int lastcheck;
    int checks_passed;
    int dump_time;
    process_t *processes;
    int is_winner;

};

struct s_corewar {

    vm_t *vm;
    list_t *champions;

};

struct s_read_champ {

    field_t *field;
    int len;

};

struct options_s {
    int a;
    int n;
    champion_t *champions[4];
    int nb_champions;
    int dump;
};

struct instruction_s {
    int opcode;
    char name[6];
    int nb_params;
    int params_type[3];
    int params[3];
    int size;
};

void parse_argv(corewar_t *corewar, int ac, char **av);

void load_champions(corewar_t *corewar, int ac, char **argv);
vm_t *init_vm(void);
void destroy_vm(vm_t *vm);
corewar_t *init_corewar(int ac, char **argv);
int destroy_corewar(corewar_t *corewar);
void start_graphic_mode(corewar_t *corewar);

champion_t *load_champion(corewar_t *corewar, char *path);
read_champ_t *read_champ(champion_t *champion);

void place_in_arena(corewar_t *corewar, champion_t *champion,
                    read_champ_t *champ, int args[2]);

void free_champ(read_champ_t *champ);
void exit_champ(read_champ_t *champ, corewar_t *corewar);
void exit_number(int number, corewar_t *corewar);

void read_value(field_t *field, int *offset, int size, int *buffer);

//! REMOVE
int main_graphic_curse(field_t *fields);

instruction_t *get_instruction(field_t *field, int pos);

void get_insctruction_loop(instruction_t *instruction, field_t *field,
                            int *sizes, int pos);
instruction_t *check_all_params_valid(instruction_t *instruction);
instruction_t *instruction_error(instruction_t *instruction);

int is_a_pcb(int opcode);

void dump_memory(corewar_t *corewar);

void next_cycle(corewar_t *corewar);

process_t *create_process(int id, int pos);
process_t *clone_process(process_t *process, int new_pos);
void process_append(vm_t *vm, process_t *process);

char *get_champion_name(corewar_t *corewar, int id);
void move_pc(process_t *process, int offset);
void write_at_pos(field_t *fields, int value, int pos, int id);

void live_instruction(corewar_t *corewar, instruction_t *instruction,
                    process_t *process);
void ld_instruction(corewar_t *corewar, instruction_t *instruction,
                    process_t *process);
void st_instruction(corewar_t *corewar, instruction_t *instruction,
                    process_t *process);
void add_instruction(corewar_t *corewar, instruction_t *instruction,
                    process_t *process);
void sub_instruction(corewar_t *corewar, instruction_t *instruction,
                    process_t *process);
void and_instruction(corewar_t *corewar, instruction_t *instruction,
                    process_t *process);
void or_instruction(corewar_t *corewar, instruction_t *instruction,
                    process_t *process);
void xor_instruction(corewar_t *corewar, instruction_t *instruction,
                    process_t *process);
void zjmp_instruction(corewar_t *corewar, instruction_t *instruction,
                    process_t *process);
void ldi_instruction(corewar_t *corewar, instruction_t *instruction,
                    process_t *process);
void sti_instruction(corewar_t *corewar, instruction_t *instruction,
                    process_t *process);
void fork_instruction(corewar_t *corewar, instruction_t *instruction,
                    process_t *process);
void lld_instruction(corewar_t *corewar, instruction_t *instruction,
                    process_t *process);
void lldi_instruction(corewar_t *corewar, instruction_t *instruction,
                    process_t *process);
void lfork_instruction(corewar_t *corewar, instruction_t *instruction,
                    process_t *process);
void aff_instruction(corewar_t *corewar, instruction_t *instruction,
                    process_t *process);

void parse_argv_flag(int *i, int ac, char **av, options_t *opt);
void parse_argv_flag_n(int *i, int ac, char **av, options_t *opt);
int next_cycle_part2(corewar_t *corewar, process_t *process, vm_t *vm);
void do_process(corewar_t *corewar, process_t *process);
#endif // COREWAR_H
