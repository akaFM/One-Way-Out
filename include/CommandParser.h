#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include "Map.h"
#include "Player.h"
#include <string>
using namespace std;
class CommandParser {
public:
    CommandParser(Map*, Player*);
    std::string toLower(const std::string& str);
    void runGame();
    void assignCommandAndParameter(const string& uInput, string& command, string& param);
    void executeCommand(std::string m, std::string p);
    void help();
    void printIntroductoryDialogue();

private:
    Map* map;
    Player* player;
};

#endif  // COMMANDPARSER_H