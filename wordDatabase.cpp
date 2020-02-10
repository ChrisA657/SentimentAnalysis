//
// Created by Chris on 2/9/2020.
//

#include "wordDatabase.h"

int wordDatabase::wordsSentiment(DSString word) {
    // searching algorithm



    //if word is negative -1, word positive +1, not found 0
    for(int i = 0; i < database.size(); i++)
    {
        if(database[i].getWord()== word)
        {
            return database[i].getSentiment();
        }
    }
    return 0;
}

wordDatabase::wordDatabase() {

}

void wordDatabase::addNewWord(sentimentalWord word) {
    database.push_back(word);

}

void wordDatabase::print() {
    for(int i=0; i < database.size(); i++)
        std::cout << database.at(i).getWord() << ' ';


}

int wordDatabase::getSize() {
    return database.size();
}
