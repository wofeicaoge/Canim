#include <iostream>
#include <mobject/mobject.h>
#include <utils/Color.h>

using namespace Canim;

int main() {
  Mobject obj(3);
  auto color = obj.get_color();
  auto [r, g, b] = color.get_rgb();
  std::cout << static_cast<int>(r) << " " << static_cast<int>(g) << " "
            << static_cast<int>(b) << std::endl;
  std::cout << "End" << std::endl;
  return 0;
}
