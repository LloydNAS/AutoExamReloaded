#ifndef AUTOEXAMRELOADED_DNAOPTIMIZATION_H
#define AUTOEXAMRELOADED_DNAOPTIMIZATION_H

#include <vector>

#include "Subject.h"

struct DNAParameters{
    //Parents select parameters
    long maxPopulationSize;
    double probabilityOfReproduction;

    //Mutation parameters
    double probabilityOfMutation;

    //Quality parameters
    long maximumNumberOfGenerations;
    double minAcceptedSolutionScore;

    DNAParameters(long, double, double, double, long);
    DNAParameters();
};

class DNAOptimization {
private:
    DNAOptimization(std::vector<Subject>&);
    static DNAOptimization *instance;
    double calculateSolutionScore(std::vector<std::string>);
    std::vector<std::vector<std::pair<double,std::string>>> selectParents(std::vector<std::vector<std::pair<double,std::string>>>&);
    void reproduceParents(std::vector<std::vector<std::pair<double,std::string>>>&);
    void mutate(std::vector<std::vector<std::pair<double,std::string>>>&);
    void findElite(std::vector<std::vector<std::pair<double,std::string>>>&);


    DNAParameters parameters;
    std::vector<Subject> unoptimized;
    std::vector<std::string> bestSolution;
    double bestSolutionScore;
public:
    static DNAOptimization* getInstance(std::vector<Subject>&);
    static DNAOptimization* getInstance();
    void start(std::vector<Subject>);
    std::vector<std::string>& getResults();
    double getBestSolutionScore();
};


#endif //AUTOEXAMRELOADED_DNAOPTIMIZATION_H
