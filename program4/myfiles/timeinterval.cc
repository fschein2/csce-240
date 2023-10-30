// Copyright 2023 fschein
#include"timeinterval.h"
#include"timeofday.h"
#include<iostream>
using std::cout;
using std::endl;
#include<string>
using std::string;

TimeInterval::TimeInterval() :
  start_(), end_() {
}

TimeInterval::TimeInterval(const TimeOfDay& s, const TimeOfDay& e) {
  start_.SetHour(s.GetHour());
  start_.SetMinute(s.GetMinute());
  start_.SetSecond(s.GetSecond());

  if (s.GetHour() > e.GetHour()) {
    end_.SetHour(s.GetHour());
    end_.SetMinute(s.GetMinute());
    end_.SetSecond(s.GetSecond());
  } else if (s.GetHour() == e.GetHour()) {
      if (s.GetMinute() > e.GetMinute()) {
        end_.SetHour(s.GetHour());
        end_.SetMinute(s.GetMinute());
        end_.SetSecond(s.GetSecond());
      } else if (s.GetMinute() == e.GetMinute()) {
          if (s.GetSecond() > e.GetSecond()) {
            end_.SetHour(s.GetHour());
            end_.SetMinute(s.GetMinute());
            end_.SetSecond(s.GetSecond());
          } else if (s.GetSecond() <= e.GetSecond()) {
              end_.SetHour(e.GetHour());
              end_.SetMinute(e.GetMinute());
              end_.SetSecond(e.GetSecond());
          }
      } else if (s.GetMinute() < e.GetMinute()) {
          end_.SetHour(e.GetHour());
          end_.SetMinute(e.GetMinute());
          end_.SetSecond(e.GetSecond());
      }
  } else if (s.GetHour() < e.GetHour()) {
      end_.SetHour(e.GetHour());
      end_.SetMinute(e.GetMinute());
      end_.SetSecond(e.GetSecond());
  }
}

TimeInterval::TimeInterval(const TimeOfDay& s, int l, string u) {
  start_.SetHour(s.GetHour());
  start_.SetMinute(s.GetMinute());
  start_.SetSecond(s.GetSecond());

  end_.SetHour(s.GetHour());
  end_.SetMinute(s.GetMinute());
  end_.SetSecond(s.GetSecond());

  int newHr = start_.GetHour();
  int newMin = start_.GetMinute();
  int newSec = start_.GetSecond();
  if (l > 0) {
    if (u == "hours") {
      if (newHr + l < 24) {
        newHr = newHr + l;
        end_.SetHour(newHr);
        end_.SetMinute(newMin);
        end_.SetSecond(newSec);
      }
    } else if (u == "minutes") {
        for (int i = 0; i < l; i++) {
          ++newMin;
          if (newMin == 60) {
            newHr = newHr + 1;
            newMin = 0;
          }
        }
        if (newHr < 24) {
          end_.SetHour(newHr);
          end_.SetMinute(newMin);
          end_.SetSecond(newSec);
        }
    } else if (u == "seconds") {
        for (int i = 0; i < l; i++) {
          ++newSec;
          if (newSec == 60) {
            ++newMin;
            newSec = 0;
            if (newMin == 60) {
              ++newHr;
              newMin = 0;
            }
          }
        }
        if (newHr < 24) {
          end_.SetHour(newHr);
          end_.SetMinute(newMin);
          end_.SetSecond(newSec);
        }
    }
  }
}

void TimeInterval::SetStartTime(const TimeOfDay& s) {
  if (s.GetHour() < end_.GetHour()) {
    start_.SetHour(s.GetHour());
    start_.SetMinute(s.GetMinute());
    start_.SetSecond(s.GetSecond());
  } else if (s.GetHour() == end_.GetHour()) {
      if (s.GetMinute() < end_.GetMinute()) {
        start_.SetMinute(s.GetMinute());
        start_.SetSecond(s.GetSecond());
      } else if (s.GetMinute() == end_.GetMinute()) {
          if (s.GetSecond() < end_.GetSecond()) {
            start_.SetSecond(s.GetSecond());
          }
      }
  }

  if (s.GetHour() == end_.GetHour() &&
      s.GetMinute() == end_.GetMinute() &&
      s.GetSecond() == end_.GetSecond() ) {
    start_.SetHour(s.GetHour());
    start_.SetMinute(s.GetMinute());
    start_.SetSecond(s.GetSecond());
  }
}

void TimeInterval::SetEndTime(const TimeOfDay& e) {
  if (e.GetHour() > start_.GetHour()) {
    end_.SetHour(e.GetHour());
    end_.SetMinute(e.GetMinute());
    end_.SetSecond(e.GetSecond());
  } else if (e.GetHour() == start_.GetHour()) {
      if (e.GetMinute() > start_.GetMinute()) {
        end_.SetMinute(e.GetMinute());
        end_.SetSecond(e.GetSecond());
      } else if (e.GetMinute() == start_.GetMinute()) {
          if (e.GetSecond() > start_.GetSecond()) {
            end_.SetSecond(e.GetSecond());
          }
      }
  }

  if (e.GetHour() == start_.GetHour() &&
      e.GetMinute() == start_.GetMinute() &&
      e.GetSecond() == start_.GetSecond()) {
    end_.SetHour(e.GetHour());
    end_.SetMinute(e.GetMinute());
    end_.SetSecond(e.GetSecond());
  }
}

void TimeInterval::SetEndTime(int l, string u) {
  int newHr = start_.GetHour();
  int newMin = start_.GetMinute();
  int newSec = start_.GetSecond();
  if (l > 0) {
    if (u == "hours") {
      if (newHr + l < 24) {
        newHr = newHr + l;
        end_.SetHour(newHr);
        end_.SetMinute(newMin);
        end_.SetSecond(newSec);
      }
    } else if (u == "minutes") {
        for (int i = 0; i < l; i++) {
          ++newMin;
          if (newMin == 60) {
            newHr = newHr + 1;
            newMin = 0;
          }
        }
        if (newHr < 24) {
          end_.SetHour(newHr);
          end_.SetMinute(newMin);
          end_.SetSecond(newSec);
        }
    } else if (u == "seconds") {
        for (int i = 0; i < l; i++) {
          ++newSec;
          if (newSec == 60) {
            ++newMin;
            newSec = 0;
            if (newMin == 60) {
              ++newHr;
              newMin = 0;
            }
          }
        }
        if (newHr < 24) {
          end_.SetHour(newHr);
          end_.SetMinute(newMin);
          end_.SetSecond(newSec);
        }
    }
  }
}

void TimeInterval::Print(bool military, bool seconds) {
  cout << "Start time: ";
  start_.Print(military, seconds);
  cout << "End time: ";
  end_.Print(military, seconds);
}