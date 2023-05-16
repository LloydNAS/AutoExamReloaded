//
// Created by Nestor Adrian Sandoval Ortiz on 15/05/23.
//

#ifndef AUTOEXAMRELOADED_CAREER_H
#define AUTOEXAMRELOADED_CAREER_H

#include <string>
#include <vector>

class Career {
public:
    Career(std::string);
    std::string getName();
    std::vector<short>& getCalendar();
private:
    std::string name;
    std::vector<short> calendar;
};


#endif //AUTOEXAMRELOADED_CAREER_H
