#ifndef CANIM_ANIMATION_H
#define CANIM_ANIMATION_H


#include <cstdint>

class animation {
public:
    animation(int run_time) : run_time_(run_time) {}

    int get_run_time() const { return run_time_; }

    void echo() const;

private:
    int run_time_;
};


#endif //CANIM_ANIMATION_H
