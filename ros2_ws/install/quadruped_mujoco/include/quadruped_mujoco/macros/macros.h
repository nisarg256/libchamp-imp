#ifndef MACROS_H
#define MACROS_H

#define SECONDS_TO_MICROS 1000000
#define MICROS_TO_SECONDS 1.0/1000000.0

#ifdef ARDUINO
    #include <Arduino.h>
    inline unsigned long time_us()
    {
        return micros();
    }
#else
    #include <chrono>
    inline unsigned long time_us()
    {
        return std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
    }
#endif

#define MICROS_TO_SEC(micros) (micros / 1000000.0)
#define DEG_TO_RAD(deg) (deg * 0.01745329251994329576923690768489)
#define RAD_TO_DEG(rad) (rad * 57.295779513082320876798154814105)

#endif 