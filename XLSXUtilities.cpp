#include "XLSXUtilities.h"
#include "Constants.h"

XLSXUtilities *XLSXUtilities::getInstance() {
    if(XLSXUtilities::instance == nullptr)
        XLSXUtilities::instance = new XLSXUtilities();
    return instance;
}

void XLSXUtilities::openBook(std::string path) {
    document = new OpenXLSX::XLDocument(path, XLZipArchive());
}

void XLSXUtilities::closeBook(){
    document->close();
    document == nullptr;
}

std::vector<Subject> &XLSXUtilities::getGatheredData() {
    return gatheredData;
}

XLSXUtilities::XLSXUtilities(){
    gatheredData = std::vector<Subject>();
}

void XLSXUtilities::gatherData(std::string sheetName, char nameColumn, char difficultyColumn, char classColumn,
                               std::pair<char, char> scheduledDaysRange, std::pair<short,short> rowIndexRange, std::pair<std::string,std::string> careersRange) {
    if(document == nullptr){
        std::cerr<<"No document is loaded!!!";
        return;
    }

    std::map<std::string, Career*> careerMemo;
    std::map<std::string, Subject*> subjectMemo;

    XLWorksheet sheet = document->workbook().worksheet(sheetName);

    for(short i = rowIndexRange.first-1;i < rowIndexRange.second;i++){
        std::string currSubjectName = sheet.cell((nameColumn + std::to_string(i))).value().typeAsString() + " " +
                sheet.cell((classColumn + std::to_string(i))).value().typeAsString();

        std::string currSubjectDifficultyString = sheet.cell((difficultyColumn + std::to_string(i))).value().typeAsString();
        //delete all whitespaces for stringstream to work well
        currSubjectDifficultyString.erase(remove(currSubjectDifficultyString.begin(), currSubjectDifficultyString.end(), ' '), currSubjectDifficultyString.end());

        std::stringstream ss(currSubjectDifficultyString);
        std::string currSubjectHolderString;

        float currSubjectDifficulty = 0.0f;
        short currVotationCount = 0;
        //difficulty calculation
        while(ss>>currSubjectHolderString){
            currVotationCount++;
            currSubjectDifficulty += std::stof(currSubjectHolderString);
        }

        currSubjectDifficulty /= currVotationCount; //final difficulty;

        //MISSING SPECIAL CASES!!!

        Subject *currSubject = subjectMemo.find(currSubjectName) == subjectMemo.end() ? (subjectMemo[currSubjectName] = new Subject(i, currSubjectName, currSubjectDifficulty)) : subjectMemo[currSubjectName];

        //only if currsubject does not have careers yet, we add to it
        if(currSubject->getCareers().empty()){
            for(char j = careersRange.first.back(); j <= careersRange.second.back(); j++){
                std::string currCellValue = "A";
                currCellValue.push_back(j);
                currCellValue += std::to_string(i);

                std::string currCareerSemester = sheet.cell(currCellValue).value().typeAsString();

                if(!currCareerSemester.empty()){
                    std::string currCareerName = Constants::BASE_CAREER_NAMES[j - careersRange.first.back()] + currCareerSemester;

                    //only create new career if a previous one does not exist
                    currSubject->addCareer(careerMemo.find(currCareerName) == careerMemo.end() ?
                        (careerMemo[currCareerName] = new Career(currCareerName)) : careerMemo[currCareerName]);

                }

            }

        }

        //add scheduled days to subject
        for(char j = scheduledDaysRange.first; j <= scheduledDaysRange.first; j++){
            std::string currScheduledDay = sheet.cell(j + std::to_string(i)).value().typeAsString();

            if(!currScheduledDay.empty())
                currSubject->addScheduledDay((1+(j - scheduledDaysRange.first))%7); //for 1st and 2nd week

        }



    }

}

