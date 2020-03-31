Course: D0041D  
Student: Herman Åberg
## Part I
### Problem
Design a divide and conquer algorithm to compute the first three smallest elements in an array of _n_ (_n_ ≥ 3) distinct elements. The algorithm should run in linear time in the worst case and should return the indeces of the three smallest elements sorted from smallest to largest.
### Algorithm
1. Find the median of the array using **median of medians**(**BFPRT**): _O_(_n_)
2. Use the median as a pivot for **quickselect** to find the third smallest element: _O_(_n_)  
	The two smallest elements are now located to the left of the third smallest.
3. ```return (arr[0] < arr[1]) ? (arr[0], arr[1], arr[2]) : (arr[1], arr[0], arr[2]);```

Total time complexity: _O_(_n_)

## Part II
### Problem
Design a divide and conquer algorithm that, given an array _a_ =
{_a_(1), _a_(2), ···, _a_(_n_)} of positive numbers, _n_ ≥ 2, determines two indices 1 ≤ _i_ < _j_ ≤ _n_ such
that _a_(_j_) divided by _a_(_i_) is maximized over all such indices. Your algorithm should run in _O_(_n_) time in the
worst case.
## Algorithm
1. Divide the array into two parts, do this recursively until the subarray reaches the size of 3 or 2
2. Calculate and return a struct that contains the indeces for the
	* Highest value
	* Lowest value
	* Numerator
	* Denominator

The Numerator and Denominator are the highest result from dividing values in the subarray where:  
* Numerator index > Denominator index

3. Add the highest and lowest value out of the structs returned from the left and right subarrays to a new struct
4. Compare the results of the Numerator / Denominator of the struct from the left and right subarray aswell as with the highest value from the right subarray divided by the lowest value from the left subarray. The indeces resulting in the highest result are saved into the new struct
5. Return the new struct
