#include <SFML/Graphics/Color.hpp>
#include "BarrierDisplay.hpp"


sf::VertexArray BarrierDisplay::buildVertexArray(const Barrier& barrier) const {
    const auto& vertices = barrier.getVertices();
    sf::VertexArray va(sf::LineStrip, vertices.size());

    for (int i = 0; i < vertices.size(); ++i) {
        auto [x, y] = vertices[i];
        va[i].position = sf::Vector2f(x, y);
        va[i].color = sf::Color(0x888888FF);
    }

    return va;
}


void BarrierDisplay::draw(sf::RenderWindow& window) {
    window.draw(lines);
}

