//
// Created by Chris on 2/8/2020.
//

#include "DSString.h"
#include<cstring>
#include <ostream>
// chars constructor
DSString::DSString(const char * incomingChars) {

    stringData = new char[strlen(incomingChars) + 1];
    for(int i = 0; i< strlen(incomingChars); i++)
    {
        stringData[i] = incomingChars[i];
    }
    stringData[strlen(incomingChars)] = '\0';
}
// copy constructor
DSString::DSString(const DSString &copyString) {

    stringData = new char[strlen(copyString.getString()) + 1];
    for(int i = 0; i< strlen(copyString.getString());i++)
    {
        stringData[i] = copyString.getString()[i];
    }
    stringData[copyString.getLength()] = '\0';

}

DSString::DSString() {
    stringData = new char[1];
    stringData[0] = '\0';

}
// include null turm below this
DSString DSString::operator+(const DSString add) {

    char* temp = new char[strlen(add.getString()) + strlen(stringData)+1];
    for(int i = 0; i < strlen(stringData); i++)
    {
        temp[i] = stringData[i];
    }
    for(int j =0; j <strlen(add.getString()); j++)
    {
        temp[j+strlen(stringData)] = add.getString()[j];
    }
    temp[strlen(add.getString()) + strlen(stringData)] = '\0';
    DSString addedStrings(temp);
    delete[] temp;
    return addedStrings;
}

DSString& DSString::operator+=(const DSString& add) {
    DSString* addedStrings;
    char* temp = new char[strlen(add.getString()) + strlen(stringData)+1];
    temp[strlen(add.getString()) + strlen(stringData)] = '\0';
    for(int i = 0; i <strlen(stringData); i++)
    {
        temp[i] = stringData[i];
    }
    for(int j =0; j <strlen(add.getString()); j++)
    {
        temp[j+strlen(stringData)] = add.getString()[j];
    }

    addedStrings = new DSString(temp);

    delete[] temp;
    delete[] stringData;
    *this = addedStrings;
    delete[] addedStrings->stringData;
    delete addedStrings;
    return *this;
}

DSString DSString::operator=(const DSString& toBeCopied){

         delete[] stringData;
         stringData = nullptr;
         stringData = new char[toBeCopied.getLength()+1];
         stringData[toBeCopied.getLength()]= '\0';
        for(int i = 0; i< strlen(toBeCopied.getString());i++)
        {
            stringData[i] = toBeCopied.getString()[i];
        }
        return *this;



}
DSString DSString::operator=(const DSString* toBeCopied){

    delete[] stringData;
    stringData = new char[strlen(toBeCopied->getString())+1];
    stringData[toBeCopied->getLength()]= '\0';
    for(int i = 0; i< strlen(toBeCopied->getString());i++)
    {
        stringData[i] = toBeCopied->getString()[i];
    }
    return *this;
}

bool DSString::operator==(const DSString compare) const {
    if(std::strcmp(compare.getString(), stringData)== 0)
    {

        return true;
    }


    return false;
}


// get String data
char* DSString::getString() const {
    return stringData;
}
//First num is starting point, last num is end point which is not included
DSString DSString::substring(int start, int end) {

    if(end < strlen(stringData) && start >= 0)
    {
        char * temp = new char [(end - start) + 1];
        temp[(end - start) ] = '\0';
        for(int i = start; i < end; i++)
        {
            temp[i-start] = stringData[i] ;
        }


        DSString sub = (temp);
        delete[] temp;
        return sub;
    }
    return *this;

}

int DSString::getLength() const {
    return strlen(stringData);
}

DSString DSString::operator()(const char *incomingChars) {
    return DSString(incomingChars);
}

unsigned long DSString::operator[](int i) const {
    return stringData[i];
}

bool DSString::isEmpty() {
    if(strlen(stringData)==0)
        return true;
    return false;
}

const char* DSString::c_str() const {
    return stringData;
}

DSString::~DSString() {
    delete[] stringData;
}

void DSString::setString(char *set) {
    delete stringData;
    stringData = new char[strlen(set) + 1];
    for(int i = 0; i< strlen(set); i++)
    {
        stringData[i] = set[i];
    }
    stringData[strlen(set)] = '\0';

}


std::ostream& operator<<(std::ostream& stream , const DSString& printString) {
    return stream << printString.getString();
}
