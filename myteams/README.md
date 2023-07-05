# MyTeams Protocol

# 1 Introduction :

The MyTeams project aims to develop a server and a CLI client for communication between users. This document provides a detailed description of the       protocol to be used in the project.

# 2 Overview :

The MyTeams protocol is based on the Transmission Control Protocol (TCP) for network communication. The protocol defines the data model, commands, and events that  the server and client will use to exchange data. The protocol is divided into two main categories: Request-Response commands and Event notifications.

# 3 Core of the project :

User: The user is identified by a unique username and has a status (online, offline)

Channel: The channel is a group of users that can communicate with each other. It is identified by a unique ID and has a name and a list of users

Message: The message is a text sent by a user in a channel. It is identified by a unique ID and has a content, a timestamp, and the username of the sender

# 4 Request-Response Commands :
Request-Response commands are used by the client to interact with the server. Each command has a unique ID, and the server responds with a corresponding response message.

  * /help : Displays the list of available commands.

  * /login [“user_name”] : Sets the user name used by the client. Replace [“user_name”] with the desired name.

  * /logout : Disconnects the client from the server.

  * /users : Retrieves the list of all users that exist on the domain.

  * /user [“user_uuid”] : Retrieves details about the specified user. Replace [“user_uuid”] with the user's unique identifier.

  * /send [“user_uuid”] [“message_body”] : Sends a message to the specified user. Replace [“user_uuid”] with the user's unique identifier and [“message_body”] with the content of the message.

  * /messages [“user_uuid”] : Lists all messages exchanged with the specified user. Replace [“user_uuid”] with the user's unique identifier.

  * /subscribe [“team_uuid”] : Subscribes to the events of a team and its sub-directories. Replace [“team_uuid”] with the unique identifier of the team.

  * /subscribed ?[“team_uuid”] : Lists all subscribed teams or all users subscribed to a team. Replace ?[“team_uuid”] with an optional parameter to list users subscribed to a specific team.

  * /unsubscribe [“team_uuid”] : Unsubscribes from a team. Replace [“team_uuid”] with the unique identifier of the team.

  * /use ?[“team_uuid”] ?[“channel_uuid”] ?[“thread_uuid”] : Sets the command context to a team, channel, or thread. Replace the optional parameters with the unique identifiers of the desired team, channel, or thread.

  * /create : Creates a sub-resource based on the current context.

  * /list : Lists all sub-resources based on the current context.

  * /info : Displays details of the current resource based on the context.

The Magic Numbers are 41 and 59
41 return OK
59 return KO

# 5 Event Notifications :

Event notifications are sent by the server to the client to inform about changes in the system.

  * 5.1. User Status Change :
  The server sends a User Status Change event to the client when a user changes their status (online or offline).

  * 5.2. New Message :
  The server sends a New Message event to the client when a new message is sent in a channel. The event includes the content of the message, the timestamp, and the username of the sender.

  * 5.3. New Channel :
  The server sends a New Channel event to the client when a new channel is created. The event includes the ID and name of the channel.

  * 5.4. Channel Update :
  The server sends a Channel Update event to the client when a channel is updated. The event includes the ID and name of the channel.

# Conclusion

The MyTeams protocol defines the commands and events used by the server and client to communicate with each other.
