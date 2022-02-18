#include <iostream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reverseorder.h"

void reverseorder(std::string date1, std::string date2){
    //reads file
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1); // exit if failed to open the file
    }

    std::string junk;    // new string variable
    getline(fin, junk); // read one line from the file

    std::string date;
    double eastSt, eastEl, westSt, westEl;

    std::string dateArray[365];
    double westE[365];
    int j = 0;
    bool startDate = false;


    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
      // this loop reads the file line-by-line
      // extracting 5 values on each iteration
      fin.ignore(INT_MAX, '\n'); //skips to the end of line, ignoring the remaining columns

      if (date1 == date) {
        startDate = true;
      }

      if (startDate) {
        dateArray[j] = date;
        westE[j] = westEl;
        j++;
      }

      if (date2 == date){
        startDate = false;
      }

    }

      fin.close();
      for(int i = j - 1; i >= 0; i--){
        std::cout << dateArray[i] << " " << westE[i] << std::endl;
      }


  }
