//
// Created by Chris on 2/9/2020.
//

#include <fstream>
#include "Analyzer.h"
#include "Tweet.h"



Analyzer::Analyzer() {
     learnedTweets =0;
     correctTweets =0;
     incorrectTweets =0;
     accuracy =0;
}

void Analyzer::learn(std::ifstream& file1, std::ifstream& file2)
{


    char* tweetDataBuffer = new char[256];
    char* tweetDataBuffer2= new char[256];
    file1.getline(tweetDataBuffer, 256, '\n');
    file2.getline(tweetDataBuffer2, 256, '\n');

    while(file1.getline(tweetDataBuffer, 256, '\n'))
    {

        file2.getline(tweetDataBuffer2, 256, '\n');
        Tweet* loadedTweet = new Tweet(tweetDataBuffer, tweetDataBuffer2);


        delete tweetDataBuffer;
        delete tweetDataBuffer2;
        tweetDataBuffer = new char[256];
        tweetDataBuffer2= new char[256];
        sentimentalWord* temp = new sentimentalWord(loadedTweet->selectRandWord(), loadedTweet->getSentiment());
        learnedData.addNewWord(*temp);
        delete temp;

        // adds words to databank of words: more words = more accurate
        for(int i=0; i <loadedTweet->getWordArray().size();i++)
        {
            temp = new sentimentalWord(loadedTweet->getWordArray()[i], loadedTweet->getSentiment());

            learnedData.addNewWord(*temp);
            delete temp;
        }
        delete loadedTweet;
        learnedTweets++;
    }

    delete tweetDataBuffer;
    delete tweetDataBuffer2;
}

void Analyzer::test(std::ifstream& file3 , std::ifstream& file4)
{

    //ignore first line in file


    long knownSentiment = 0;
    int sentimentScore = 0;
    char* tweetDataBuffer = new char[256];
    char* tweetDataBuffer2= new char[256];



    file3.getline(tweetDataBuffer, 256 ,'\n');
    file4.getline(tweetDataBuffer2 , 256 ,'\n');
    while(file3.getline(tweetDataBuffer, 256, '\n'))
    {
        file4.getline(tweetDataBuffer2, 256, '\n');
        // load the tweet's data
        Tweet* tweetGuess = new Tweet(tweetDataBuffer,tweetDataBuffer2);


        delete tweetDataBuffer;
        delete tweetDataBuffer2;

        tweetDataBuffer = new char[256];
        tweetDataBuffer2= new char[256];knownSentiment = tweetGuess->getSentiment();


        //score every word
        for(int i = 0; i<tweetGuess->getWordCount(); i++)
        {
          sentimentScore+= learnedData.wordsSentiment(tweetGuess->getWordArray()[i]);
        }
        //Program "guesses" what the sentiment of the tweet is based on sentiment score
        if(sentimentScore>=0)
        {
            tweetGuess->setSentiment(1);
        }
        else {
            tweetGuess->setSentiment(-1);
        }
        // checks to see if guess was correct
        if(tweetGuess->getSentiment()==knownSentiment) {

            correctTweets++;
        }
        else {

            incorrectTweets++;
        }

    delete tweetGuess;

    }
    // calculates accuracy
    if(incorrectTweets != 0)
    accuracy = float((double)correctTweets/(double)(incorrectTweets+correctTweets));
    else accuracy = 100;
}

//print accuracy to output file
void Analyzer::print(std::ofstream& output) {


    std::cout <<"accuracy: "<< accuracy<<" incorrect: "<<incorrectTweets<<" correct: "<<correctTweets <<"total words in bank "<< learnedData.getSize()<< std::endl;
    output <<"accuracy: " << accuracy;
    output.close();

}