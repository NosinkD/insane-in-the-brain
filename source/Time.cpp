#include "Time.h"

Time * Time::m_singleton = nullptr;

Time::~Time(void){
    //this->m_log->report(Log::TIME, "Time system closed.");
}

Time * Time::getSingleton(void){
    if(!m_singleton) m_singleton = new Time();
    return m_singleton;
}

void Time::setDateFormat(std::string dateFormat){
    this->m_date_format = dateFormat;
}

void Time::setTimeFormat(std::string timeFormat){
    this->m_time_format = timeFormat;
}

std::string Time::getDate(void){
    updateTime();
    strftime(m_buf, sizeof(m_buf), this->m_date_format.c_str(), &m_tstruct);
    return std::string(m_buf);
}

std::string Time::getTime(void){
    updateTime();
    strftime(m_buf, sizeof(m_buf), this->m_time_format.c_str(), &m_tstruct);
    return std::string(m_buf);
}

Time::Time(void){
    //this->m_log = Log::getSingleton();
    //this->m_log->report(Log::TIME, "Time system started.");

    this->m_date_format = "%d-%m-%Y";
    this->m_time_format = "%H-%M-%S";
}

void Time::updateTime(void){
    m_now = time(nullptr);
    m_tstruct = *localtime(&m_now);
}