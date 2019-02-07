#ifndef FILE_H
#define FILE_H

#include "Internal.h"

class File {

public:

    ~File(void);
    static File * getSingleton(void);

    std::string readAllText(const char * path);

protected:

public:

    File(void);
    static File * m_singleton;

};

#endif // FILE_H