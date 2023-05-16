#include <iostream>
#include "DNAOptimization.h"

DNAParameters::DNAParameters(long mps, double por, double pom, double mass, long mnog){
    maxPopulationSize = mps;
    probabilityOfReproduction = por;
    probabilityOfMutation = pom;
    minAcceptedSolutionScore = mass;
    maximumNumberOfGenerations = mnog;
}

DNAOptimization *DNAOptimization::getInstance(std::vector<Subject>& subjects) {
    if(instance == nullptr)
        instance = new DNAOptimization(subjects);
    return instance;
}

DNAOptimization *DNAOptimization::getInstance() {
    if(instance == nullptr)
        std::cerr<<"Optimization instance is not defined!!!";
    return instance;
}

DNAOptimization::DNAOptimization(std::vector<Subject>& subjects){
    unoptimized = subjects;
    bestSolution = std::vector<std::string>();
    bestSolutionScore = -1.0;

    parameters = DNAParameters(30, 0.8, 0.3, 500,100);
}

std::vector<std::string> &DNAOptimization::getResults() {
    return bestSolution;
}

double DNAOptimization::getBestSolutionScore() {
    return bestSolutionScore;
}

void DNAOptimization::start(std::vector<Subject>) {

}


