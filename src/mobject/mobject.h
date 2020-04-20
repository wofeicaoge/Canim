#ifndef CANIM_MOBJECT_H
#define CANIM_MOBJECT_H

#include <functional>
#include <utils/Color.h>
#include <vector>

namespace Canim {
class Mobject {
public:
  explicit Mobject(int dim = 3) : dim_(dim) {}

  void set_color(Color color) { color_ = color; }

  [[nodiscard]] const Color &get_color() const { return color_; }

  void add_updater(const std::function<void(Mobject *)> &updater);

private:
  int dim_{0};
  Color color_ = Color(std::string_view("BLACK"));
  std::vector<std::function<void(Mobject *)>> updaters_{};
};
} // namespace Canim

#endif // CANIM_MOBJECT_H