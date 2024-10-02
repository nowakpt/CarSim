
#include "Car.hpp"
#include "Gearbox.hpp"


void Gearbox::selectGear(Gear gear) {
    if (gear == selectedGear) return;
    if (std::abs(car.getCurrentSpeed()) > 1.0) return;
    if (car.getBrake() < 0.2) return;

    selectedGear = gear;
    currentGear = Gear::N;
    gearShiftCooldown = GEAR_SHIFT_COOLDOWN;
}

void Gearbox::advanceTime(double dt) {
    if (currentGear != selectedGear) {
        gearShiftCooldown -= dt;

        if (gearShiftCooldown <= 0.0) {
            currentGear = selectedGear;
            gearShiftCooldown = 0.0;
        }
    }
}


