#include "spctools.h"
#include "matplot/matplot.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void Plot(double* x, double* y, size_t length) {
    std::vector<double> xv(x, x + length);
    std::vector<double> yv(y, y + length);
    matplot::plot(xv, yv);
}

void Hold(uint8_t flag) {
    if (flag) {
        matplot::hold(matplot::on);
    } else {
        matplot::hold(matplot::off);
    }
}

void Show() {
    matplot::show();
}

#ifdef __cplusplus
}
#endif
