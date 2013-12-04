#ifndef COMMAND_H
#define COMMAND_H
#include <string>

class Command
{
public:
    Command();
    virtual void execute(std::string s) = 0;
};

#endif // COMMAND_H
