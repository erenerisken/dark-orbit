//
// Created by Eren Erisken on 3/20/22.
//

#include <iostream>

#include "./classes/Simulation.h"

int main(int argc, char* argv[]) {
    std::string pathToInputFile;
    size_t numIntervals;
    size_t numThreads;
    if (argc < 4) {
        std::cout <<
            "Usage: dark_orbit <path_to_input_file> <number_of_intervals_for_unit_time> <number_of_threads>" <<
            std::endl;
        return 0;
    }
    pathToInputFile = std::string(argv[1]);
    numIntervals = Utilities::atou(argv[2]);
    numThreads = Utilities::atou(argv[3]);

    try {
        Simulation simulation(pathToInputFile, numIntervals, numThreads);
        auto result = simulation.run();

        std::cout << "Result -> " << result << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}