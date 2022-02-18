// add your code
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reservoir.h"

//type function name(std::type date)
double get_east_storage(std::string date)
{
  //reads file
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) {
      std::cerr << "File cannot be opened for reading." << std::endl;
      exit(1); // exit if failed to open the file
  }

  std::string junk;        // new string variable
  getline(fin, junk); // read one line from the file

  std::string date1;
  double eastSt, eastEl, westSt, westEl;
  while(fin >> date1 >> eastSt >> eastEl >> westSt >> westEl) {
    // this loop reads the file line-by-line
    // extracting 5 values on each iteration
    fin.ignore(INT_MAX, '\n'); //skips to the end of line, ignoring the remaining columns
    if (date1 == date){
      return eastSt;
    }
    // for example, to print the date and East basin storage:
    //std::cout << date << " " << eastSt << std::endl;
    }

    fin.close();
    return eastSt;

}

double get_min_east() {
  //reads file
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) {
      std::cerr << "File cannot be opened for reading." << std::endl;
      exit(1); // exit if failed to open the file
  }

  std::string junk;        // new string variable
  getline(fin, junk); // read one line from the file

  std::string date;
  double eastSt, eastEl, westSt, westEl;
  double min = INT_MAX;
  while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
    // this loop reads the file line-by-line
    // extracting 5 values on each iteration
    fin.ignore(INT_MAX, '\n'); //skips to the end of line, ignoring the remaining columns
    if (eastSt < min){
      min = eastSt;
    }
    // for example, to print the date and East basin storage:
    //std::cout << date << " " << eastSt << std::endl;
    }

    fin.close();
    return min;

}

double get_max_east() {
  //reads file
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) {
      std::cerr << "File cannot be opened for reading." << std::endl;
      exit(1); // exit if failed to open the file
  }

  std::string junk;        // new string variable
  getline(fin, junk); // read one line from the file

  std::string date;
  double eastSt, eastEl, westSt, westEl;
  double max = INT_MIN;
  while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
    // this loop reads the file line-by-line
    // extracting 5 values on each iteration
    fin.ignore(INT_MAX, '\n'); //skips to the end of line, ignoring the remaining columns
    if (eastSt > max){
      max = eastSt;
    }
    // for example, to print the date and East basin storage:
    //std::cout << date << " " << eastSt << std::endl;
    }

    fin.close();
    return max;

}

double get_west_storage(std::string date)
{
  //reads file
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) {
      std::cerr << "File cannot be opened for reading." << std::endl;
      exit(1); // exit if failed to open the file
  }

  std::string junk;    // new string variable
  getline(fin, junk); // read one line from the file

  std::string date1;
  double eastSt, eastEl, westSt, westEl;
  while(fin >> date1 >> eastSt >> eastEl >> westSt >> westEl) {
    // this loop reads the file line-by-line
    // extracting 5 values on each iteration
    fin.ignore(INT_MAX, '\n'); //skips to the end of line, ignoring the remaining columns
    if (date1 == date){
      return westSt;
    }
    // for example, to print the date and East basin storage:
    //std::cout << date << " " << eastSt << std::endl;
    }

    fin.close();
    return westSt;

}

std::string compare_basins(std::string date)
{
	double west = get_west_storage(date);
  double east = get_east_storage(date);

    if (west > east){
      return "West";
    }
    else if (east > west){
      return "East";
    }
    else if (east == west){
      return "Equal";
    }
    return "null";
}
