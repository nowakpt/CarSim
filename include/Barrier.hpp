#ifndef BARRIER_HPP
#define BARRIER_HPP

#include "Car.hpp"

using Point = std::tuple<double, double>;
using Line = std::tuple<Point, Point>;

class Barrier {
public:
    Barrier(std::vector<Point>&& vertices) :
        vertices(vertices)
    {}

    const std::vector<Point>& getVertices() const {
        return vertices;
    }

private:
    const std::vector<Point> vertices;
};


#endif  // BARRIER_HPP
