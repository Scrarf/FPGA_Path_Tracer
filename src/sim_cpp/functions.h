#include <math.h>
#include <stdio.h>
#include <random>

#define INT_MAX 0xFFFFFFFF

#define EXP 8
#define FRAC 12

uint32_t float_size = EXP + FRAC + 3;

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
    int exp = sign_extend_exp((p_float >> (FRAC + 1)) & ~(INT_MAX << (EXP + 1)));
    //printf("RAW EXPONENT: %d\n", exp);
    
    double value;
    //printf("RAW VALUE: %b\n", (p_float & ~(INT_MAX << (FRAC + 1))));
    
    value = (double)(p_float & ~(INT_MAX << (FRAC + 1))) / (1 << FRAC);
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
    return (sign << (EXP + FRAC + 2)) | ((exp & ~(INT_MAX << (EXP + 1))) << (FRAC + 1)) | frac;
}

void double3_to_packed_float3(uint32_t* packed_float3, double dx, double dy, double dz) {
	
	uint32_t x = double_to_packed_array(dx);
	uint32_t y = double_to_packed_array(dy);
	uint32_t z = double_to_packed_array(dz);
	
	packed_float3[0] = z | (y << float_size);
	packed_float3[1] = (y >> (32 - float_size)) | (x << (32 - (2 * (32 - float_size))));
	packed_float3[2] = x >> (2 * (32 - float_size));
	return;
}

void packed_float3_to_double3(double* x, double* y, double* z, uint32_t packed_float3[]) {

	uint32_t mask = ~(INT_MAX << float_size);

	uint32_t iz = (uint32_t)packed_float3[0] & (mask);
	uint32_t iy = (((uint32_t)packed_float3[0] >> float_size) | ((uint32_t)packed_float3[1] << (32 - float_size))) & mask;
	uint32_t ix = ((uint32_t)packed_float3[1] >> ((2 * float_size) - 32)) | (uint32_t)packed_float3[2] << (32 - ((2 * float_size) - 32));

	*x = packed_array_to_double(ix);
	*y = packed_array_to_double(iy);
	*z = packed_array_to_double(iz);

	return;
}
