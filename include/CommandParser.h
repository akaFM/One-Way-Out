#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include "Map.h"
#include "Player.h"
#include <string>

class CommandParser {
public:
    CommandParser(Map*, Player*);
    void runGame();
    void assignCommandAndParameter(const string& uInput, string& command, string& param);
    void executeCommand(std::string m, std::string p);
    void help();

private:
    Map* map;
    Player* player;
};

#endif  // COMMANDPARSER_H