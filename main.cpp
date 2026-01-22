#include <iostream>

#include "include/SampleGenerator.h"
#include "include/Math.h"

int main(int argc, char *argv[]) {
    /* Running:
     * cmake-build-debug/Sprocket > audio.csv
     * gnuplot -p -e "set datafile separator ','; plot 'audio.csv' using 2 with lines"
     *
     * TODO: Amplitude
     * TODO: Sawtooth, Triangle, Square
     * TODO: ADSR shapes
     */

    SampleGenerator sampleGenerator;
    float* samples = sampleGenerator.generateSamples(SampleGenerator::SAWTOOTH, 10, 440.0f);

    int sampleCount = Math::min(1000, 44100*10);

    for (int i = 0; i < sampleCount; i++) {
        float time = static_cast<float>(i) / 44100.0f;
        std::cout << time << "," << samples[i] << std::endl;
    }

    delete[] samples;
}