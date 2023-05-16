//
// Created by Nestor Adrian Sandoval Ortiz on 15/05/23.
//

#include "Subject.h"

float Subject::getDifficulty(){
    return difficulty;
}

std::string Subject::getName(){
    return name;
}

std::vector<short>& Subject::getScheduledDays() {
    return scheduledDays;
}

void Subject::setDifficulty(float difficulty) {
    this->difficulty = difficulty;
}

void Subject::setScheduledDay(short scheduledDay){
    scheduledExamDay = scheduledDay;
}

short Subject::getScheduledDay() {
    return scheduledExamDay;
}

short Subject::getID() {
    return id;
}

void Subject::addScheduledDay(short day) {
    scheduledDays.push_back(day);
}

std::vector<Career*> &Subject::getCareers() {
    return careers;
}

void Subject::addCareer(Career *career) {
    careers.push_back(career);
}

Subject::Subject(short id, std::string name, float difficulty) {
    this->id = id;
    this->name = name;
    this->difficulty = difficulty;
    scheduledExamDay = -1;
    scheduledDays = std::vector<short>(0);
}


