// add your code as appropriate
#include <iostream>
#include "reservoir.h"
#include "reverseorder.h"

int main(){

  std::cout << "Enter date: 06/28/2018" << std::endl;
  std::cout << "East Basin Storage: " << get_east_storage("06/28/2018") << " billion gallons" << std::endl;

  std::cout << "Enter date: 12/05/2018" << std::endl;
  std::cout << "East Basin Storage: " << get_east_storage("12/05/2018") << " billion gallons" << std::endl;

  std::cout << "Enter date: 5/31/2018" << std::endl;
  std::cout << "East Basin Storage: " << get_east_storage("05/31/2018") << " billion gallons" << std::endl;

  std::cout << "Minimum storage in the East Basin: " << get_min_east() << " billion gallons" << std::endl;
  std::cout << "Maximum storage in the East Basin: " << get_max_east() << " billion gallons" << std::endl;

  std::cout << "09/21/2018 " << compare_basins("09/21/2021") << std::endl;
  std::cout << "07/14/2018 " << compare_basins("07/14/2021") << std::endl;
  std::cout << "10/25/2018 " << compare_basins("10/25/2021") << std::endl;

  reverseorder("05/20/2018","05/31/2018");


  return 0;
}
