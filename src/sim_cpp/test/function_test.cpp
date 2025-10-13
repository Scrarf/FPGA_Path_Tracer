#include "../functions.h"
#include <cmath>

#define MARGIN 0.001

#define STEPS 1000000

int main() {

	for (int i = 0; i < STEPS; i++) {

		double rand[3];
	
		for (int i = 0; i < 3; i++) {
			rand[i] = random_double(-10, 10);
		}
	
	
		uint32_t arr[3];
	
		double3_to_packed_float3(arr, rand[0], rand[1], rand[2]);
	
		double ans_x, ans_y, ans_z;
		packed_float3_to_double3(&ans_x, &ans_y, &ans_z, arr);
	
		if ((fabs(rand[0] - ans_x) > MARGIN) || (fabs(rand[1] - ans_y) > MARGIN) || (fabs(rand[2] - ans_z) > MARGIN)) {
			printf("nope: in: [%.4f, %.4f, %.4f] out: [%.4f, %.4f, %.4f] \n",rand[0], rand[1], rand[2], ans_x, ans_y, ans_z );
			
		}
		//else {
		//	printf("yay!\n");
		//}

	}
	
	return 0;
	
}
