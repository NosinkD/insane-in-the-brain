#ifndef LOG_H
#define LOG_H

#include "Internal.h"
#include "File.h"
#include "Time.h"

class Log {

public:

    enum Type {
        AUDIO, DIRECTOR, FILE, GAMEOBJECT, INPUT, LOG, SCENE, TIME, VIDEO
    };

    ~Log(void);
    static Log * getSingleton(void);

    void report(Log::Type type, std::string message);

    std::string getLast(void);
    std::string getLast(Log::Type type);
    std::string get(int index = -1);

    void save(std::string path = "log/");

protected:

private:

    struct Report {
        Log::Type type;
        std::string message;
    };

    Log(void);
    static Log * m_singleton;

    Log::Report format(Log::Type type, std::string message);

    std::vector<Log::Report> m_log;
    File * m_file;
    Time * m_time;

};

#endif // LOG_H