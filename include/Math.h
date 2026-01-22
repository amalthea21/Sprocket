#pragma once

class Math {
public:
    static float Sine(float degrees);
    static float Cosine(float degrees);
    static float Tangent(float degrees);
    static float Cotangent(float degrees);
    static float Hann(float n, float N);

    static float fmod(float x, float y);
    static float min(float a, float b);
    static float abs(float a);
};
