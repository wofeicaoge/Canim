#ifndef CANIM_MOBJECT_H
#define CANIM_MOBJECT_H

#include <string_view>
#include <cctype>
#include <utils/Color.h>

namespace Canim {
    class Mobject {
    public:
        explicit Mobject(int dim = 3) : dim_(dim) {}
        void set_color(Color color) { color_ = color;}
        const Color& get_color() const {return color_;}
    private:
        int dim_;
        Color color_ = Color(std::string_view("BLACK"));
    };
}

#endif //CANIM_MOBJECT_H