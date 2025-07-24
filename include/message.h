#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
class Message {
public:
    // Constructors
    Message(std::string type, std::string sender, std::string receiver);
    Message();
    // Getter functions
    std::string get_type() const;
    std::string get_sender() const;
    std::string get_receiver() const;
    std::string get_time() const;
    virtual std::string get_data() const;
    // Print function for use in operator<< overloading
    void virtual print(std::ostream &os) const;

    // Overload operator<< to work with Message objects
    friend std::ostream& operator<<(std::ostream &os, const Message &msg);
    virtual ~Message() = default;
private:
    std::string type;     // Type of the message ("text", "voice", ...)
    std::string sender;   // The username who sent this message
    std::string receiver; // The username to whom this message is intended
    std::string time;     // Creation time of the message in GMT
};
#endif //MESSAGE_H