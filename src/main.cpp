#include <iostream>
#include <SFML/Graphics.hpp> 
#include <SFML/Window/Window.hpp>
#include "solver.hpp"
#include "renderer.hpp"
#include "number_generator.hpp"
#include "math.hpp"
#include <SFML/Window/ContextSettings.hpp>

using namespace std;  

static sf::Color getRainbow(float t){
    const float r = sin(t);
    const float g = sin(t+0.33f*2.0f*Math::pi);
    const float b = sin(t+0.66f*2.0f*Math::pi);
    return {static_cast<uint8_t>(255.0f*r*r), static_cast<uint8_t>(255.0f*g*g), static_cast<uint8_t>(255.0f*b*b)};

};

int32_t main(int32_t, char*[]){
    constexpr int32_t window_width = 1000;
    constexpr int32_t window_height =1000;

}