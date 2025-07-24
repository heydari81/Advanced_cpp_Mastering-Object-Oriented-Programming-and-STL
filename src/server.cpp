#include "server.h"
#include "crypto.h"
#include <algorithm>
#include <vector>
#include <iterator>
std::vector<User> Server::get_users() const {
    return users;
}
std::map<std::string, std::string> Server::get_public_keys() const {
    return public_keys;
}
std::vector<Message*> Server::get_messages() const {
    return messages;
}

User Server::create_user(std::string username) {
    auto it = std::find_if(users.begin(), users.end(), [&](const User& u) {
    return u.get_username() == username;
});
    if (it != users.end()) {
        throw std::invalid_argument("Username already exists");
    }
    std::string public_key{}, private_key{};
    crypto::generate_key(public_key, private_key);
    public_keys[username] = public_key;
    users.emplace_back(username, private_key, this);
    return users.back();
}
bool Server::create_message(Message* msg, std::string signature) {
    std::string sender = msg->get_sender();
    auto receiver = msg->get_receiver();
    bool found = false;
    for (auto it = users.begin(); it != users.end(); it++) {
        if ((*it).get_username() == receiver ) {
            found = true;
            break;
        }
    }
    if (found == false) {
        return false;
    }
    std::string public_key = public_keys[sender];
    auto data = msg->get_data();
    bool authentic = crypto::verifySignature(public_key,data, signature);
    public_keys[sender] = public_key;
    if (!authentic) {
        return false;
    }
    messages.push_back(msg);
    return true;
}


std::vector<Message *> Server::get_all_messages_from(std::string username) {
    std::vector<Message *> messages_from_user;
    for (auto it = messages.begin(); it != messages.end(); it++) {
        if ((*it)->get_sender() == username) {
            messages_from_user.push_back(*it);
        }
    }
    return messages_from_user;
}
std::vector<Message *> Server::get_all_messages_to(std::string username) {
    std::vector<Message *> messages_to_user;
    for (auto it = messages.begin(); it != messages.end(); it++) {
        if ((*it)->get_receiver() == username) {
            messages_to_user.push_back(*it);
        }
    }
    return messages_to_user;
}
std::vector<Message *> Server::get_chat(std::string user1, std::string user2) {
    std::vector<Message *> messages_chat;
    for (auto it = messages.begin(); it != messages.end(); it++) {
        if (((*it)->get_receiver() == user1 && (*it)->get_sender() == user2) or
            ((*it)->get_receiver() == user2 && (*it)->get_sender() == user1)) {
            messages_chat.push_back(*it);
        }
    }
    return messages_chat;
}
void Server::sort_msgs(std::vector<Message *> &msgs) {
    std::sort(msgs.begin(), msgs.end(), [](Message* m1, Message* m2) {
        return m1->get_time() < m2->get_time();
    });
}



