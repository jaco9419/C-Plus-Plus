#include <iostream>

// Very basic calculation. Just using the main function.

int main() {
  
  double tempf = 34.0;
  double tempc;
  
  tempc = (tempf - 32) / 1.8;
  
  std::cout << "The temp is " << tempc << " degrees Celsius.\n";
  
}
