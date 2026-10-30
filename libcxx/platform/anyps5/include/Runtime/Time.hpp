#ifndef ANYLIBCXX_RUNTIME_TIME_HPP
#define ANYLIBCXX_RUNTIME_TIME_HPP

struct GuestTm {
    int Seconds;
    int Minutes;
    int Hours;
    int MonthDay;
    int Month;
    int Year;
    int WeekDay;
    int YearDay;
    int DaylightSaving;
    long long GmtOffset;
    const char* Zone;
};

#endif
