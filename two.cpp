#include<bits/stdc++.h>
using namespace std;
#define int long long int

  int merge(int arr[],int temp[],int left,int mid,int right) 
{ 
	  int i, j, k; 
	  int inv_count = 0; 

	i = left; 
	j = mid; 
	k = left; 
	while ((i <= mid - 1) && (j <= right)) 
    { 
		if (arr[i] <= arr[j]) 
        { 
			temp[k++] = arr[i++]; 
		} 
		else 
        { 
			temp[k++] = arr[j++]; 					
			inv_count = inv_count + (mid - i); 	//left array= i to mid
                                 				//right array= mid+1 to right
		} 
	} 

	while (i <= mid - 1) 
		temp[k++] = arr[i++]; 

	while (j <= right) 
		temp[k++] = arr[j++]; 

	for (i = left; i <= right; i++) 
		arr[i] = temp[i]; 

	return inv_count; 
} 


  int MergeSort(int arr[],int temp[],int left,int right) 
{ 
  int mid, inv_count = 0; 
	if (right > left)
	{ 

		mid = (right + left) / 2; 
		inv_count += MergeSort(arr, temp, left, mid); 
		inv_count += MergeSort(arr, temp, mid + 1, right); 
		inv_count += merge(arr, temp, left, mid + 1, right); 
	} 
	return inv_count; 
} 


  int _mergesort(int arr[],int array_size) 
{ 
	  int temp[array_size]; 
	return MergeSort(arr, temp, 0, array_size - 1); 
} 


int32_t main()
 {
        int p;
	cin>>p;
	while(p--)
	{
	      int n;
	    cin>>n;
	      int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    
	        
	    int count = _mergesort(arr, n); 
	    
	    cout<<count<<endl;
	}
}	
