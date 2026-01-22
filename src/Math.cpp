#include "../include/Math.h"

#include <cmath>

float Math::fmod(float x, float y) {
    if (y == 0.0f)
        return NAN;

    float quotient = x / y;
    float truncated_quotient = static_cast<int>(quotient);

    float remainder = x - truncated_quotient * y;

    return remainder;
}

float Math::Sine(float degrees) {
    constexpr float PI = 3.14159265359f;

    degrees = Math::fmod(degrees, 360.0f);
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

float Math::min(float a, float b) {
    if (a < b) return a;
    return b;
}
