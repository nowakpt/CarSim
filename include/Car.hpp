#ifndef CAR_HPP
#define CAR_HPP

#include <algorithm>
#include <tuple>
#include "Gearbox.hpp"


class Car {
public:
    Car(double x, double y, double heading, double length = 130.0, double width = 60.0) :
        LENGTH(length),
        WIDTH(width),
        x(x),
        y(y),
        heading(heading),
        speed(0.0),
        throttleInput(0.0),
        steeringInput(0.0),
        brakeInput(0.0),
        gearbox(*this)
    {}

    void setThrottle(double input) {
        throttleInput = std::clamp(input, 0.0, 1.0);
    }

    void setSteering(double input) {
        steeringInput = std::clamp(input, -1.0, 1.0);
    }

    void setBrake(double input) {
        brakeInput = std::clamp(input, 0.0, 1.0);
    }

    void changeThrottle(double delta) {
        throttleInput = std::clamp(throttleInput + delta, 0.0, 1.0);
    }

    void changeSteering(double delta) {
        steeringInput = std::clamp(steeringInput + delta, -1.0, 1.0);
    }

    void changeBrake(double delta) {
        brakeInput = std::clamp(brakeInput + delta, 0.0, 1.0);
    }

    void setGear(Gearbox::Gear newGear) {
        gearbox.selectGear(newGear);
    }

    void advanceTime(double dt);

    std::tuple<double, double, double> getPosition() const {
        return {x, y, heading};
    }

    double getThrottle() const {
        return throttleInput;
    }

    double getSteering() const {
        return steeringInput;
    }

    double getBrake() const {
        return brakeInput;
    }

    Gearbox::Gear getSelectedGear() const {
        return gearbox.getSelectedGear();
    }

    double getCurrentSpeed() const {
        return speed;
    }

    const double LENGTH;
    const double WIDTH;

private:
    double x;
    double y;
    double heading;
    double speed;

    double throttleInput;
    double steeringInput;
    double brakeInput;
    Gearbox gearbox;

    static constexpr double TURNING_COEFF = 0.006;
    static constexpr double MAX_POWER = 1000.0;
    static constexpr double MAX_BRAKING = 2000.0;
    static constexpr double ENERGY_LOSS_COEFF = 1.0;
};



#endif  // CAR_HPP
