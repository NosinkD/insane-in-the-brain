#ifndef TIME_H
#define TIME_H

#include "Internal.h"

class Time {

public:

    ~Time(void);
    static Time * getSingleton(void);

    void setDateFormat(std::string dateFormat);
    void setTimeFormat(std::string timeFormat);

    std::string getDate(void);
    std::string getTime(void);

protected:

private:

    Time(void);
    static Time * m_singleton;

    void updateTime(void);

    std::string m_date_format;
    std::string m_time_format;

    //Log * m_log;

    time_t m_now;
    struct tm m_tstruct;
    char m_buf[10];

};

#endif // TIME_H