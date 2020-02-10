//
// Created by Chris on 2/9/2020.
//
#include <fstream>
#include "wordDatabase.h"
#ifndef S20_PA01_SENTIMENTANALYSIS_ANALYZER_H
#define S20_PA01_SENTIMENTANALYSIS_ANALYZER_H


class Analyzer {
private:
    int learnedTweets;
    wordDatabase learnedData;
    int correctTweets;
    int incorrectTweets;
    float accuracy;
public:
    Analyzer();
    void print(std::ofstream&);
    void learn(std::ifstream&,  std::ifstream&);
    void test(std::ifstream&,  std::ifstream&);
};


#endif //S20_PA01_SENTIMENTANALYSIS_ANALYZER_H
