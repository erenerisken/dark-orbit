//
// Created by Eren Erişken on 3/23/22.
//

#include "Simulation.h"

Simulation::Simulation(const std::string &pathToInputFile, size_t numIntervals, size_t numThreads):
    bestResult(0, 0, 0, std::numeric_limits<float>::max()), numThreads(numThreads) {

    utilities.setNumIntervals(numIntervals);
    std::ifstream inputFile;
    try {
        inputFile.open(pathToInputFile);
    } catch (std::exception &e){
        throw ErrorOpeningInputFile(e.what());
    }

    if (!inputFile.good()) {
        throw ErrorOpeningInputFile("Input file status not good");
    }

    sphereCount = 0;
    std::string lineRead;
    try {
        while (std::getline(inputFile, lineRead)) {
            std::istringstream inSStream(lineRead);
            unsigned int r;
            float theta, phi, uvx, uvy, uvz;
            int w;
            if(!(inSStream >> r >> theta >> phi >> w >> uvx >> uvy >> uvz)) {
                throw ErrorReadingInputLine(lineRead);
            }
            spheres.emplace_back(
                    Sphere(++sphereCount, utilities, r, theta, phi, w, {uvx, uvy, uvz})
                    );
        }
    } catch (std::exception& e) {
        inputFile.close();
        throw ErrorReadingInputFile(e.what());
    }

    inputFile.close();
}

Simulation::SimulationResult Simulation::run() {
    std::sort(spheres.begin(), spheres.end());
    auto sphereCountAsU64 = (size_t) sphereCount;
    size_t threadCount = std::min(numThreads, (size_t)std::ceil((double)sphereCountAsU64 / (double)SPHERES_PER_THREAD));
    size_t spheresPerThread = sphereCountAsU64 / threadCount;
    if (sphereCountAsU64 % threadCount > 0) {
        spheresPerThread++;
    }

    std::vector<std::thread> threads;
    for (size_t i = 0; i < sphereCountAsU64; i += spheresPerThread) {
        size_t end = std::min(i + spheresPerThread, sphereCountAsU64) - 1;
        threads.emplace_back(std::thread(Simulation::threadRoutine, this, i, end));
    }
    std::cout << "Invoked " << threads.size() << " threads." << std::endl;

    for (auto& thread: threads) {
        thread.join();
    }

    return bestResult;
}

Simulation::SimulationResult::SimulationResult(int index1, int index2, float t, float distance):
    index1(index1), index2(index2), t(t), distance(distance) {}

int Simulation::SimulationResult::getIndex1() const {
    return index1;
}

int Simulation::SimulationResult::getIndex2() const {
    return index2;
}

float Simulation::SimulationResult::getT() const {
    return t;
}

float Simulation::SimulationResult::getDistance() const {
    return distance;
}

std::ostream &operator<<(std::ostream &o, Simulation::SimulationResult simulationResult) {
    o <<
        "Sphere 1: " <<
        simulationResult.index1 <<
        " Sphere 2: " <<
        simulationResult.index2 <<
        " T = " <<
        simulationResult.t <<
        " Closest distance: " <<
        simulationResult.distance;

    return o;
}

void Simulation::SimulationResult::setIndex1(int index1) {
    SimulationResult::index1 = index1;
}

void Simulation::SimulationResult::setIndex2(int index2) {
    SimulationResult::index2 = index2;
}

void Simulation::SimulationResult::setT(float t) {
    SimulationResult::t = t;
}

void Simulation::SimulationResult::setDistance(float distance) {
    SimulationResult::distance = distance;
}

void Simulation::threadRoutine(Simulation *simulation, size_t startIndex, size_t endIndex) {
    auto &spheres = simulation->spheres;
    size_t sphereCount = spheres.size();
    for (size_t i = startIndex; i < endIndex; ++i) {
        auto &sphere1 = spheres[i];
        for (size_t j = i + 1; j < sphereCount; ++j) {
            auto &sphere2 = spheres[j];
            float currentMinimumDistance = simulation->getBestDistance();
            if (sphere1.radialDistanceTo(sphere2) >= currentMinimumDistance) {
                break;
            }

            auto distanceCalculation = sphere1.closestDistanceTo(sphere2);
            SimulationResult newResult(
                    sphere1.getIndex(),
                    sphere2.getIndex(),
                    distanceCalculation.second,
                    distanceCalculation.first
                    );
            simulation->updateResult(newResult);
        }
    }
}

void Simulation::updateResult(Simulation::SimulationResult &potentialResult) {
    mutex.lock();
    if (potentialResult.getDistance() < bestResult.getDistance()) {
        bestResult = potentialResult;
    }
    mutex.unlock();
}

float Simulation::getBestDistance() {
    mutex.lock();
    float bestDistance = bestResult.getDistance();
    mutex.unlock();
    return bestDistance;
}
