#include "Career.h"
#include "Constants.h"

std::vector<short> &Career::getCalendar() {
    return calendar;
}

std::string Career::getName(){
    return name;
}

Career::Career(std::string name){
    this->name = name;
    this->calendar = std::vector<short>((1 + Constants::FINAL_CALENDAR_DAY - Constants::INITIAL_CALENDAR_DAY),0);
}
