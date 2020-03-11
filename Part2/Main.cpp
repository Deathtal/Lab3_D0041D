#include <iostream>

const static int32_t ARRAY_SIZE = 9;
const static int32_t MAX_RAND_VALUE = 100;

struct ResultIndeces {
	int32_t High;
	int32_t Low;
	int32_t Numerator;
	int32_t Denominator;
};

ResultIndeces findIndecesForMaximumValueOfOneDividedByAPreviusOne(int* arr, int32_t N) {
	if (N == 3) {
		ResultIndeces result;
		if (arr[0] <= arr[1]) {
			result.Denominator = 0;
			result.High = arr[1] > arr[2] ? 1 : 2;
			result.Low = arr[0] <= arr[2] ? 0 : 2;
		}
		else {
			result.Denominator = 1;
			result.High = arr[0] > arr[2] ? 0 : 2;
			result.Low = arr[1] <= arr[2] ? 0 : 2;
		}
		if (arr[1] >= arr[2] && result.Denominator == 0) {
			result.Numerator = 1;
		}
		else {
			result.Numerator = 2;
		}
		return result;
	}
	if (N == 2) {
		ResultIndeces result;
		if (arr[0] <= arr[1]) {
			result.High = 1;
			result.Low = 0;
			result.Numerator = 1;
			result.Denominator = 0;
		}
		else {
			result.High = 0;
			result.Low = 1;
			result.Numerator = 1;
			result.Denominator = 0;
		}
		return result;
	}
	ResultIndeces result;
	ResultIndeces result_l = findIndecesForMaximumValueOfOneDividedByAPreviusOne(arr, N / 2);
	ResultIndeces result_r = findIndecesForMaximumValueOfOneDividedByAPreviusOne(arr + N / 2, N - N / 2);
	result.High = arr[result_l.High] > arr[(result_r.High += N / 2)] ? result_l.High : result_r.High;
	result.Low = arr[result_l.Low] <= arr[(result_r.Low += N / 2)] ? result_l.Low : result_r.Low;

	double div_l = (double)arr[result_l.Numerator] / (double)arr[result_l.Denominator];
	double div_r = (double)arr[(result_r.Numerator += N / 2)] / (double)arr[(result_r.Denominator += N / 2)];
	double div_quota = (double)arr[result_r.High] / (double)arr[result_l.Low];

	if (div_quota >= div_l) {
		if (div_quota >= div_r) {
			result.Numerator = result_r.High;
			result.Denominator = result_l.Low;
		}
		else {
			result.Numerator = result_l.Numerator;
			result.Denominator = result_l.Denominator;
		}
	}
	else {
		if (div_l >= div_r) {
			result.Numerator = result_l.Numerator;
			result.Denominator = result_l.Denominator;
		}
		else {
			result.Numerator = result_r.Numerator;
			result.Denominator = result_r.Denominator;
		}
	}
	return result;
}



int main() {
	int a[ARRAY_SIZE];

	/*for (int& i : a) {
		i = rand() % ARRAY_SIZE + 1;
	}*/

	for (int32_t i = 0; i < ARRAY_SIZE; ++i) {
		a[i] = ARRAY_SIZE - i;
	}

	for (int32_t i = 0; i < ARRAY_SIZE; ++i) {
		std::cout << i << ": " << a[i] << "\n";
	}

	ResultIndeces result = findIndecesForMaximumValueOfOneDividedByAPreviusOne(a, ARRAY_SIZE);

	std::cout << "\nHigh: index: " << result.High << ", value: " << a[result.High];
	std::cout << "\nLow: index: " << result.Low << ", value: " << a[result.Low];
	std::cout << "\nNumerator index: " << result.Numerator << ", Denominator index: " << result.Denominator << "\n";
	std::cout << a[result.Numerator] << "/" << a[result.Denominator] << " = " << (double)a[result.Numerator] / (double)a[result.Denominator];
}