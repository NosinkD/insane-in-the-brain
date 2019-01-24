#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Component.h"

#include "Transform.h"

class GameObject {
public:

    std::vector<std::unique_ptr<Component>> components;

public:

    template<class ComponentType>
    void AddComponent(void);

    template<class ComponentType>
    ComponentType & GetComponent(void);

    template<class ComponentType>
    bool RemoveComponent(void);

};

template<class ComponentType>
void GameObject::AddComponent(void) {
    this->components.emplace_back(std::make_unique<ComponentType>());
}

template<class ComponentType>
ComponentType & GameObject::GetComponent() {
    for (auto && component : this->components) {
        if (component->IsClassType(ComponentType::Type)) {
            return * static_cast<ComponentType*>(component.get());
        }
    }
    return * std::unique_ptr<ComponentType>(nullptr);
}

template<class ComponentType>
bool GameObject::RemoveComponent(void) {
    if (this->components.empty()) {
        return false;
    }
    auto & index = std::find_if(this->components.begin(), this->components.end(), 
    [ classType = ComponentType::Type ]( auto & component ) { 
        return component->IsClassType( classType ); 
        } 
    );
    if (index != this->components.end()){
        this->components.erase(index);
        return true;
    }
    return false;
}

#endif // GAME_OBJECT_H