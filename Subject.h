//
// Created by Nestor Adrian Sandoval Ortiz on 15/05/23.
//

#ifndef AUTOEXAMRELOADED_SUBJECT_H
#define AUTOEXAMRELOADED_SUBJECT_H

#include <string>
#include <vector>

#include "Career.h"

class Subject {
public:
    Subject(short, std::string, float);
    void setDifficulty(float);
    void setScheduledDay(short);
    void addCareer(Career* career);
    short getScheduledDay();
    short getID();
    float getDifficulty();
    std::string getName();
    std::vector<short>& getScheduledDays();
    std::vector<Career*>& getCareers();
    void addScheduledDay(short);
private:
    float difficulty;
    std::string name;
    std::vector<short> scheduledDays;
    std::vector<Career*> careers;
    short scheduledExamDay;
    short id;
};


#endif //AUTOEXAMRELOADED_SUBJECT_H
