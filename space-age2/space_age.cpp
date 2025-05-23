#include "space_age.h"

namespace space_age {
    // unnamed namespace limits the scope of contents to this file ONLY (internal linkage)
    namespace {
        // use constexpr to define the orbital periods especially considering the fact that it is compile time constant.
        constexpr double ONE_EARTH_YEAR_IN_SECONDS = 31557600;
        // ex). 3 earth yrs in secs is 94,672,800. 
        // orbital periods in earth years
        constexpr double MERCURY_ORBITAL_PERIOD_IN_EARTH_YEARS = 0.2408467;
        constexpr double VENUS_ORBITAL_PERIOD_IN_EARTH_YEARS = 0.61519726;
        constexpr double MARS_ORBITAL_PERIOD_IN_EARTH_YEARS = 1.8808158;
        constexpr double JUPITER_ORBITAL_PERIOD_IN_EARTH_YEARS = 11.862615;
        constexpr double SATURN_ORBITAL_PERIOD_IN_EARTH_YEARS = 29.447498;
        constexpr double URANUS_ORBITAL_PERIOD_IN_EARTH_YEARS = 84.016846;
        constexpr double NEPTUNE_ORBITAL_PERIOD_IN_EARTH_YEARS = 164.79132;

        // Helper function to calculate age on different planets
        double calculate_age(long long age_in_seconds, double planet_orbital_period_in_earth_years) {
            //return (age_in_seconds / ONE_EARTH_YEAR_IN_SECONDS) * planet_orbital_period_in_earth_years;
            return age_in_seconds / ONE_EARTH_YEAR_IN_SECONDS / planet_orbital_period_in_earth_years;
        }
    }

    // Constructor
    space_age::space_age(long long seconds):age_in_seconds_(seconds){}  

    // Public member functions
    // again utilizing long long bc no decimals need to be stored.
    long long space_age::seconds() const {
        return age_in_seconds_;
    }

    // now utilizing the double variable bc we must account for decimals from this point for ages.
    // calculates earth age
    double space_age::on_earth() const {
        return calculate_age(age_in_seconds_, 1.0);
    }

    // calculates mercury age
    double space_age::on_mercury() const {
        return calculate_age(age_in_seconds_, MERCURY_ORBITAL_PERIOD_IN_EARTH_YEARS);
    }

    // calculates venus age
    double space_age::on_venus() const {
        return calculate_age(age_in_seconds_, VENUS_ORBITAL_PERIOD_IN_EARTH_YEARS);
    }

    // calculates mars age
    double space_age::on_mars() const {
        return calculate_age(age_in_seconds_, MARS_ORBITAL_PERIOD_IN_EARTH_YEARS);
    }

    // calculates jupiter age
    double space_age::on_jupiter() const {
        return calculate_age(age_in_seconds_, JUPITER_ORBITAL_PERIOD_IN_EARTH_YEARS);
    }

    // calculates saturn age
    double space_age::on_saturn() const {
        return calculate_age(age_in_seconds_, SATURN_ORBITAL_PERIOD_IN_EARTH_YEARS);
    }

    // calculates uranus age    
    double space_age::on_uranus() const {
        return calculate_age(age_in_seconds_, URANUS_ORBITAL_PERIOD_IN_EARTH_YEARS);
    }

    // calculates neptune age
    double space_age::on_neptune() const {
        return calculate_age(age_in_seconds_, NEPTUNE_ORBITAL_PERIOD_IN_EARTH_YEARS);
    }

} //namespace space_age