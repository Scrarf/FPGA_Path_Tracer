#include <math.h>
#include <stdio.h>
#include <random>

#define EXP 8
#define FRAC 12

#define UNPACK_SIGN(x) (x >> (EXP + FRAC + 2))
#define UNPACK_EXP(x) /*((x >> (EXP + 1)) & !(0xFFFFFFFF << (EXP + 1)))*/ 0
#define UNPACK_FRAC(x) (x & !(0xFFFFFFFF << (FRAC + 1)))

typedef struct {
    int sign;
    int exp;
    int frac;
} u_float;


int sign_extend_exp(int exp) {
    int shift = 32 - EXP;
    return (exp << shift) >> shift;
}


double to_double(int sign, int exp, int frac) {

    exp = sign_extend_exp(exp);

    double value;
    value = (double)frac / (1 << FRAC);
    value = value * pow(2, exp);
    if (sign) {
        value = -value;
    }
    return value;
}

double packed_array_to_double(int p_float) {

    //int exp = ((p_float >> (FRAC + 1)) & ~(0xFFFFFFFF << (EXP)));
    //exp = ((p_float >> (FRAC + EXP + 1)) & 1) ? -exp : exp;
    int exp = sign_extend_exp((p_float >> (FRAC + 1)) & ~(0xFFFFFFFF << (EXP + 1)));
    //printf("RAW EXPONENT: %d\n", exp);
    double value;
    //printf("RAW VALUE: %b\n", (p_float & ~(0xFFFFFFFF << (FRAC + 1))));
    value = (double)(p_float & ~(0xFFFFFFFF << (FRAC + 1))) / (1 << FRAC);
    //printf("VALUEEEE: %f\n", value);
    value = value * pow(2, exp);
    if (p_float >> (EXP + FRAC + 2)) {
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


int pack_struct (u_float u_float) {
    return u_float.frac | (u_float.exp << 12 ) | (u_float.sign << 20); 
}

int double_to_packed_array (double val) {
    int sign = (val < 0);
    int exp = (int)floor(log2(fabs(val)));
    int frac = (int)floor((fabs(val) / pow(2.0, exp)) * (1 << (FRAC)));
    //printf("THE THING: %f\n", (fabs(val) / pow(2.0, exp)) * (1 << (FRAC)));
    //printf("frac: %d\n",frac);

    //exp = (exp < 0) ?  : exp;

    return (sign << (EXP + FRAC + 2)) | ((exp & ~(0xFFFFFFFF << (EXP + 1))) << (FRAC + 1)) | frac;
}

