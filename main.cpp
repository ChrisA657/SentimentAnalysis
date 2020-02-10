#define CATCH_CONFIG_RUNNER  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <iostream>
#include <fstream>
#include <cstddef>
#include <iostream>
#include <string>
#include "Analyzer.h"
#include <fstream>

int main (int argc, char * argv[]) {

    if(argc == 1)
    {
        Catch::Session().run();
    }
    // file one:  file with the training tweets
    std::ifstream inFile1(argv[1]);
    if (!inFile1.is_open())
    {
        std::cout << "Could not open the file 1." << std::endl;
        return -1;
    }

    // file two:
    std::ifstream inFile2(argv[2]);
    if (!inFile2.is_open())
    {
        std::cout << "Could not open the file 2." << std::endl;
        return -1;
    }

    // file three
    std::ifstream inFile3(argv[3]);
    if (!inFile3.is_open())
    {
        std::cout << "Could not open the file 3." << std::endl;
        return -1;
    }
    //file four
    std::ifstream inFile4(argv[4]);
    if (!inFile4.is_open())
    {
        std::cout << "Could not open the file 4." << std::endl;
        return -1;
    }
    // file five: output file
    std::ofstream outputfile(argv[5]);
    if (!outputfile.is_open())
    {
        std::cout << "Could not open the output file" << std::endl;
        return -1;
    }

    Analyzer sentimentAnalyzer;
    sentimentAnalyzer.learn(inFile1, inFile2);
    sentimentAnalyzer.test(inFile3, inFile4);
    sentimentAnalyzer.print(outputfile);
    std::cout<<"program finished";

    return 0;
}


