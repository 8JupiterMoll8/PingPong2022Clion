#ifndef PINGPONG_H
#define PINGPONG_H

#pragma once

#include <Arduino.h>
#include "FastLED.h"
#include <SPI.h>
#include "printf.h"
#include "RF24.h"
#include "Reciver.hpp"
#include "ReciverData.hpp"
#include "PeaKDetector.hpp"
#include "ResponsiveAnalogRead.h"
#include "Counter.hpp"
#include "I_InputSensorBhv.hpp"
#include "InputSensorRaw.hpp"
#include "InputSensorSmooth.hpp"
#include "Piezo.hpp"
#include <EasyTransfer.h>
#include "Swing.hpp"
#include "SensorFusion.h"
#include "Mahony.hpp"
#include "Pressure.hpp"
#include "Speed.hpp"
#include "Racket.hpp"
#include "Table.h"
#include "BallwechselCounter.h"
#include "MoveNeopixel.h"
#include "Comet.h"
#include "Bargraph.h"
#include "CometRaw.h"
#include <EasyTransfer.h>
#include "ETSENDATA.h"
#include "CollisionDetector.h"
#include "InputHandler.h"


#include "BallWechselState.h" //! THIS HAS TO BE BEFORE THE STATEMACHINE
#include "BallWechselStateMachine.h"
#include "IdleState.h"
#include "StartState.h"
#include "A_Left_Table_LinksAufschlagState.h"
#include "B_Right_Table_LinksAufschalgState.h"
#include "BallwechselCounter.h"

#endif