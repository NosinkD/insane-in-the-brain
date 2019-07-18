#include "Log.h"

Log * Log::m_singleton = nullptr;

Log::Log(void){
    this->m_file = File::getSingleton();
    this->m_log = "";
}

Log * Log::getSingleton(void){
    if(!m_singleton){
        m_singleton = new Log();
    }
    return m_singleton;
}

Log::~Log(void){
    this->m_log.clear();
}