#include <stdint.h>
#include <stdio.h>
#include <immintrin.h>
#define KB 1024
#define MB 1024*KB

double compute_pi(size_t dt)
{
	double pi = 0.0;
	double delta = 1.0 / dt;
	for (size_t i = 0; i < dt; i++) {
		double x = (double) i / dt;
		pi += delta / (1.0 + x * x);
	}
	return pi * 4.0;
}

double compute_pi2(size_t dt)
{
	double pi = 0.0;
	double delta = 1.0 / dt;
	register __m256d ymm0, ymm1, ymm2, ymm3, ymm4;
	ymm0 = _mm256_set1_pd(1.0);
	ymm1 = _mm256_set1_pd(delta);
	ymm2 = _mm256_set_pd(delta * 3, delta * 2, delta * 1, 0.0);
//	ymm4 = _mm256_setzero_pd();
	ymm4 = _mm256_set1_pd(0);

	for (int i = 0; i <= dt - 4; i += 4) {
		ymm3 = _mm256_set1_pd(i * delta);
		ymm3 = _mm256_add_pd(ymm3, ymm2);
		ymm3 = _mm256_mul_pd(ymm3, ymm3);
		ymm3 = _mm256_add_pd(ymm0, ymm3);
		ymm3 = _mm256_div_pd(ymm1, ymm3);
		ymm4 = _mm256_add_pd(ymm4, ymm3);
	}
	double tmp[4] __attribute__((aligned(32)));
	_mm256_store_pd(tmp, ymm4);
	pi += tmp[0] + tmp[1] + tmp[2] + tmp[3];
//	pi += ymm3[0] + ymm3[1] + ymm3[2] + ymm3[3];

	return pi * 4.0;
}

double F(int i, size_t dt){
	if(i == dt)
		return 1;
	else
		return 1 + i/(2.0*i + 1) * F(i+1, dt);
}

double compute_pi3(size_t dt)
{
	double pi = 2 * F(1, dt);
	return pi;
}

int main(void)
{

	double result = compute_pi(128*MB);
//	double result2 = compute_pi2(128*MB);
	double result3 = compute_pi3(128*MB);

	printf("result is %lf\n", result);
//	printf("result is %lf\n", result2);
	printf("result is %lf\n", result3);

	return 0;
}
