#include <iostream>
#include <SFML/Graphics.hpp>
#include "solver.hpp"
#include "renderer.hpp"
#include "number_generator.hpp"
#include "math.hpp"

using namespace std; 
using namespace sf;

static Color getRainbow(float t){
    const float r = sin(t);
    const float g = sin(t+0.33f*2.0f*Math::pi);
    const float b = sin(t+0.66f*2.0f*Math::pi);
    return {static_cast<uint8_t>(255.0f*r*r), static_cast<uint8_t>(255.0f*g*g), static_cast<uint8_t>(255.0f*b*b)};

};
