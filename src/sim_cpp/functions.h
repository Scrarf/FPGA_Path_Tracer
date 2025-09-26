#include <math.h>
#include <stdio.h>
#include <random>

#define EXP 8
#define FRAC 12


typedef struct {
    int sign;
    int exp;
    int frac;
} u_float;

typedef struct {
	u_float x, y, z;
} u_float3;


double random_double(double min = -100.0, double max = 100.0) {
    static std::random_device rd;   // For seeding
    static std::mt19937 gen(rd());  // Mersenne Twister engine
    std::uniform_real_distribution<double> dist(min, max);
    return dist(gen);
}

int sign_extend_exp(int exp) {
    int shift = 32 - EXP;
    //printf("coverage_1\n");
    return (exp << shift) >> shift;
}


double packed_array_to_double(int p_float) {
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
    //printf("coverage_3\n");
    return value;
}


uint32_t double_to_packed_array(double val) {
    uint32_t sign = (val < 0);
    int32_t exp = (int)floor(log2(fabs(val)));
    uint32_t frac = (int)floor((fabs(val) / pow(2.0, exp)) * (1 << (FRAC)));
    //printf("frac: %d\n",frac);

	//printf("coverage_6\n");
    return (sign << (EXP + FRAC + 2)) | ((exp & ~(0xFFFFFFFF << (EXP + 1))) << (FRAC + 1)) | frac;
}

void double3_to_packed_float3(uint32_t* tmp_array, double dx, double dy, double dz) {
	
	uint32_t x = double_to_packed_array(dx);
	uint32_t y = double_to_packed_array(dy);
	uint32_t z = double_to_packed_array(dz);
	
	uint32_t float_size = EXP + FRAC + 3;
	tmp_array[0] = x | (y >> float_size);
	tmp_array[1] = (y << (32 - float_size)) | (z >> (32 - float_size)) | (z <<  (2 * (32 - float_size)));
	tmp_array[2] = z << (2 * (32 - float_size));
	return;
}


/*
double to_double(int sign, int exp, int frac) {

    exp = sign_extend_exp(exp);

    double value;
    value = (double)frac / (1 << FRAC);
    value = value * pow(2, exp);
    if (sign) {
        value = -value;
    }
    printf("coverage_2\n");
    return value;
}
*/

/*
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
    printf("coverage_4\n");
}
*/


/*
int pack_struct (u_float u_float) {
	printf("coverage_5\n");
    return u_float.frac | (u_float.exp << 12 ) | (u_float.sign << 20);
     
}
*/




