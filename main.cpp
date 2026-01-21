#include <iostream>

#include "include/SampleGenerator.h"

int main(int argc, char *argv[]) {
    /* cmake-build-debug/Sprocket > audio.csv
     * gnuplot -p -e "set datafile separator ','; plot 'audio.csv' using 2 with lines" */
    SampleGenerator sampleGenerator;
    float* samples = sampleGenerator.generateSamples(SampleGenerator::SINE, 10, 440.0f);

    int sampleCount = std::min(1000, 44100*10);

    for (int i = 0; i < sampleCount; i++) {
        float time = static_cast<float>(i) / 44100.0f;
        std::cout << time << "," << samples[i] << std::endl;
    }

    delete[] samples;
}