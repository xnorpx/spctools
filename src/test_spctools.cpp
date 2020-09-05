#include "spctools.h"
#include <gtest/gtest.h>

TEST(SPCTools, Plot) {
    double x[] = {1,2,3,4};
    double y[] = {1,2,2,4};
    Plot(&x[0], &y[0], 4);
    Hold(1);
    y[2] = 3;
    Plot(&x[0], &y[0], 4);
    Show();
}
