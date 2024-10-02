#include <cmath>
//#include <numbers>
#include <stdexcept>
#include "Car.hpp"

void Car::advanceTime(double dt)
{
    if (dt < 0.0) throw std::logic_error("negative time delta");

    gearbox.advanceTime(dt);

    auto targetSpeed = std::abs(speed);
    targetSpeed -= ENERGY_LOSS_COEFF * targetSpeed * dt;
    targetSpeed += throttleInput * MAX_POWER * dt * gearbox.getCurrentGearRatio();
    targetSpeed -=  brakeInput * MAX_BRAKING * dt;
    targetSpeed = std::max(targetSpeed, 0.0);
    speed = targetSpeed * gearbox.getDirection();

    double deltaHeading = speed * steeringInput * dt * TURNING_COEFF;
    heading += deltaHeading;

    constexpr auto TWO_PI = 2.0 * std::numbers::pi;
    if (heading < 0.0) heading += TWO_PI;
    else if (heading > TWO_PI) heading -= TWO_PI;

    // pivot point; located around rear axis and used to calculate car's rotation
    double xp = 0.45 * LENGTH * std::cos(heading);
    double yp = 0.45 * LENGTH * std::sin(heading);

    x += speed * dt * std::cos(heading) + (xp * (std::cos(deltaHeading) - 1.0) - yp * std::sin(deltaHeading));
    y += speed * dt * std::sin(heading) + (xp * std::sin(deltaHeading) + yp * (std::cos(deltaHeading) - 1.0));
}

