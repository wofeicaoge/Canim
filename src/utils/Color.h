//
// Created by haozi on 4/19/20.
//

#ifndef CANIM_COLOR_H
#define CANIM_COLOR_H

#include <cassert>
#include <cctype>
#include <map>
#include <tuple>

namespace Canim {
struct RGB {
  uint8_t red_;
  uint8_t green_;
  uint8_t blue_;
};

class Color {
public:
  explicit Color(uint8_t red = 0, uint8_t green = 0, uint8_t blue = 0,
                 uint8_t alpha = 0)
      : rgb_{red, green, blue}, alpha_{alpha} {}
  explicit Color(std::string_view color_name, uint8_t alpha = 0)
      : alpha_{alpha} {
    const auto &rgb = color_map_.find(color_name);
    assert(rgb != color_map_.end());
    rgb_ = rgb->second;
  }

  [[nodiscard]] auto get_rgb() const { return rgb_; }
  [[nodiscard]] auto get_alpha() const { return alpha_; }

private:
  RGB rgb_{0, 0, 0};
  uint8_t alpha_{0};

private:
  static const std::map<std::string_view, RGB> color_map_;
};
} // namespace Canim

#endif // CANIM_COLOR_H
