#ifndef BARRIER_DISPLAY_HPP
#define BARRIER_DISPLAY_HPP

#include <SFML/Graphics.hpp>
#include <ranges>
#include "Barrier.hpp"

using Point = std::tuple<double, double>;
using Line = std::tuple<Point, Point>;

class BarrierDisplay {
public:
    BarrierDisplay(const Barrier& barrier) :
        lines(buildVertexArray(barrier))
    {}

    void draw(sf::RenderWindow& window);

private:
    sf::VertexArray lines;

    sf::VertexArray buildVertexArray(const Barrier& barrier) const;
};


#endif  // BARRIER_DISPLAY_HPP
