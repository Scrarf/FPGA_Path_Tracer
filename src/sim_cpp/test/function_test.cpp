#include "../functions.h"
#include <cmath>

int main() {

	double rand[3];

	for (int i = 0; i < 3; i++) {
		rand[i] = random_double(-10, 10);
	}


	uint32_t arr[3];

	double3_to_packed_float3(arr, rand[0], rand[1], rand[2]);

	double ans_x, ans_y, ans_z;
	packed_float3_to_double3(&ans_x, &ans_y, &ans_z, arr);

	if ((fabs(rand[0] - ans_x) > 0.1)) {
		printf("nope\n");
		
		printf("%f, %f\n", rand[0], ans_x);
		
	}
	else {
		printf("yay\n");
	}
	
	return 0;
	
}
