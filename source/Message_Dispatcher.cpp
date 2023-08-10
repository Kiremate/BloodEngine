#include "../headers/Message_Dispatcher.h"


void blood_engine::Message_Dispatcher::Register(Id id, std::shared_ptr<Message_Observer> observer)
{
    observers[id].emplace_back(observer);
}

void blood_engine::Message_Dispatcher::Send(const std::shared_ptr<Message>& message)
{
    messages.push(message);
}

std::shared_ptr<blood_engine::Message> blood_engine::Message_Dispatcher::Allocate_Message()
{
    return std::make_shared<Message>();
}

void blood_engine::Message_Dispatcher::Update()
{
    while (!messages.empty()) {
        auto message = messages.front();
        auto targets = observers.find(message->target);

        if (targets != observers.end())
        {
            for (auto& target : targets->second)
            {
                target->Handle(*message);
            }
        }

        messages.pop();
    }
}
