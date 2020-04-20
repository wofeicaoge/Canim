//
// Created by haozi on 4/19/20.
//

#include <utils/Color.h>

namespace Canim {
const std::map<std::string_view, RGB> Color::color_map_ = {
    {"WHITE", {1, 1, 1}}, {"BLACK", {0, 0, 0}}};
}