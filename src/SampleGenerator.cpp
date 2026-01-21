#include "../include/SampleGenerator.h"

#include <cmath>

#pragma region Sine
float SampleGenerator::calculateSine(float degrees)
{
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


float *SampleGenerator::generateSine(float sampleSize, float frequency) {
    const float PI = 3.14159265359f;
    const int SAMPLERATE = 44100;

    int samples_count = static_cast<int>(sampleSize * SAMPLERATE);
    float* samples = new float[samples_count];

    for (int i = 0; i < samples_count; i++) {
        float t = static_cast<float>(i) / SAMPLERATE;
        samples[i] = calculateSine(2.0f * PI * frequency * t * 180.0f / PI);
    }

    return samples;
}
#pragma endregion

float *SampleGenerator::generateSawtooth(float sampleSize, float frequency) {
    float* samples;

    for (int i = 0; i < sampleSize; i++) {

    }

    return samples;
}

float *SampleGenerator::generateTriangle(float sampleSize, float frequency) {
    float* samples;

    for (int i = 0; i < sampleSize; i++) {

    }

    return samples;
}

float *SampleGenerator::generateSquare(float sampleSize, float frequency) {
    float* samples;

    for (int i = 0; i < sampleSize; i++) {

    }

    return samples;
}

float *SampleGenerator::generateSamples(Shape shape, float time, float frequency) {
    const int SAMPLERATE = 44100;
    float* samples;

    switch (shape) {
        case Shape::SINE: samples = generateSine(time, frequency); break;
        case Shape::SQUARE: samples = generateSquare(time, frequency); break;
        case Shape::TRIANGLE: samples = generateTriangle(time, frequency); break;
        case Shape::SAWTOOTH: samples = generateSawtooth(time, frequency); break;
    }

    return samples;
}