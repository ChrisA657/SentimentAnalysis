//
// Created by Chris on 2/9/2020.
//

#include "sentimentalWord.h"

int sentimentalWord::getSentiment() const {
    return sentiment;
}

DSString sentimentalWord::getWord() const {
    return word;
}

sentimentalWord::sentimentalWord(DSString word, int sen) {

    this->word = word;
    sentiment = sen;

}
