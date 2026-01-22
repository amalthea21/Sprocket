#include "../include/Math.h"


#pragma region Trigonometry
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

float Math::Cosine(float degrees) {
    constexpr float PI = 3.14159265359f;

    degrees = Math::fmod(degrees, 360.0f);
    if (degrees < 0) degrees += 360.0f;

    float radians = degrees * PI / 180.0f;

    float term = 1.0f;
    float sum  = 1.0f;

    for (int i = 1; i <= 10; i++)
    {
        term *= -radians * radians / ((2 * i - 1) * (2 * i));
        sum += term;
    }

    return sum;
}

float Math::Tangent(float degrees) {
    float cos_val = Cosine(degrees);

    if (cos_val == 0.0f || (cos_val > -0.0001f && cos_val < 0.0001f)) {
        // IEEE 754 NaN: exponent all 1s, mantissa non-zero
        unsigned int nan_bits = 0x7FC00000;
        return *reinterpret_cast<float*>(&nan_bits);
    }

    return Sine(degrees) / cos_val;
}

float Math::Cotangent(float degrees) {
    float sin_val = Sine(degrees);

    if (sin_val == 0.0f || (sin_val > -0.0001f && sin_val < 0.0001f)) {
        // IEEE 754 NaN: exponent all 1s, mantissa non-zero
        unsigned int nan_bits = 0x7FC00000;
        return *reinterpret_cast<float*>(&nan_bits);
    }

    return Cosine(degrees) / sin_val;
}

float Math::Hann(float n, float N) {
    if (N <= 0.0f || n < 0.0f) {
        return 0.0f;
    }

    float cos_arg = 360 * n / N;

    return 0.5f * (1.0f - Cosine(cos_arg));
}
#pragma endregion Trigonometry

float Math::min(float a, float b) {
    if (a < b) return a;
    return b;
}

float Math::abs(float a) {
    if (a < 0) return -a;
    return a;
}

float Math::fmod(float x, float y) {
    if (y == 0.0f) {
        // IEEE 754 NaN: exponent all 1s, mantissa non-zero
        unsigned int nan_bits = 0x7FC00000;
        return *reinterpret_cast<float*>(&nan_bits);
    }

    float quotient = x / y;
    float truncated_quotient = static_cast<int>(quotient);

    float remainder = x - truncated_quotient * y;

    return remainder;
}