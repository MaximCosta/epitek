/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-hades.cuisinier
** File description:
** client
*/

#ifndef CLIENT_H_
    #define CLIENT_H_
    #define CREATED_L 20
    #define NAME_L 32
    #define UUID_L 16
    #define DESC_L 255
    #define BODY_L 512
    #define BUFF_SIZE 1024
    #define EXIT_SUCCESS 0
    #define EXIT_FAIL 84
    #define RS_OK "41"
    #define RS_KO "59"
    #define R_LOGGED "User logged in."
    #define ENDER "\r\n"
    #include <string.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdbool.h>
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
    #include <uuid/uuid.h>
    #include "../libs/myteams/logging_client.h"

typedef struct client_server_s {
    char *ip;
    char *name;
    int port;
    int socket;
    int fd;
    int server_fd;
    int keep_running;
    char buffer[BUFF_SIZE];
    char command[BUFF_SIZE];
    fd_set readfds;
    fd_set writefds;
    uuid_t user_uuid;
    struct sockaddr_in server_addr;
} client_server_t;

/* init_client.c */
int init_client(client_server_t *client, char **av);


/* loop/client_success.c */
int handle_success(client_server_t *client);

/* loop/client_error.c */
int handle_error(client_server_t *client);

/* loop/client_loop.c */
int client_loop(client_server_t *client);
int handle_input(client_server_t *client);
int handle_server_response(client_server_t *client);
int handle_server_activity(client_server_t *client);

/* response/parse_response.c */
char **parse_messages(char *buffer);
char **parse_send(char *buffer);
char **parse_status(char *buffer);
char *parse_uuid(char *buffer);
char **parse_uuid_and_name(char *buffer);

/* response/client_log.c */
int client_log(client_server_t *client);

/* response/client_logout.c */
int client_logout(client_server_t *client);

/* response/client_users.c */
int client_users(client_server_t *client);

/* response/client_user.c */
int client_user(client_server_t *client);

/* response/client_unauthorized.c */
int client_unauthorized(client_server_t *client);

/* response/client_unknown_user.c */
int client_unknown_user(client_server_t *client);

/* response/client_send.c */
int client_send(client_server_t *client);

/* response/client_messages.c */
int client_messages(client_server_t *client);


#endif /* !CLIENT_H_ */
