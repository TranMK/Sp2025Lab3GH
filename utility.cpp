#include <cmath>
const double EPSILON = 1e-4;

bool doubles_equal(double a, double b) {
  if (std::fabs(a - b) < EPSILON) {
   return true; 
  }
  return false;
}
