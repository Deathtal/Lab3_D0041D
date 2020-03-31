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
