#ifndef FRACTALCREATOR_H
#define FRACTALCREATOR_H

#include <string>
#include "Bitmap.h"
#include "ZoomList.h"
#include "memory"

using namespace std;

namespace caveofprogramming {

class FractalCreator {
private:
  int m_width;
  int m_height;
  unique_ptr<int[]> m_histogram;
  unique_ptr<int[]> m_fractal;
  Bitmap m_bitmap;
  ZoomList m_zoomList;
  int m_total{0};
public:
  FractalCreator(int width, int height);

  void calculateIterations();
  void calculateTotalIterations();
  void drawFractal();
  void writeBitMap(string name);
  void addZoom(const Zoom& zoom);
};


}

#endif // FRACTALCREATOR_H
