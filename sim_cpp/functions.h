#include <math.h>
#include <stdio.h>
#include <random>

#define EXP 8
#define FRAC 12

double to_double(int sign, int exp, int frac) {
    double value;
    value = (double)frac / (1 << FRAC);
    value = value * pow(2, exp);
    if (sign) {
        value = -value;
    }
    return value;
}

void to_int(double flt, int* sign, int* exp, int* frac) {

    if (flt < 0) {
        *sign = 1;
        flt = -flt;
    } else {
        *sign = 0;
    }

    if (flt == 0.0) {
        *exp = 0;
        *frac = 0;
        return;
    }

    int actual_exp = (int)floor(log2(flt));
    *exp = actual_exp;

    double mantissa_double = flt / pow(2.0, actual_exp);


    *frac = (int)round(mantissa_double * (1 << 12));

    if (*frac == (1 << 13)) {
        *exp += 1;
        *frac = (1 << 12);
    }
}

double random_double(double min = -100.0, double max = 100.0) {
    static std::random_device rd;   // For seeding
    static std::mt19937 gen(rd());  // Mersenne Twister engine
    std::uniform_real_distribution<double> dist(min, max);
    return dist(gen);
}