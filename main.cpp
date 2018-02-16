#include <iostream>
#include <exception>

class DivideByZeroException : public std::exception {
private:
  int denom;
public:
  DivideByZeroException(int denom) : denom(denom) {}
  virtual const char* what() const throw() {
    return "Attempted to divide by zero.";
  }
};

float divide(float numerator, float denominator) {
  if (denominator == 0) {
    // throw "Tried to divide by 0";
    throw DivideByZeroException(denominator);
  }
  // if (numerator == 7) {
  //   throw '7';
  // }
  std::cout << "Returning from divide()" << std::endl;
  return numerator / denominator;
}

void foo() {
  int* array = new int[10];
  divide(10, 0);
  std::cout << "Feeing array" << std::endl;
  delete[] array;
}

int main(int argc, char const *argv[]) {

  try {
    foo();
    divide(7, 1);
  } catch (DivideByZeroException& e) {
    std::cerr << "Error when dividing: " << e.what() << std::endl;
  }
  // catch (const char* e) {
  //   std::cerr << "Error when dividing: " << e << std::endl;
  // } catch (int e) {
  //   std::cerr << "Tried to divide 7 by something" << std::endl;
  // } catch (...) {
  //   std::cerr << "Caught some exception" << std::endl;
  // }

  return 0;
}
