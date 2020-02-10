//
// Created by Chris on 2/8/2020.
//

#ifndef S20_PA01_SENTIMENTANALYSIS_DSSTRING_H
#define S20_PA01_SENTIMENTANALYSIS_DSSTRING_H
#include <ostream>
#include <iostream>
#include <cstring>
class DSString {
private:
        char* stringData;
public:
    ~DSString();
    DSString (const DSString& copyString);
    DSString (const char* incomingChars);
    DSString ();
    DSString operator()(const char* incomingChars);
    DSString operator+(const DSString);
    DSString operator=(const DSString&);
    DSString operator=(const DSString*);
    DSString& operator+=(const DSString&);
    bool isEmpty();
    bool  operator==(DSString ) const;
    unsigned long operator [](int i) const;
    char* getString() const;
    DSString substring(int , int );
    int getLength() const ;
    const char* c_str() const;
    void setString(char * set);


};
std::ostream& operator<<(std::ostream& , const DSString& printString);

#endif //S20_PA01_SENTIMENTANALYSIS_DSSTRING_H
