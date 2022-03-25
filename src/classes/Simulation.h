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

/**
 * Class for running simulation routine
 */
class Simulation {
public:
    /**
     * Class for storing result of simulation
     */
    class SimulationResult {
    private:
        int index1;
        int index2;
        float t;
        float distance;
    public:
        /**
         * Initializes a new simulation result
         * @param index1 index of the first sphere
         * @param index2 index of the second sphere
         * @param t time when approximation is calculated to occur
         * @param distance closest distance calculated between given spheres at time t
         */
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

    /**
     * getter for best distance calculated until the moment of invocation
     * @return current best distance calculated between any sphere until now
     */
    float getBestDistance();

    /**
     * compares given result with the current best result, if given result is better, replaces the current best
     * result with the given result. Note that this method may block execution of a thread since it uses a mutex
     * to avoid race conditions on best result object
     * @param potentialResult calculated result which has a potential to be a new best result
     */
    void updateResult(SimulationResult& potentialResult);

    /**
     * Main routine function for threads. Each thread starts from given start index of the vector containing spheres,
     * iterates until given end index and calculates closest distances between spheres until radial distances get bigger
     * than current best result. Each result calculated is compared with current best result and current result is
     * updated if a better result is found.
     * @param simulation pointer to simulation object running the thread
     * @param startIndex start index of the vector of spheres for the range this thread runs
     * @param endIndex end index of the vector of spheres for the range this thread runs
     */
    static void threadRoutine(Simulation *simulation, size_t startIndex, size_t endIndex);
public:
    /**
     * Initializes a new simulation. Reads sphere data from the file at the given path
     * @param pathToInputFile path containing the input file which has observed sphere information
     * @param numIntervals number of divisions per unit time to determine step size of the simulation
     * @param numThreads maximum allowable number of threads
     */
    Simulation(const std::string &pathToInputFile, size_t numIntervals, size_t numThreads);

    /**
     * Starts the execution of the simulation. Sorts the vector containing the spheres by radius of spheres in ascending
     * order, then invokes threads according to numThreads and number of spheres. After all threads are terminated,
     * returns the best result calculated.
     * @return a simulation result object containing the best result calculated
     */
    SimulationResult run();
};


#endif //DARK_ORBIT_SIMULATION_H
