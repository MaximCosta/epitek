/*
** EPITECH PROJECT, 2023
** myftp [WSL: Ubuntu]
** File description:
** states
*/

#include "myftp.h"

bool is_passive(client_t *client)
{
    return client->channel.status == PASSIVE;
}

bool is_active(client_t *client)
{
    return client->channel.status == ACTIVE;
}

bool is_none(client_t *client)
{
    return client->channel.status == NONE;
}
