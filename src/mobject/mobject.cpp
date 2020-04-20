//
// Created by haozi on 4/20/20.
//
#include "mobject.h"

namespace Canim {

void Mobject::add_updater(const std::function<void(Mobject *)> &updater) {
  updaters_.push_back(updater);
}
} // namespace Canim
