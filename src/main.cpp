#include <iostream>
#include <SFML/Graphics.hpp> 
#include <SFML/Window/Window.hpp>
#include "solver.hpp"
#include "renderer.hpp"
#include "number_generator.hpp"
#include "math.hpp"
#include <SFML/Window/ContextSettings.hpp>


static sf::Color getRainbow(float t){
    const float r = sin(t);
    const float g = sin(t+0.33f*2.0f*Math::pi);
    const float b = sin(t+0.66f*2.0f*Math::pi);
    return {static_cast<uint8_t>(255.0f*r*r), 
    static_cast<uint8_t>(255.0f*g*g), 
    static_cast<uint8_t>(255.0f*b*b)};

};

int32_t main(int32_t, char*[]){
    constexpr int32_t window_width = 1000;
    constexpr int32_t window_height =1000;
    
    sf::ContextSettings settings; 
    settings.antialiasingLevel =1; 
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Verlet", sf::Style::Default, settings);
    const uint32_t frame_rate =60; 
    window.setFramerateLimit(frame_rate);

    Solver solver; 
    Renderer renderer{window};

    solver.setConstraint({static_cast<float>(window_width) *0.5f, static_cast<float>(window_height)*0.5f}, 450.0f);
    solver.setSubStepsCount(8);
    solver.setStimulationUpdateRate(frame_rate);

    //Simulation Attributes
    const float         object_spawn_delay  = 3.00f;
    const float         object_spawn_speed  = 1200.0f;
    const sf::Vector2f  object_spawn_position={500.0f, 200.0f};
    const float         object_min_radius   = 50.0f; 
    const float         object_max_radius   = 50.0f; 
    const uint32_t      max_objects_count   = 3; 
    const float         max_angle           = 1.0f; 

    sf::Clock clock;

    //Main Loop 
    while (window.isOpen()) {
      sf::Event event{};
      while(window.pollEvent(event)){
        if(event.type==sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
          window.close();
        }
      }

      if(solver.getObjectsCount() <max_objects_count && clock.getElapsedTime().asSeconds()>=object_spawn_delay){
        clock.restart(); 
        auto& object = solver.addObject(object_spawn_position, RNGf::getRange(object_min_radius, object_max_radius));
        const float t = solver.getTime();
        const float angle = max_angle * sin(t)+Math::pi*0.5f;
        solver.setObjectVelocity(object, object_spawn_speed * sf::Vector2f{cos(angle), sin(angle)}); 
      }

      solver.update();
      window.clear(sf::Color::White);
      renderer.render(solver);
      window.display();
    }



    return 0;
}
