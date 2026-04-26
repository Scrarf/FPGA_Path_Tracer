#include <math.h>
#include <stdio.h>
#include <random>

#define EXP 8
//#define FRAC 12
#define FRAC 23

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


double packed_array_to_double(uint64_t p_float) {
	//if (p_float == 0) return 0.0;

	//int frac_raw = p_float & ~(~0LL << (FRAC + 1));
	//printf("frac %b\n", frac_raw);

    int exp = sign_extend_exp((p_float >> (FRAC + 1)) & ~(~0LL << (EXP + 1)));
    //printf("RAW EXPONENT: %d\n", exp);
    
    double value;
    //printf("RAW VALUE: %b\n", (p_float & ~(~0LL << (FRAC + 1))));
    
    value = (double)(p_float & ~(~0LL << (FRAC + 1))) / (1 << FRAC);
    //printf("VALUEEEE: %f\n", value);
    
    value = value * pow(2, exp);
    if (p_float >> (EXP + FRAC + 2)) {
        value = -value;
    }
    //printf("coverage_3\n");
    return value;
}

uint64_t double_to_packed_array(double val) {
	//if (val == 0.0) return 0;
	
    uint64_t sign = (val < 0);
    int64_t exp = (int)floor(log2(fabs(val)));
    uint64_t frac = (int)floor((fabs(val) / pow(2.0, exp)) * (1 << (FRAC)));
    //printf("frac: %d\n",frac);

	//printf("coverage_6\n");
    return (sign << (EXP + FRAC + 2)) | ((exp & ~(~0LL << (EXP + 1))) << (FRAC + 1)) | frac;
}

void write_bits(uint32_t* arr, int offset, uint64_t val, int width) {
    for (int i = 0; i < width; i++) {
        int bit = offset + i;
        if ((val >> i) & 1)
            arr[bit / 32] |= (1u << (bit % 32));
        else
            arr[bit / 32] &= ~(1u << (bit % 32));
    }
}

uint64_t read_bits(uint32_t* arr, int offset, int width) {
    uint64_t val = 0;
    for (int i = 0; i < width; i++) {
        int bit = offset + i;
        if ((arr[bit / 32] >> (bit % 32)) & 1)
            val |= (1ULL << i);
    }
    return val;
}

void double3_to_packed_float3(uint32_t* arr, double dx, double dy, double dz) {
    write_bits(arr, 0,           double_to_packed_array(dz), float_size);
    write_bits(arr, float_size,  double_to_packed_array(dy), float_size);
    write_bits(arr, float_size*2,double_to_packed_array(dx), float_size);
}

void packed_float3_to_double3(double* dx, double* dy, double* dz, uint32_t* arr) {
    *dz = packed_array_to_double(read_bits(arr, 0,            float_size));
    *dy = packed_array_to_double(read_bits(arr, float_size,   float_size));
    *dx = packed_array_to_double(read_bits(arr, float_size*2, float_size));
}
