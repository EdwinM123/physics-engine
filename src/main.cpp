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
    const float g = sin(t);
    const float b = sin(t);
};