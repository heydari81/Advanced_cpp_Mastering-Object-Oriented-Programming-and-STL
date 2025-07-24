#include "user.h"
#include <server.h>
#include <crypto.h>
#include "TextMessage.h"
#include "VoiceMessage.h"

User::User(std::string username, std::string private_key,Server *server):server(server) {
   this->username = username;
   this->private_key = private_key;
}

std::string User::get_username() const {
   return this->username;
}


bool User::send_text_message(std::string text, std::string receiver) {
   std::string signature = crypto::signMessage(private_key, text);
   TextMessage *message = new TextMessage(text,this->get_username(), receiver);
   bool status = server->create_message(message,signature);
   //delete message;
   return status;
}
bool User::send_voice_message(std::string receiver) {
   VoiceMessage *message = new VoiceMessage(this->get_username(), receiver);
   auto text = message->get_data();
   std::string signature = crypto::signMessage(private_key, text);

   bool status = server->create_message(message,signature);
   //delete message;
   return status;
}
