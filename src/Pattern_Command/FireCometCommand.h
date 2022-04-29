#pragma once

class FireCometCommand : public Command {

private: CometRaw &comet_;
private: Racket &racket_;
public:  FireCometCommand(CometRaw &comet, Racket &racket) : comet_(comet), racket_(racket) {}

public: virtual void execute() override{
    printRacketSpeedAndHitPeak();

    float minIn = 0.00;
    float maxIn = 27.0; // Todo : Find right Value to  calibrate the sensitivity
    float speed = constrain(racket_.hitPeak(), minIn, maxIn);
 // float speed = constrain(racket_.speed(),   minIn, maxIn);

    comet_.start();
    comet_.setSpeed       (map(speed, minIn, maxIn, 1.0, 10.0));
    comet_.setWidth       (map(speed, int(minIn), int(maxIn), 1, 25));
    comet_.setFadeSize    (map(speed, minIn, maxIn, 223.0, 134.0));
    comet_.setMidiVelocity(map(speed, minIn, maxIn, 0.0, 127.0));
  }

private: void printRacketSpeedAndHitPeak(){
    Serial.println("Firing Comet");
    Serial.print("Racket-Speed : ");   Serial.println(racket_.speed());
    Serial.print("Racket-HitPeak : "); Serial.println(racket_.hitPeak());
  }
};
