#include <iostream>
#include <vector>

int main() {
  std::vector<int> numbers = {2,4,3,6,1,9};
  int totalEven = 0;
  int totalOdd = 1;

  for (int i = 0; i < numbers.size(); i++) {
    if (numbers[i] % 2 == 0) {
      totalEven += numbers[i];
    } else {
      totalOdd *= numbers[i];
    }
  }

  std::cout << "Sum of even numbers is " << totalEven << std::endl;
  std::cout << "Product of odd numbers is " << totalOdd << std::endl;
}
