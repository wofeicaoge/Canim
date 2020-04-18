#include <animation/animation.h>
#include "../boost_unit_test.h"

BOOST_AUTO_TEST_SUITE(anim_unit)

BOOST_AUTO_TEST_CASE(anim_test)
{
    animation anim(2);
    BOOST_CHECK_EQUAL(anim.get_run_time(), 2);
}

BOOST_AUTO_TEST_SUITE_END()