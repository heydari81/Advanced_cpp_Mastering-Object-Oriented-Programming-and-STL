//
// Created by Mohammad on 7/17/2025.
//

#ifndef VOICEMESSAGE_H
#define VOICEMESSAGE_H

#include "Message.h"  // Include the base class header
#include <vector>
#include <string>
#include <iostream>

class VoiceMessage : public Message {
public:
    // Constructor
    VoiceMessage(std::string sender, std::string receiver);

    // Member function for printing
    void print(std::ostream &os) const;

    // Getter function for the voice data
    std::vector<unsigned char> get_voice() const;

    virtual std::string get_data() const;

    std::vector<unsigned char> generate_randon_bytes();
private:
    std::vector<unsigned char> voice; // Array of bytes to store the voice data
};

#endif //VOICEMESSAGE_H
