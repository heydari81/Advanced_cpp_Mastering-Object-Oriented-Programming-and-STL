    #include "message.h"
    #include "TextMessage.h"
    #include "VoiceMessage.h"
    #include <ctime>
    #include <iostream>
    #include <random>
    #include <limits> // For std::numeric_limits
    Message::Message(std::string type, std::string sender, std::string receiver) {
        this->type = type;
        this->sender = sender;
        this->receiver = receiver;
        std::time_t now = std::time(0);
        std::string time = std::ctime(&now);
        time.erase(time.find_last_not_of(" \n\r\t") + 1);
        this->time = time;

    }
    Message::Message() {
        this->type = "";
        this->sender = "";
        this->receiver = "";
        std::time_t now = std::time(0);
        std::string time = std::ctime(&now);
        time.erase(time.find_last_not_of(" \n\r\t") + 1);
        this->time = time;
    }

    // Getter functions
    std::string Message::get_type() const {
        return type;
    }
    std::string Message::get_sender() const {
        return sender;
    }
    std::string Message::get_receiver() const {
        return receiver;
    }
    std::string Message::get_time() const {
        return time;
    }

    // Print function for use in operator<< overloading
    void Message::print(std::ostream &os) const {
        os << "*************************" << std::endl
        << this->get_sender() << " -> " << this->get_receiver() << std::endl
        << "message type: " << this->get_type() << std::endl
        << "message time: " << this->get_time() << std::endl
        << "*************************" << std::endl;
    }
    std::string Message::get_data() const {
    return "";
    }


    // Overload operator<< to work with Message objects
    std::ostream& operator<<(std::ostream &os, const Message &msg) {
        msg.print(os);
        return os;
    }


    TextMessage::TextMessage(std::string text, std::string sender, std::string receiver):Message("text",sender,receiver) {
        this->text = text;
    }
    void TextMessage::print(std::ostream &os) const {
        os << "*************************" << std::endl
        << this->get_sender() << " -> " << this->get_receiver() << std::endl
        << "message type: " << this->get_type() << std::endl
        << "message time: " << this->get_time() << std::endl
        << "text :" << this->get_text() << std::endl
        << "*************************" << std::endl;
    }
    std::string TextMessage::get_text() const {
        return this->text;
    }


    VoiceMessage::VoiceMessage(std::string sender, std::string receiver):Message("voice",sender,receiver) {
        this->voice = generate_randon_bytes();
    }
    std::vector<unsigned char> VoiceMessage::generate_randon_bytes() {
        std::vector<unsigned char> bytes(5);
        std::random_device rd;
        int count  = 5;
        for (int i = 0; i < count; i++) {
            bytes[i] = static_cast<unsigned char>(rd() & 0xFF); // get only lower 8 bits
        }
        return bytes;

    }

    void VoiceMessage::print(std::ostream &os) const {
        os << "*************************" << std::endl
        << this->get_sender() << " -> " << this->get_receiver() << std::endl
        << "message type: " << this->get_type() << std::endl
        << "message time: " << this->get_time() << std::endl
        << "voice :";
        for (int i = 0; i < 5; i++) {
            os << static_cast<int>(this->voice[i]) << " ";
        }
        os << std::endl;
        os << "*************************" << std::endl;
    }

    std::vector<unsigned char> VoiceMessage::get_voice() const {
        return voice;
    }

    std::string VoiceMessage::get_data() const {
        std::string result;
        for (unsigned char b : voice) {
            result += std::to_string(static_cast<int>(b)) + " ";
        }
        return result;
    }

std::string TextMessage::get_data() const {
    return this->get_text();
}
