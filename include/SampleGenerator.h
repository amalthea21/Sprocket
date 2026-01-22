#pragma once

class SampleGenerator {
public:
    enum Shape {
        SINE, SQUARE, TRIANGLE, SAWTOOTH,
        COSINE, TANGENT, COTANGENT,
        HANN, PHASED_HANN
    };

    static float* generateSamples(Shape shape, float time, float frequency);

private:
    // Primitive
    static float* generateSine(float sampleSize, float frequency);
    static float *generateSquare(float sampleSize, float frequency);
    static float *generateTriangle(float sampleSize, float frequency);
    static float *generateSawtooth(float sampleSize, float frequency);

    // Trigonometry
    static float* generateCosine(float sampleSize, float frequency);
    static float* generateTangent(float sampleSize, float frequency);
    static float* generateCotangent(float sampleSize, float frequency);

    static float* generateHann(float sampleSize, float frequency);
    static float* generatePhasedHann(float sampleSize, float frequency);
};