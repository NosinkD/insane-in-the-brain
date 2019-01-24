#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include <functional>
#include <vector>
#include <memory>
#include <algorithm>

#define TO_STRING(x) #x

#define CLASS_DECLARATION(classname)                                                        \
public:                                                                                     \
    static const std::size_t Type;                                                          \
    virtual bool IsClassType(const std::size_t classType) const override;                   \

#define CLASS_DEFINITION(parentclass, childclass)                                           \
const std::size_t childclass::Type = std::hash<std::string>()(TO_STRING(childclass));       \
bool childclass::IsClassType(const std::size_t classType) const {                           \
        if (classType == childclass::Type)                                                  \
            return true;                                                                    \
        return parentclass::IsClassType(classType);                                         \
}                                                                                           \

class Component {

public:

    virtual ~Component(void) = default;
    Component(){};

    static const std::size_t Type;
    virtual bool IsClassType(const std::size_t classType) const { return classType == Type; }

};

#endif // COMPONENT_H