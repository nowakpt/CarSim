#ifndef GEARBOX_HPP
#define GEARBOX_HPP

#include "Car.hpp"

class Car;

class Gearbox
{
public:
    enum class Gear {N, D, R};

    Gearbox(Car& car) :
        car(car),
        selectedGear(Gear::N),
        currentGear(Gear::N),
        gearShiftCooldown(0.0)
    {}

    double getDirection() const {
        switch (currentGear) {
            case Gear::D: return 1.0;
            case Gear::R: return -1.0;
            default: return 0.0;
        }
    }

    double getCurrentGearRatio() const {
        switch (currentGear) {
            case Gear::D: return 1.0;
            case Gear::R: return 0.4;
            default: return 0.0;
        }
    }

    Gear getCurrentGear() const {
        return currentGear;
    }

    Gear getSelectedGear() const {
        return selectedGear;
    }

    void selectGear(Gear gear);
    void advanceTime(double dt);

private:
    Car& car;

    Gear selectedGear;
    Gear currentGear;

    double gearShiftCooldown;

    // duration of a gear shift, in seconds
    static constexpr double GEAR_SHIFT_COOLDOWN = 0.8;
};


#endif  // GEARBOX_HPP
