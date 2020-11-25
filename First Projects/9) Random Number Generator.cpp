#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
  // This accesses to the clock in our computer, which will give srand a different number each time it runs.
  // Else, the same numbers would be displayed every time we run this program.
  
  srand(time(0));
  
  for(int x = 1; x < 25; x++) {
  
    // The remainder and the 1+ control the range for the random number, 1-6 inclusive in this case. 
    // If I didn't add 1+, it would be from 0-5.
    
    std::cout << 1+(rand() % 6) << std::endl;
  }
}
