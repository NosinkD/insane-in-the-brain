#include "File.h"

File * File::m_singleton = nullptr;

File::~File(void){

}

File * File::getSingleton(void){
    if(!m_singleton){
        m_singleton = new File();
    }
    return m_singleton;
}

const char * File::readAllText(const char * path){
    std::fstream file;
    file.open(path, std::fstream::in);
    std::string line = "", doc = "";
    if (file.is_open()) {
        do {
            std::getline(file, line);
            doc += line;
        } while (!file.eof());
        file.close();
    }
    return doc.c_str();
}

File::File(void){

}