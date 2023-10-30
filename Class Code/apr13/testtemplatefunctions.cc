// Copyright 2023 bhipp
// call functions written in mytemplatefunctions
#include<iostream>
using std::cout;
using std::endl;
#include<ctime>
#include<cstdlib>
#include"mytemplatefunctions.h"

int main() {
  int onenum = 15, anothernum = 37;
  MyTemplateFunctions::TradeValues<int>(onenum, anothernum);
  cout << "onenum = " << onenum << "\nanothernum = " << anothernum << endl;
  double real1 = -3, real2 =  -8.6;
  MyTemplateFunctions::TradeValues(real1, real2);
  cout << "real1 = " << real1 << "\nreal2 = " << real2 << endl;

  srand(time(0));
  const int kSize = 10;
  int somenumbers[kSize];
  for ( int i = 0; i < kSize; ++i )
    somenumbers[i] = rand() % 100;
  for ( int i = 0; i < kSize; ++i )
    cout << somenumbers[i] << " ";
  cout << endl;
  MyTemplateFunctions::QuickSort(somenumbers, 0, kSize - 1);
  for ( int i = 0; i < kSize; ++i )
    cout << somenumbers[i] << " ";

  return 0;
}
