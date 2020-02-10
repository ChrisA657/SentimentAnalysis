//
// Created by Chris on 2/9/2020.
//

#ifndef S20_PA01_SENTIMENTANALYSIS_SENTIMENTALWORD_H
#define S20_PA01_SENTIMENTANALYSIS_SENTIMENTALWORD_H

#include "DSString.h"
class sentimentalWord {
private:
    DSString word;
    int sentiment;
public:
    sentimentalWord(DSString word, int sentiment);
    DSString getWord() const;
    int getSentiment() const;
};


#endif //S20_PA01_SENTIMENTANALYSIS_SENTIMENTALWORD_H
