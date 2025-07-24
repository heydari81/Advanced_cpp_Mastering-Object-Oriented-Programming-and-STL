//
// Created by Mohammad on 7/17/2025.
//

#ifndef TEXTMESSAGE_H
#define TEXTMESSAGE_H
#include <message.h>
#include <string>
#include <iostream>

class TextMessage : public Message {
public:
    // Constructor
    TextMessage(std::string text, std::string sender, std::string receiver);

    // Member function for printing
    void print(std::ostream &os) const;

    // Getter function for the text content
    std::string get_text() const;

    virtual std::string get_data() const;
private:
    std::string text;  // The text content of the message
};

#endif //TEXTMESSAGE_H
