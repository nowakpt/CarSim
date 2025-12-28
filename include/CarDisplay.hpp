#ifndef CAR_DISPLAY_HPP
#define CAR_DISPLAY_HPP

#include <SFML/Graphics.hpp>
#include "Car.hpp"


class CarDisplay {
public:
    CarDisplay(const Car& car) :
        car(car)
    {}

    void draw(sf::RenderWindow& window);

private:
    const Car& car;
};


#endif  // CAR_DISPLAY_HPP
