#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "includes_std.h"

#include "Transform.h"

class GameObject {

public:

    template<class ComponentType>
    void addComponent(void);

    template<class ComponentType>
    ComponentType & getComponent(void);

    template<class ComponentType>
    bool removeComponent(void);

protected:

private:

    std::vector<std::unique_ptr<Component>> m_components;

};

template<class ComponentType>
void GameObject::addComponent(void) {
    this->m_components.emplace_back(std::make_unique<ComponentType>());
}

template<class ComponentType>
ComponentType & GameObject::getComponent() {
    for (auto && component : this->m_components) {
        if (component->IsClassType(ComponentType::Type)) {
            return * static_cast<ComponentType*>(component.get());
        }
    }
    return * std::unique_ptr<ComponentType>(nullptr);
}

template<class ComponentType>
bool GameObject::removeComponent(void) {
    if (this->m_components.empty()) {
        return false;
    }
    auto & index = std::find_if(this->m_components.begin(), this->m_components.end(), 
    [ classType = ComponentType::Type ]( auto & component ) { 
        return component->IsClassType( classType ); 
        } 
    );
    if (index != this->m_components.end()){
        this->m_components.erase(index);
        return true;
    }
    return false;
}

#endif // GAME_OBJECT_H