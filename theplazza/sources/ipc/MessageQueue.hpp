#ifndef B_CCP_400_MPL_4_1_THEPLAZZA_HUGO_ESCHLIMANN_MESSAGEQUEUE_HPP
#define B_CCP_400_MPL_4_1_THEPLAZZA_HUGO_ESCHLIMANN_MESSAGEQUEUE_HPP

#include "Ipc.hpp"
#include <algorithm>
#include <cstring>
#include "../reception/Order.hpp"

#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <stdio.h>

namespace Plazza {
    inline struct mq_attr attr {
        .mq_flags = 0,
        .mq_maxmsg = 10,
        .mq_msgsize = sizeof(mq_attr)
    };

    struct msgbuf {
        long mtype;
        char mtext[502];
    };

    class MessageQueue : public IPC {
    public:
        MessageQueue() = default;
        ~MessageQueue() override = default;

        MessageQueue(const MessageQueue& other) = default;
        MessageQueue& operator=(const MessageQueue& other) = default;
        MessageQueue(MessageQueue&& other) noexcept = default;
        MessageQueue& operator=(MessageQueue&& other) noexcept = default;

        void sendMessage(std::string message, int type) override;
        void sendMessageOrder(const Order& order, unsigned int type);
        std::string receiveMessage(unsigned int type) override;
        std::string receiveMessageNoWait(unsigned int type);
        std::string receiveMessageOrder(unsigned int type);
        std::string receiveMessageOrderNoWait(unsigned int type);
        void createMessageQueue();
        void deleteMessageQueue();

        int getId() const;

    private:
        int _msgId;
        mqd_t _mqd;
        std::string _tmpName;
    };
} // Plazza

#endif //B_CCP_400_MPL_4_1_THEPLAZZA_HUGO_ESCHLIMANN_MESSAGEQUEUE_HPP
