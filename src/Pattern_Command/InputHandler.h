#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#pragma once
#include "Racket.hpp"
#include "Table.h"
#include "Command.h"
#include "FireCometCommand.h"
#include "CometRaw.h"

class InputHandler
{

private:
    Command *fireLeftCometCommand;
    Command *fireRightCometCommand;
    Racket &rightRacket_;
    Racket &leftRacket_;
    Table &rightTable_;
    Table &leftTable_;
    CometRaw &rightComet_;
    CometRaw &leftComet_;

public:
    // Constructor
    InputHandler(Racket &rightRacket, Racket &leftRacket, Table &rightTable, Table &leftTable, CometRaw &rightComet, CometRaw &leftComet)
        : rightRacket_(rightRacket), 
          leftRacket_(leftRacket), 
          rightTable_(rightTable), 
          leftTable_(leftTable), 
          rightComet_(rightComet), 
          leftComet_(leftComet)

    {
        fireLeftCometCommand  = new FireCometCommand(leftComet_, leftRacket_);
        fireRightCometCommand = new FireCometCommand(rightComet_, rightRacket_);
    }

    void loop()
    {
        rightComet_.loop();
        leftComet_.loop();

        if (rightRacket_.isHit()) fireLeftCometCommand->execute(); 
        if (leftRacket_.isHit())  fireRightCometCommand->execute(); 
        if (rightTable_.isHit());
        if (leftTable_.isHit());
    }

    // Methods to bind commands...
};

#endif