class SmallestMissing 
{ 
	int findFirstMissing(int array[], int start, int end) 
	{ 

		System.out.println("Start: " +start);
		if (start > end) 
			return end + 1; 

		if (start != array[start])
		{
			System.out.println("start: " +start);
			return start; 
		}
		int mid = (start + end) / 2; 
		System.out.println("Mid: " +mid);

		// Left half has all elements from 0 to mid 
		if (array[mid] == mid) {
			System.out.println("End :"+end);
			return findFirstMissing(array, mid+1, end); 
		}
		return findFirstMissing(array, start, mid); 
	} 

	public static void main(String[] args) 
	{ 
		SmallestMissing small = new SmallestMissing(); 
		int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 10}; 
		int n = arr.length; 
		System.out.println("First Missing element is : "
				+ small.findFirstMissing(arr, 0, n - 1)); 
	} 
}
