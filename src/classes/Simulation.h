//
// Created by Eren Erişken on 3/23/22.
//

#ifndef DARK_ORBIT_SIMULATION_H
#define DARK_ORBIT_SIMULATION_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <mutex>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

#include "Sphere.h"
#include "Errors.h"

class Simulation {
public:
    class SimulationResult {
    private:
        int index1;
        int index2;
        float t;
        float distance;
    public:
        SimulationResult(int index1, int index2, float t, float distance);

        [[nodiscard]] int getIndex1() const;
        [[nodiscard]] int getIndex2() const;
        [[nodiscard]] float getT() const;
        [[nodiscard]] float getDistance() const;

        void setIndex1(int index1);
        void setIndex2(int index2);
        void setT(float t);
        void setDistance(float distance);

        friend std::ostream& operator<<(std::ostream& o, SimulationResult simulationResult);
    };
private:
    int sphereCount;
    size_t numThreads;
    std::vector<Sphere> spheres;
    Utilities utilities;
    SimulationResult bestResult;

    std::mutex mutex;

    float getBestDistance();
    void updateResult(SimulationResult& potentialResult);

    static void threadRoutine(Simulation *simulation, size_t startIndex, size_t endIndex);
public:
    Simulation(const std::string &pathToInputFile, size_t numIntervals, size_t numThreads);

    SimulationResult run();
};


#endif //DARK_ORBIT_SIMULATION_H
