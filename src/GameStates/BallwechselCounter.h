
#pragma once

#include "PingPong.h"

class BallwechselCounter {

public:
    BallwechselCounter(Racket &leftRacket, Racket &rightRacket, Table &leftTable, Table &rightTable) :
            leftRacket_(leftRacket), rightRacket_(rightRacket), leftTable_(leftTable), rightTable_(rightTable) {}

public:
    void loop() {

        printDebug();

        switch (state_) {

            case IDLE:
                state_ = LINKS_AUFSCHLAG_LEFT_RACKET;
                break;

            case LINKS_AUFSCHLAG_LEFT_RACKET:
                if (leftRacket_.isHit()) state_ = LINKS_AUFSCHLAG_LEFT_TABLE;
                break;

            case LINKS_AUFSCHLAG_LEFT_TABLE:
                if (leftRacket_.isHit() || rightRacket_.isHit() || rightTable_.isHit()) state_ = DOPPEL_FEHLER;
                if (leftTable_.isHit()) state_ = LINKS_AUFSCHLAG_RIGHT_TABLE;
                break;

            case LINKS_AUFSCHLAG_RIGHT_TABLE:
                if (leftRacket_.isHit() || rightRacket_.isHit() || leftTable_.isHit()) state_ = DOPPEL_FEHLER;
                if (rightTable_.hitSum() == 1) state_ = LINKS_BALLWECSHEL_RIGHT_RACKET;
                break;

            case LINKS_BALLWECSHEL_RIGHT_RACKET:
                if (leftRacket_.isHit() || rightTable_.hitSum() || leftTable_.hitSum()) state_ = DOPPEL_FEHLER;
                if (rightRacket_.isHit()) state_ = LINKS_BALLWECHSEL_LEFT_TABLE;
                break;

            case LINKS_BALLWECHSEL_LEFT_TABLE:
                if (leftRacket_.isHit() || rightRacket_.isHit() || rightTable_.hitSum()) state_ = DOPPEL_FEHLER;
                if (leftTable_.isHit()) state_ = LINKS_BALLWECHSEL_LEFT_RACKET;
                break;

            case LINKS_BALLWECHSEL_LEFT_RACKET:
                if (leftTable_.isHit() || rightRacket_.isHit() || leftTable_.isHit()) state_ = DOPPEL_FEHLER;
                if (leftRacket_.isHit()) state_ = LINKS_BALLWECHSEL_RIGHT_TABLE;
                break;

            case LINKS_BALLWECHSEL_RIGHT_TABLE:
                if (leftRacket_.isHit() || rightRacket_.isHit() || leftTable_.hitSum()) state_ = DOPPEL_FEHLER;
                if (rightTable_.isHit()) state_ = COUNT_BALLWECHSEL;
                break;

            case COUNT_BALLWECHSEL:
                ++totalBallWechsel;
                state_ = LINKS_BALLWECHSEL_LEFT_TABLE;
                break;

            case DOPPEL_FEHLER:
                state_ = IDLE;
                break;

            case FINISH_GAME:
                break;

        } // end switch


    }// end loop


private:
    Racket &leftRacket_;
    Racket &rightRacket_;
    Table &leftTable_;
    Table &rightTable_;
    int totalBallWechsel = 0;

private:
    enum States {
        /*00*/IDLE,
        /*01*/LINKS_AUFSCHLAG_LEFT_RACKET,
        /*02*/LINKS_AUFSCHLAG_LEFT_TABLE,
        /*03*/LINKS_AUFSCHLAG_RIGHT_TABLE,
        /*04*/LINKS_BALLWECSHEL_RIGHT_RACKET,
        /*05*/LINKS_BALLWECHSEL_LEFT_TABLE,
        /*06*/LINKS_BALLWECHSEL_LEFT_RACKET,
        /*07*/LINKS_BALLWECHSEL_RIGHT_TABLE,
        /*08*/COUNT_BALLWECHSEL,
        /*09*/DOPPEL_FEHLER,
        /*10*/FINISH_GAME
    };

private:
    States state_ = IDLE;
    byte currentState_ ;
    byte lastState_ ;

private:
    void printDebug() {
//        Serial.print("LastState:");
//        Serial.println(lastState_);
//        Serial.print("CurrentState ");
//        Serial.println(currentState_);

        if ( lastState_ != state_) {
            Serial.print("State : ");
            Serial.println(state_);
            if(state_ == 0) Serial.println("Waiting for LINKS_AUFSCHLAG oder RECHTS_AUFSCHLAG");
            if(state_ == 9) Serial.println("DOPPELFEHLLER");
        }
          lastState_ = state_;


    }


};
