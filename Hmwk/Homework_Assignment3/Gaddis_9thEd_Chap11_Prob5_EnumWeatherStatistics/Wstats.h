/* 
 * File:   WSTATS.h
 * Author: Jacob Gower
 *
 * Created on April 5, 2021, 11:15 PM
 */

#ifndef WSTATS_H
#define WSTATS_H

struct WStats{
    float ttlRain=0, //Total Rain for a month in inches
          hiTemp=0, //Month's highest temperature in Fahrenheit
          loTemp=0, //Month's lowest temperature in Fahrenheit
          avTemp=0; //Month's average temperature in Fahrenheit
};


#endif /* WSTATS_H */

