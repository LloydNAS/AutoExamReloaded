#ifndef AUTOEXAMRELOADED_XLSXUTILITIES_H
#define AUTOEXAMRELOADED_XLSXUTILITIES_H

#include <OpenXLSX.hpp>
#include <string>
#include <map>

#include "Career.h"
#include "Subject.h"

using namespace OpenXLSX;

class XLSXUtilities {
private:
    XLSXUtilities();
    std::vector<Subject> gatheredData;
    OpenXLSX::XLDocument *document;
    static XLSXUtilities *instance;
public:
    static XLSXUtilities *getInstance();

    void openBook(std::string);
    void gatherData(std::string, char, char, char, std::pair<char,char>, std::pair<short,short>, std::pair<std::string,std::string>);
    void closeBook();

    std::vector<Subject>& getGatheredData();


};


#endif //AUTOEXAMRELOADED_XLSXUTILITIES_H
