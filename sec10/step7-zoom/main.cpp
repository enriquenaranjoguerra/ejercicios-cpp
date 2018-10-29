#include <iostream>
#include <cstdint>
#include <memory>

#include "FractalCreator.h"

using namespace std;
using namespace caveofprogramming;

int main() {

  int const height = 600;

  FractalCreator fractalCreator(800, 600);

  fractalCreator.addZoom(Zoom(295, height - 202, 0.1));
  fractalCreator.addZoom(Zoom(312, height - 304, 0.1));
  fractalCreator.calculateIterations();
  fractalCreator.calculateTotalIterations();
  fractalCreator.drawFractal();
  fractalCreator.writeBitMap("test.bmp");

  cout << "Finished." << endl;
  return 0;
}
