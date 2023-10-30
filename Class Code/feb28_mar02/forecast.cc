// Copyright 2023 fschein
// Implement the functionality of the Forecast class
#include"forecast.h"
#include"temperature.h"  // even though forcast.h includes temperature.h
                         // we'll list it here for clarity/transparency
#include<iostream>
using std::cout;
using std::endl;

Forecast::Forecast(double l, double h, double rain) :
  low_(-100, "Fahrenheit"), high_(200, "Fahrenheit"), chance_of_rain_(0) {
  // low_.SetValue(l);
  // low_.SetUnits("Fahrenheit");
  // chance_of_rain_ = 0;
  SetLow(l);
  SetHigh(h);
  SetChanceOfRain(rain);
}

void Forecast::SetChanceOfRain(double r) {
  if ( r >= 0 && r <= 100 )
    chance_of_rain_ = r;
}

void Forecast::SetLow(double l) {
  // at the moment we're assuming that low_ and high_ have the same units
  if ( l <= high_.GetValue() )
    low_.SetValue(l);
}

void Forecast:SetHigh(double h) {
  // same assumption that temp units are the same
  if ( h >= low_.GetValue() )
    high_.SetValue(h);
}

void Forecast::Print() const {
  cout << "Forecast low: ";
  low_.Print();  // note: low_ is a Temperature object, so it can call any 
                 // of the public members of Temperature
  cour << "Forecast high: ";
  high_.Print();
  cout << "Chance of Precipitation: " << chance_of_rain_ << endl;
}
