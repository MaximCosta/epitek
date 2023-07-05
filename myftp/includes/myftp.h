/*
** EPITECH PROJECT, 2023
** myftp [WSL: Ubuntu]
** File description:
** myftp
*/

#ifndef MYFTP_H_
    #define MYFTP_H_
    #ifdef __GNUC__
        #define UNUSED(x) UNUSED_##x __attribute__((__unused__))
    #else
        #define UNUSED(x) UNUSED_##x
    #endif
    #define BUFFER_SIZE 4096
    #include <arpa/inet.h>
    #include <fcntl.h>
    #include <limits.h>
    #include <netinet/in.h>
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/io.h>
    #include <sys/mman.h>
    #include <sys/select.h>
    #include <sys/socket.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <unistd.h>

    typedef struct serv serv_t;
    typedef struct client client_t;
    typedef struct channel_s channel_t;
    typedef struct socket_s socket_t;
    typedef struct sockaddr sockaddr_t;
    typedef struct command_map command_map_t;
    typedef struct sockaddr_in sockaddr_in_t;
    typedef int (*command_handler)(char *buf, client_t *client);

    typedef enum state_e { PASSIVE, ACTIVE, NONE } state_t;
    struct command_map {
        char *key;
        command_handler handler;
    };

    struct socket_s {
        sockaddr_in_t sock_in;
        int fd;
    };
    struct channel_s {
        state_t status;
        socket_t server;
        int fd;
    };
    struct client {
        bool used;
        int anonymous;
        char *path;
        int state;
        channel_t channel;
        socket_t socket;
        serv_t *serv;
    };
    struct serv {
        socket_t *socket;
        fd_set read_set;
        int port;
        client_t *clients;
        char *default_path;
    };

    // clients
    //  -> call.c
    int execute_command(int clientfd, char *buffer, client_t *client);
    //  -> client_manage.c
    int check_empty(char *buffer);
    void close_channel(client_t *client);
    void remove_client(client_t *client);
    int client_read(serv_t *serv, client_t *client);
    //  -> channel_manage.c
    int channel_read(serv_t *serv, client_t *client);
    //  -> client.c
    client_t *client_init(void);
    void client_new(serv_t *serv, bool writing);
    //  -> state.c
    bool is_passive(client_t *client);
    bool is_active(client_t *client);
    bool is_none(client_t *client);

    // commands
    //  -> auth.c
    int handle_user_command(char *buffer, client_t *client);
    int handle_pass_command(char *buffer, client_t *client);
    int handle_quit_command(char *buffer, client_t *client);
    //  -> help.c
    int handle_help_command(char *buffer, client_t *client);
    //  -> noop.c
    int handle_noop_command(char *buffer, client_t *client);
    //  -> pwd.c
    int handle_pwd_command(char *buffer, client_t *client);
    //  -> cwd.c
    int handle_cwd_command(char *buffer, client_t *client);
    //  -> cdup.c
    int handle_cdup_command(char *buffer, client_t *client);
    //  -> pasv.c
    int handle_pasv_command(char *buffer, client_t *client);
    //  -> list.c
    char *get_path(char *buffer, client_t *client);
    int handle_list_command(char *buffer, client_t *client);
    //  -> check_state.c
    int check_state(int state, client_t *client);

    // server
    //  -> server.c
    serv_t *init_serv(int argc, char **argv);
    int create_server(int port);
    // -> check.c
    int check_args(int argc, char **argv);
    // -> socket.c
    void socket_read_set(serv_t *serv);
    int create_socket(void);
    socket_t *init_socket(int port);
    // -> send.c
    int psend(int fd, const void *buf);
    // -> channel.c
    bool is_channel_open(channel_t *channel, int fd);
    int connect_channel(client_t *client);

#endif /* !MYFTP_H_ */
