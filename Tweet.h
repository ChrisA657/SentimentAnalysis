//
// Created by Chris on 2/9/2020.
//

#ifndef S20_PA01_SENTIMENTANALYSIS_TWEET_H
#define S20_PA01_SENTIMENTANALYSIS_TWEET_H

#include "DSString.h"
#include <istream>
#include <vector>

class Tweet {
private:
    int rowNum;
    DSString* id;
    int sentiment;
    int wordCount;
    DSString* username;
    DSString* tweetString;
    std::vector<DSString> words;

public:
    ~Tweet();
    Tweet(DSString,DSString);
    DSString selectRandWord();
    void loadTweet(DSString);
    void createWordArray();
    void setSentiment(int sent);
    void setTweet(DSString *);
    void setID(DSString* );
    void setRow(int);
    int getWordCount();
    int getSentiment() const;
    DSString* getTweet() const;
    std::vector<DSString> getWordArray();
    DSString* getID() const;
    int getRow() const;
};


#endif //S20_PA01_SENTIMENTANALYSIS_TWEET_H
