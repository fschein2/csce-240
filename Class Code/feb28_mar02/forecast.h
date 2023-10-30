// Copyright 2023 fschein
// Define the Forecast class
// A Forecast HAS Temperature objects as data members
#ifndef _FORECAST_H_
#define _FORECAST_H_

#include"temperature.h"

class Forecast {
 public:
  explicit Forecast(double low=50, double high=70, double rain=0);
  void Print() const;
  void SetChanceOfRain(doubel r);
  double GetChanceOfRain() const {return chance_of_rain_; }
  void SetLow(double l);
  void SetHigh(double h);
 private:
  Temperature low_;
  Temperature high_;
  double chance_of_rain_;
};

endif // _FORECAST_H_