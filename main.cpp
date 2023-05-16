#include <iostream>
#include <OpenXLSX.hpp>
#include "Constants.h"

using namespace OpenXLSX;

void initConstants();

int main() {
    initConstants();
    XLDocument document = XLDocument("/Users/lloydna/Desktop/UP/6°semestre/AutoExamReloaded/InputXLSX/Horarios1232_pesos_materias.xlsm", XLZipArchive());




    return 0;
}

void initConstants(){
    Constants::BASE_CAREER_NAMES = std::vector<std::string>{"II","IM","IID","IIA","ITE","ICA","IBE"};
    Constants::INITIAL_CALENDAR_DAY = 1;
    Constants::FINAL_CALENDAR_DAY = 11;
}