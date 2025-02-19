// FREEZE CODE BEGIN
#include <iostream>
#include "ABS.h"
#include "hidden.h"
using namespace std;

int StudentTest();

int main()
{
  int option = 0;
  cin >> option;
  if(option == 1){
    if (testDefaultConstructorAndGetSize()) {
          std::cout << "Default constructor and getSize() PASSED" << std::endl;;
      } else {
          std::cout << "Default constructor and getSize() FAILED" << std::endl;
      }
  }
  if(option == 2){
    if (testParameterizedConstructor()) {
        std::cout << "Parameterized constructor test PASSED" << std::endl;
    } else {
        std::cout << "Parameterized constructor test FAILED" << std::endl;
    }
  }
  if(option == 3){
    if (testResizingOnPush()) {
        std::cout << "Resizing on push test PASSED" << std::endl;
    } else {
        std::cout << "Resizing on push test FAILED" << std::endl;
    }
  }
  if(option == 4){
    if (testPoppingFromABS()) {
        std::cout << "Popping from ABS test PASSED" << std::endl;
    } else {
        std::cout << "Popping from ABS test FAILED" << std::endl;
    }
  }
  if(option == 5){
    if (testPoppingFromEmptyABS()) {
        std::cout << "Popping from empty ABS test PASSED" << std::endl;
    } else {
        std::cout << "Popping from empty ABS test FAILED" << std::endl;
    }
  }
  if(option == 6){
    if (testPeekingAtEmptyABS()) {
        std::cout << "Peeking at an empty ABS test PASSED" << std::endl;
    } else {
        std::cout << "Peeking at an empty ABS test FAILED" << std::endl;
    }
  }
  if(option == 7){
    if (testPeekingAtContents()) {
        std::cout << "Peeking at contents of ABS test PASSED" << std::endl;
    } else {
        std::cout << "Peeking at contents of ABS test FAILED" << std::endl;
    }
  }
  if(option == 8){
    if (testProperResizingAfterPopping()) {
        std::cout << "Proper resizing after popping test PASSED" << std::endl;
    } else {
        std::cout << "Proper resizing after popping test FAILED" << std::endl;
    }
  }
	if(option == 9){
    FullTest();
  }
  if(option == 10){
    StudentTest();
  }

	return 0;
}
// FREEZE CODE END

int StudentTest() {
  // If you would like to test your code
  // (won't affect tests at all!)
}