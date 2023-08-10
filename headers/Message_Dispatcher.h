/**
 * @author Bloodmask
 * @copyright Copyright (c) 2023, Bloodmask
 * @license All rights reserved
 */
#pragma once
#include "System.h"
#include <map>
#include <queue>
namespace blood_engine {
	class Message_Observer;
	typedef int Id;
	typedef std::string Variant;
	
	struct Message 
	{
	public:
		Id target;
		Id action;

		struct Param
		{
			Id id;
			Variant value;
		};

		Param params[5];
	};
	
	class Message_Observer {
		
	public:
		virtual void Handle(const Message&) = 0;
	};
	
	class Message_Dispatcher : public System
	{
	public:
		void Register(Id id, std::shared_ptr<Message_Observer> observer);
		std::shared_ptr<Message> Allocate_Message();
		void Send(const std::shared_ptr<Message>& message);
		void Update() override;
	private:
		std::map< Id, std::vector<std::shared_ptr<Message_Observer>>> observers;
		std::queue<std::shared_ptr<Message>> messages;
		std::vector<std::shared_ptr<Message>> message_pool;
	};
}
