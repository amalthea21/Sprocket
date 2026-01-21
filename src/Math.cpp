#include "../include/Math.h"

#include <cmath>


float Math::calculateSine(float degrees) {
    const float PI = 3.14159265359f;

    degrees = std::fmod(degrees, 360.0f);
    if (degrees < 0) degrees += 360.0f;

    float radians = degrees * PI / 180.0f;

    float term = radians;
    float sum  = radians;

    for (int i = 1; i <= 10; i++)
    {
        term *= -radians * radians / ((2 * i) * (2 * i + 1));
        sum += term;
    }

    return sum;
}
