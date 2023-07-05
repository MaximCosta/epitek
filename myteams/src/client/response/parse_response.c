/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-hades.cuisinier
** File description:
** parse_response
*/

#include "client.h"

char **parse_messages(char *buffer)
{
    char **response = calloc(4, sizeof(char *));
    char *tmp = buffer + 5;

    response[0] = parse_uuid(tmp);
    tmp += strcspn(tmp, "(") + 1;
    response[1] = strndup(tmp, strcspn(tmp, ")"));
    tmp += strcspn(tmp, ")") + 2;
    response[2] = strdup(tmp);
    return response;
}

char **parse_send(char *buffer)
{
    char **response = calloc(3, sizeof(char *));
    char *tmp = buffer + 5;

    response[0] = parse_uuid(tmp);
    tmp += strcspn(tmp, "]") + 2;
    response[1] = strndup(tmp, strcspn(tmp, "\r"));
    response[1][strcspn(tmp, "\r")] = '\0';
    return response;
}

char **parse_status(char *buffer)
{
    char **status = parse_uuid_and_name(buffer);
    char *tmp = buffer + strcspn(buffer, "]") + 11;
    status[2] = strdup(tmp);
    return status;
}

char *parse_uuid(char *buffer)
{
    char buff[37];
    char *tmp = buffer + strcspn(buffer, "[") + 1;

    strncpy(buff, tmp, strcspn(tmp, "]"));
    buff[strcspn(tmp, "]")] = '\0';
    return strdup(buff);
}

char **parse_uuid_and_name(char *buffer)
{
    char buff[37];
    char username[512];
    char *tmp = buffer[0] == '4' || buffer[0] == '5' ?
    buffer + 5 : buffer;
    char **response = calloc(4, sizeof(char *));

    strncpy(username, tmp, strcspn(tmp, "-"));
    username[strcspn(tmp, "-")] = '\0';
    response[0] = strdup(username);
    tmp += strcspn(tmp, "-") + 2;
    strncpy(buff, tmp, strcspn(tmp, "]"));
    buff[strcspn(tmp, "]")] = '\0';
    response[1] = strdup(buff);
    return response;
}
