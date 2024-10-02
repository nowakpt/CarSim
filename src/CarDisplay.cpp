#include <SFML/Graphics/Color.hpp>
#include "Car.hpp"
#include "Gearbox.hpp"
#include "CarDisplay.hpp"


void CarDisplay::draw(sf::RenderWindow& window)
{
    auto [x, y, heading] = car.getPosition();

    sf::RectangleShape rect {{car.LENGTH, car.WIDTH}};
    rect.setOrigin(car.LENGTH/2.0, car.WIDTH/2.0);
    rect.setPosition(x, y);
    rect.setRotation(heading * 180.0 / std::numbers::pi);

    switch (car.getSelectedGear()) {
        case Gearbox::Gear::D:
            rect.setFillColor(sf::Color::Green);
            break;
        case Gearbox::Gear::R:
            rect.setFillColor(sf::Color::Magenta);
            break;
        default:
            rect.setFillColor(sf::Color::Cyan);
    }

    window.draw(rect);
}

