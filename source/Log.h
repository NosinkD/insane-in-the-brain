#ifndef LOG_H
#define LOG_H

#include "Internal.h"
#include "File.h"

class Log {

public:

    ~Log(void);
    static Log * getSingleton(void);

    void report(std::string message);

protected:

private:

    Log(void);
    static Log * m_singleton;

    std::string m_log;
    File * m_file;

};

#endif // LOG_H