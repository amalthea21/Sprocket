#include "../include/SampleGenerator.h"
#include "../include/Math.h"

#pragma region Primitive Shapes
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
#pragma endregion Primitive Shapes

#pragma region Trigonometric Shapes

float *SampleGenerator::generateCosine(float sampleSize, float frequency) {
    const float PI = 3.14159265359f;
    const int SAMPLERATE = 44100;

    int samples_count = static_cast<int>(sampleSize * SAMPLERATE);
    float* samples = new float[samples_count];
    float t;

    for (int i = 0; i < samples_count; i++) {
        t = static_cast<float>(i) / SAMPLERATE;
        samples[i] = Math::Cosine(2.0f * PI * frequency * t * 180.0f / PI);
    }

    return samples;
}

float *SampleGenerator::generateTangent(float sampleSize, float frequency) {
    const float PI = 3.14159265359f;
    const int SAMPLERATE = 44100;

    int samples_count = static_cast<int>(sampleSize * SAMPLERATE);
    float* samples = new float[samples_count];
    float t, tanValue;

    for (int i = 0; i < samples_count; i++) {
        t = static_cast<float>(i) / SAMPLERATE;
        tanValue = Math::Tangent(2.0f * PI * frequency * t * 180.0f / PI);

        if (tanValue > 10.0f) tanValue = 10.0f;
        if (tanValue < -10.0f) tanValue = -10.0f;

        samples[i] = tanValue / 10.0f;
    }

    return samples;
}

float *SampleGenerator::generateCotangent(float sampleSize, float frequency) {
    const float PI = 3.14159265359f;
    const int SAMPLERATE = 44100;

    int samples_count = static_cast<int>(sampleSize * SAMPLERATE);
    float* samples = new float[samples_count];
    float t, sinValue, cosValue, cotValue;

    for (int i = 0; i < samples_count; i++) {
        t = static_cast<float>(i) / SAMPLERATE;
        float angle = 2.0f * PI * frequency * t * 180.0f / PI;

        sinValue = Math::Sine(angle);
        cosValue = Math::Cosine(angle);

        if (Math::abs(sinValue) < 0.001f) {
            cotValue = (sinValue >= 0) ? 10.0f : -10.0f;
        } else {
            cotValue = cosValue / sinValue;
        }

        if (cotValue > 10.0f) cotValue = 10.0f;
        if (cotValue < -10.0f) cotValue = -10.0f;

        samples[i] = cotValue / 10.0f;
    }

    return samples;
}

#pragma endregion Trigonometric Shapes

float *SampleGenerator::generateHann(float sampleSize, float frequency) {
    const int SAMPLERATE = 44100;

    int samples_count = static_cast<int>(sampleSize * SAMPLERATE);
    float* samples = new float[samples_count];

    for (int i = 0; i < samples_count; i++) {
        samples[i] = Math::Hann(static_cast<float>(i), static_cast<float>(samples_count));
    }

    return samples;
}

float *SampleGenerator::generatePhasedHann(float sampleSize, float frequency) {
    const int SAMPLERATE = 44100;

    int samples_count = static_cast<int>(sampleSize * SAMPLERATE);
    float* samples = new float[samples_count];
    float t, phase;

    int samples_per_cycle = static_cast<int>(SAMPLERATE / frequency);

    for (int i = 0; i < samples_count; i++) {
        t = static_cast<float>(i) / SAMPLERATE;
        phase = Math::fmod(t * frequency, 1.0f);

        float n = phase * samples_per_cycle;
        samples[i] = Math::Hann(n, static_cast<float>(samples_per_cycle));
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
        case Shape::COSINE: samples = generateCosine(time, frequency); break;
        case Shape::TANGENT: samples = generateTangent(time, frequency); break;
        case Shape::COTANGENT: samples = generateCotangent(time, frequency); break;
        case Shape::HANN: samples = generateHann(time, frequency); break;
        case Shape::PHASED_HANN: samples = generatePhasedHann(time, frequency); break;
    }

    return samples;
}