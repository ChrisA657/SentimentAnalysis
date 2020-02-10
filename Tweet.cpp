//
// Created by Chris on 2/9/2020.
//

#include "Tweet.h"
#include <vector>
Tweet::Tweet(DSString data, DSString target) {

    //split and read in data from files
    DSString* buffer = new DSString("temp");
    buffer->setString(std::strtok(data.getString(), ","));
    rowNum = 0;

    // reads and sets the tweet id
    buffer->setString( std::strtok(NULL, ","));
    id = buffer;
    // sets username
    buffer->setString( std::strtok(NULL, ","));
    username = buffer;
    // sets the actual tweet string
    buffer->setString(std::strtok(NULL, "\n"));
    tweetString = new DSString(buffer->getString());



    //start of target file(rownum)
    std::strtok(target.getString(), ",");

    //reads in the sentiment value from target file
    buffer->setString(std::strtok(NULL, ","));

    if(std::strcmp(buffer->getString(), "4") ==0)
    sentiment = 1;
    else
            if (std::strcmp(buffer->getString(), "0") ==0)
                sentiment = -1;
            else
                sentiment = 0;
            //sets buffer to id
    buffer->setString(std::strtok(NULL, ","));
    // makes sure ids match up

    if(!(*id == *buffer))
    {
        std::cout<<"mismatching ids, data incorrectly formatted";
        exit(3);
    }

    createWordArray();
}
Tweet::~Tweet()
{

    delete tweetString;
}
DSString Tweet::selectRandWord() {
    return words[std::rand() % wordCount];
}

void Tweet::loadTweet(DSString tweetData) {


}

void Tweet::createWordArray() {
    wordCount = 1;
    DSString* buffer = new DSString("");


    char* safety;
    DSString* temp = new DSString(*tweetString);

    safety = std::strtok(temp->getString(),"á \" \n!@#$%^&()(,;:.-");


    buffer->setString(safety);
    words.push_back(*buffer);



        while((safety=std::strtok(NULL, "á \"\n!@#$%^&()(,;:?.-")) != NULL) {


            buffer->setString(safety);
            words.push_back(*buffer);
            wordCount++;
          // if(wordCount ==10) break;


        }
    delete temp;
}

void Tweet::setSentiment(int sent) {
    sentiment = sent;

}

void Tweet::setTweet(DSString *tweetData) {
    tweetString = tweetData;

}

void Tweet::setID(DSString* ID) {

    id = ID;

}

void Tweet::setRow(int row) {
    rowNum = row;

}

int Tweet::getSentiment() const {
    return sentiment;
}

DSString *Tweet::getTweet() const {
    return tweetString;
}

std::vector<DSString> Tweet::getWordArray() {
    return words;
}

DSString* Tweet::getID() const {
    return id;
}

int Tweet::getRow() const {
    return rowNum;
}

int Tweet::getWordCount() {
    return wordCount;
}


