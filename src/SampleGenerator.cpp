#include "../include/SampleGenerator.h"
#include "../include/Math.h"

float *SampleGenerator::generateSine(float sampleSize, float frequency) {
    const float PI = 3.14159265359f;
    const int SAMPLERATE = 44100;

    int samples_count = static_cast<int>(sampleSize * SAMPLERATE);
    float* samples = new float[samples_count];
    float t;

    for (int i = 0; i < samples_count; i++) {
        t = static_cast<float>(i) / SAMPLERATE;
        samples[i] = Math::Sine(2.0f * PI * frequency * t * 180.0f / PI);
    }

    return samples;
}

float *SampleGenerator::generateSawtooth(float sampleSize, float frequency) {
    const int SAMPLERATE = 44100;

    int samples_count = static_cast<int>(sampleSize * SAMPLERATE);
    float* samples = new float[samples_count];
    float t, phase;

    for (int i = 0; i < samples_count; i++) {
        t = static_cast<float>(i) / SAMPLERATE;

        phase = Math::fmod(t * frequency, 1.0f);

        samples[i] = 2.0f * phase - 1.0f;
    }

    return samples;
}

float *SampleGenerator::generateTriangle(float sampleSize, float frequency) {
    const int SAMPLERATE = 44100;

    int samples_count = static_cast<int>(sampleSize * SAMPLERATE);
    float* samples = new float[samples_count];
    float t, phase;

    for (int i = 0; i < samples_count; i++) {
        t = static_cast<float>(i) / SAMPLERATE;

        phase = Math::fmod(t * frequency, 1.0f);

        if (phase < 0.5f)
            samples[i] = 4.0f * phase - 1.0f;
        else samples[i] = 3.0f - 4.0f * phase;
    }

    return samples;
}

float *SampleGenerator::generateSquare(float sampleSize, float frequency) {
    const int SAMPLERATE = 44100;

    int samples_count = static_cast<int>(sampleSize * SAMPLERATE);
    float* samples = new float[samples_count];
    float t, phase;

    for (int i = 0; i < samples_count; i++) {
        t = static_cast<float>(i) / SAMPLERATE;

        phase = Math::fmod(t * frequency, 1.0f);

        if (phase < 0.5f)
            samples[i] = 1.0f;
        else samples[i] = -1.0f;
    }

    return samples;
}

float *SampleGenerator::generateSamples(Shape shape, float time, float frequency) {
    float* samples;

    switch (shape) {
        case Shape::SINE: samples = generateSine(time, frequency); break;
        case Shape::SQUARE: samples = generateSquare(time, frequency); break;
        case Shape::TRIANGLE: samples = generateTriangle(time, frequency); break;
        case Shape::SAWTOOTH: samples = generateSawtooth(time, frequency); break;
    }

    return samples;
}