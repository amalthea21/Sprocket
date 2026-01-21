#pragma once

class SampleGenerator {
public:
    enum Shape {
        SINE, SQUARE, TRIANGLE, SAWTOOTH
    };

    float* generateSamples(Shape shape, float time, float frequency);

private:
    float calculateSine(float degrees);
    float* generateSine(float sampleSize, float frequency);

    float *generateSquare(float sampleSize, float frequency);

    float *generateTriangle(float sampleSize, float frequency);

    float *generateSawtooth(float sampleSize, float frequency);
};