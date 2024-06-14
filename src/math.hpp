#pragma once 
#include <SFML/System/Vector2.hpp>

using namespace sf;

struct Math {
    static constexpr float pi=3.1415936f; 
    static Vector2f dot(Vector2f v1, Vector2f v2){
        return (v1.x*v2.x, v1.y*v2.y);
    }
};