//
//  Timer.h
//  NodeProjectXCode
//
//  Created by Josh on 5/11/16.
//  Copyright © 2016 Jforou. All rights reserved.
//

#ifndef MODEL_TIMER_H_
#define MODEL_TIMER_H_

#include <time.h>

class Timer
{
private:
    clock_t executionTime;
public:
    Timer();
    virtual ~Timer();
    void startTimer();
    void stopTimer();
    void resetTimer();
    void displayTimerInformation();
    long getExecutionTimeInMicroseconds();
};

#endif /* MODEL_TIMER_H_ */