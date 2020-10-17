// Problem: Pair with given sum and maximum shortest distance from end

// Java code to find maximum shortest distance 
// from endpoints 
import java.util.*; 

class Hashing 
{ 
static void makePermutation(int []a, int n) 
{ 
	// Store counts of all elements. 
	HashMap<Integer, 
			Integer> count = new HashMap<Integer, 
										Integer>(); 
	for (int i = 0; i < n; i++) 
	{ 
		if(count.containsKey(a[i])) 
		{ 
			count.put(a[i], count.get(a[i]) + 1); 
		} 
		else
		{ 
			count.put(a[i], 1); 
		} 
	} 
} 

// function to find maximum shortest distance 
static int findMaximum(int a[], int n, int k) 
{ 
	// stores the shortest distance of every 
	// element in original array. 
	HashMap<Integer, 
			Integer> b = new HashMap<Integer, 
									Integer>(); 
	
	for (int i = 0; i < n; i++) 
	{ 
		int x = a[i]; 
		
		// shortest distance from ends 
		int d = Math.min(1 + i, n - i); 
		if (!b.containsKey(x)) 
			b.put(x, d); 

		else
		{ 

			/* if duplicates are found, b[x] 
			is replaced with minimum of the 
			previous and current position's 
			shortest distance*/
			b. put(x, Math.min(d, b.get(x))); 
		} 
	} 
	
	int ans = Integer.MAX_VALUE; 
	for (int i = 0; i < n; i++) 
	{ 
		int x = a[i]; 
		
		// similar elements ignore them 
		// cause we need distinct elements 
		if (x != k - x && b.containsKey(k - x))		 
			ans = Math.min(Math.max(b.get(x), 
									b.get(k - x)), ans);	 
	} 
	return ans; 
} 

// Driver Code 
public static void main(String[] args) 
{ 
	int a[] = { 3, 5, 8, 6, 7 }; 
	int K = 11; 
	int n = a.length; 
	System.out.println(findMaximum(a, n, K)); 
} 
} 
