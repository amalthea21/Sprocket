#pragma once

class SampleGenerator {
public:
    enum Shape {
        SINE, SQUARE, TRIANGLE, SAWTOOTH
    };

    static float* generateSamples(Shape shape, float time, float frequency);

private:
    static float* generateSine(float sampleSize, float frequency);

    static float *generateSquare(float sampleSize, float frequency);

    static float *generateTriangle(float sampleSize, float frequency);

    static float *generateSawtooth(float sampleSize, float frequency);
};