#include "Log.h"

Log * Log::m_singleton = nullptr;

Log::~Log(void){
    report(LOG, "Log system closed."); 
    updateTime(); save();
    this->m_log.clear();
    this->m_file = nullptr;
}

Log * Log::getSingleton(void){
    if(!m_singleton) m_singleton = new Log();
    return m_singleton;
}

void Log::report(Log::Type type, std::string message){
    this->m_log.push_back(format(type, message));
    save();
}

std::string Log::getLast(void){
    if ((this->m_log.size() > 0)){
        return this->m_log.back().message;
    }
    return "";
}

std::string Log::getLast(Log::Type type){
    bool found = false;
    std::vector<Log::Report>::iterator itLast = this->m_log.end();
    std::vector<Log::Report>::iterator itFirst = this->m_log.begin();
    while((itLast != itFirst) && (!found)){
        if (itLast->type != type){
            itLast--;
        } else {
            found = true;
        }
    }
    if (found) return itLast->message;
    return "";
}

std::string Log::get(int index){
    if ((index >= 0) && (index < static_cast<int>(this->m_log.size()))){
        return this->m_log.at(index).message;
    }
    return "";
}

void Log::save(std::string path){
    strftime(this->m_buf, sizeof(this->m_buf), "%d-%m-%y", &this->m_tstruct); std::string date = std::string(this->m_buf);
    strftime(this->m_buf, sizeof(this->m_buf), "%H.%M.%S", &this->m_tstruct); std::string time = std::string(this->m_buf);
    std::string filename = date + " " + time + ".log";
    std::string log = "";
    std::vector<Log::Report>::iterator itFirst = this->m_log.begin();
    std::vector<Log::Report>::iterator itLast = this->m_log.end();
    while(itFirst != itLast){
        log += itFirst->message + "\n";
        itFirst++;
    }
    std::cout << "File Name: " << filename << std::endl << "Log:" << std::endl << log << std::endl << std::endl;
    //this->m_file->writeText(path, filename, log);
}

Log::Log(void){
    report(LOG, "Log system started.");
    this->m_file = File::getSingleton();
}

Log::Report Log::format(Log::Type type, std::string message){
    Report rt; rt.type = type; updateTime();
    rt.message = "[" + getTime() + "]";
    switch (type) {
    case AUDIO:      rt.message += "[AUDIO]";      break;
    case DIRECTOR:   rt.message += "[DIRECTOR]";   break;
    case FILE:       rt.message += "[FILE]";       break;
    case GAMEOBJECT: rt.message += "[GAMEOBJECT]"; break;
    case INPUT:      rt.message += "[INPUT]";      break;
    case LOG:        rt.message += "[LOG]";        break;
    case SCENE:      rt.message += "[SCENE]";      break;
    case TIME:       rt.message += "[TIME]";       break;
    case VIDEO:      rt.message += "[VIDEO]";      break;
    default: break;
    }
    rt.message += " " + message;
    return rt;
}

void Log::updateTime(void){
    this->m_now = time(nullptr);
    this->m_tstruct = *localtime(&this->m_now);
}

std::string Log::getTime(void){
    strftime(this->m_buf, sizeof(this->m_buf), "%H:%M:%S", &this->m_tstruct);
    return std::string(this->m_buf);
}