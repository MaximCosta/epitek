/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-hades.cuisinier
** File description:
** teams
*/

#ifndef TEAMS_H_
    #define TEAMS_H_
    #define CREATED_L 20
    #define NAME_L 32
    #define UUID_L 38
    #define DESC_L 255
    #define BODY_L 512
    #define BUFF_SIZE 512
    #define EXIT_SUCCESS 0
    #define EXIT_FAIL 84
    #define SUCCESS "41"
    #define KO "59"
    #define ENDER "\r\n"
    #include <string.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdbool.h>
    #include <stdarg.h>
    #include <time.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <uuid/uuid.h>
    #include <signal.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <sys/select.h>
    #include <sys/time.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include "../libs/myteams/logging_server.h"

typedef struct team_s {
    char name[NAME_L];
    char description[DESC_L];
    char created_at[CREATED_L];
    uuid_t uuid;
    uuid_t created_by;
    uuid_t team_uuid;
} team_t;

typedef struct channel_s {
    char name[NAME_L];
    char description[DESC_L];
    char created_at[CREATED_L];
    uuid_t uuid;
    uuid_t created_by;
    uuid_t team_uuid;
} channel_t;

typedef struct thread_s {
    char title[NAME_L];
    char body[BODY_L];
    char created_at[CREATED_L];
    uuid_t uuid;
    uuid_t created_by;
    uuid_t channel_uuid;
} thread_t;

typedef struct comment_s {
    char body[BODY_L];
    char created_at[CREATED_L];
    uuid_t uuid;
    uuid_t thread_uuid;
    uuid_t created_by;
} comment_t;

typedef struct messages_s {
    char body[BODY_L];
    uuid_t receiver;
    uuid_t created_by;
    time_t created_at;
    struct messages_s *next;
} messages_t;

typedef struct user_s {
    int *fd;
    int len_fd;
    char username[NAME_L];
    char unparsed_uuid[UUID_L];
    uuid_t uuid;
    uuid_t path;
    time_t created_at;
    messages_t *messages;
    struct user_s *next;
} user_t;

typedef struct client_s {
    int fd;
    char buffer[BUFF_SIZE];
    char unparsed_cmd[BUFF_SIZE];
    char unparsed_uuid[UUID_L];
    char **cmd;
    uuid_t user_uuid;
    struct client_s *next;
} client_t;

typedef struct server_s {
    int port;
    int opt;
    int addrlen;
    int vread;
    int server_fd;
    int new_socket;
    int keep_running;
    client_t *clients;
    user_t *users;
    fd_set readfds;
    fd_set writefds;
    struct sockaddr_in address;
} server_t;

// extern int keep_running;
void sigint_handler(int sig);

//? SERVER

/* init_serv.c */
void free_server(server_t *server);
int setup_server(server_t *server, int port);

/* loop/run_server.c */
int run_server(server_t *server);

/* loop/handler.c */
int handle_new_connection(server_t *server);
int handle_client(server_t *server, client_t *client);
int handle_commands(server_t *server, client_t *client);

/* struct/add_remove_client.c */
void free_clients(server_t *server);
void remove_client(server_t *server, client_t *client);
void add_client(server_t *server, int socket_fd, struct sockaddr_in *address);

/* struct/user_functions.c */
user_t *add_fd_user(user_t *user, int fd);
user_t *remove_fd_user(user_t *user, int fd);
user_t *user_exists(server_t *server, char *username);
user_t *find_user_by_uuid(server_t *server, uuid_t uuid);
user_t *create_user(server_t *server, client_t *client);

/* struct/free_command.c */
void free_command(client_t *client);

/* struct/save_users.c */
void free_users(server_t *server);
void add_user(server_t *server, char *username, char *uuid);
void load_users(server_t *server);
void save_users(server_t *server);

/* struct/init_messages.c */
void free_messages(messages_t *messages);
void add_messages(messages_t *messages, uuid_t sender,
uuid_t receiver, char *body);
char *get_messages(messages_t *messages, uuid_t other);
messages_t *create_message(uuid_t sender, uuid_t receiver, char *body);

/* users/print_all_fds.c */
void print_all_fds_user(user_t *user, char *format, ...);
int print_all_fds(server_t *server, user_t *user, char *code, char *message);

//? COMMANDS

/* commands/login.c */
int login(server_t *server, client_t *client);

/* commands/help.c */
int help(server_t *server, client_t *client);

/* commands/logout.c */
int logout(server_t *server, client_t *client);

/* commands/users.c */
char *get_users(server_t *server);
int users(server_t *server, client_t *client);

/* commands/user.c */
int user(server_t *server, client_t *client);

/* commands/send.c */
int send_message(server_t *server, client_t *client);

/* commands/messages.c */
int messages(server_t *server, client_t *client);

/* commands/use.c */
int use(server_t *server, client_t *client);

/* commands/create.c */
int create(server_t *server, client_t *client);

/* commands/list.c */
int list(server_t *server, client_t *client);

/* commands/info.c */
int info(server_t *server, client_t *client);

/* commands/subscribe.c */
int subscribe(server_t *server, client_t *client);

/* commands/unsubscribe.c */
int unsubscribe(server_t *server, client_t *client);

/* commands/subscribed.c */
int subscribed(server_t *server, client_t *client);

//? UTILS
char *my_strdup(char *str);
int remove_backslash_r(char *str);
int string_contains(char *str, char c);
void parse_command(client_t *client);
#endif /* !TEAMS_H_ */
