#include "GameObject.h"

const std::size_t Component::Type = std::hash<std::string>()(TO_STRING(Component));

CLASS_DEFINITION(Component, Transform);
CLASS_DEFINITION(Component, SpriteRenderer);