//
// Created by Chris on 2/9/2020.
//

#ifndef S20_PA01_SENTIMENTANALYSIS_WORDDATABASE_H
#define S20_PA01_SENTIMENTANALYSIS_WORDDATABASE_H

#include "DSString.h"
#include "sentimentalWord.h"
#include <vector>
class wordDatabase {
private:
    std::vector<sentimentalWord> database;
public:
    wordDatabase();
    void addNewWord(sentimentalWord word);
    int getSize();
    int wordsSentiment(DSString word);
    void print();

};


#endif //S20_PA01_SENTIMENTANALYSIS_WORDDATABASE_H
