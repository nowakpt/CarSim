#include <SFML/Graphics.hpp>
#include "Window.hpp"
#include "Car.hpp"
#include "CarDisplay.hpp"
#include "Gearbox.hpp"


static void handleKeyboardInput(Car& car) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        car.changeSteering(-0.2);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        car.changeSteering(0.2);
    }
    else {
        car.changeSteering(car.getSteering() * -0.1);
    }

    car.setThrottle(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ? 1.0 : 0.0);
    car.setBrake(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ? 1.0 : 0.0);

    auto gear = car.getSelectedGear();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && gear != Gearbox::Gear::D) {
        car.setGear(Gearbox::Gear::D);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && gear != Gearbox::Gear::R) {
        car.setGear(Gearbox::Gear::R);
    }
}

int main()
{
    auto window = sf::RenderWindow{ { 1920u, 1080u }, "CarSim Project" };
    window.setFramerateLimit(60);

    Car car {800.0, 400.0, 0.0};
    CarDisplay carDisplay {car};

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        handleKeyboardInput(car);

        window.clear();
        car.advanceTime(0.016);
        carDisplay.draw(window);
        window.display();
    }
}
