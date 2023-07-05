#include "MessageQueue.hpp"

namespace Plazza {
    void MessageQueue::createMessageQueue() {
        _msgId = msgget(IPC_PRIVATE, IPC_CREAT | 0666);
        if (_msgId == -1) {
            throw PlazzaException("Error when creating message queue");
        }
    }

    int MessageQueue::getId() const {
        return _msgId;
    }

    void MessageQueue::sendMessage(std::string message, int type) {
        msgbuf buffer;
        
        buffer.mtype = type;
        std::copy_n(message.begin(), message.size(), buffer.mtext);
        if (msgsnd(_msgId, &buffer, sizeof(buffer), 0) == -1) {
            throw PlazzaException("Error when sending message");
        }
    }

    void MessageQueue::sendMessageOrder(const Order& order, unsigned int type) {
        msgbuf buffer;
        std::string message { order.serialize() };

        buffer.mtype = type;
        std::copy_n(message.begin(), message.size() + 1, buffer.mtext);
        if (msgsnd(_msgId, &buffer, sizeof(buffer) + 1, 0) == -1) {
            throw PlazzaException("Error when sending message");
        }
    }

    std::string MessageQueue::receiveMessage(unsigned int type) {
        msgbuf buffer;
        
        if (msgrcv(_msgId, &buffer, sizeof(buffer), type, 0) == -1) {
            throw PlazzaException("Error when receiving message");
        }
        return buffer.mtext;
    }

        std::string MessageQueue::receiveMessageNoWait(unsigned int type) {
        msgbuf buffer;
        
        if (msgrcv(_msgId, &buffer, sizeof(buffer), type, 0) == -1) {
            throw PlazzaException("Error when receiving message");
        }
        return buffer.mtext;
    }

    std::string MessageQueue::receiveMessageOrder(unsigned int type) {
        msgbuf buffer;

        if (msgrcv(_msgId, &buffer, sizeof(buffer), type, 0) == -1) {
            throw PlazzaException("Error when receiving message");
        }
        return buffer.mtext;
    }

    std::string MessageQueue::receiveMessageOrderNoWait(unsigned int type) {
        msgbuf buffer;

        if (msgrcv(_msgId, &buffer, sizeof(buffer) + 1, (long)type, IPC_NOWAIT) == -1) {
            if (errno == ENOMSG) {
                return "false";
            }
            throw PlazzaException("Error when receiving message");
        }
        return buffer.mtext;
    }


    void MessageQueue::deleteMessageQueue() {
        if (msgctl(_msgId, IPC_RMID, nullptr) == -1) {
            throw PlazzaException("Error when deleting message queue");
        }
    }
} // Plazza