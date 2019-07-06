#include<stdio.h>
void merge(long long int arr[],long long int l,long long int m,long long int r) 
{ 
    long long int i, j, k; 
    long long int n1 = m - l + 1; 
    long long int n2 =  r - m; 
  
    /* create temp arrays */
    long long int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(long long int arr[],long long int l,long long int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
}
int main()
{
	//code
	int t;
	scanf("%d",&t);
	while(t>0){
	    long long int n,i=0,a[100000],j,l,c,q=0;
	    scanf("%lld",&n);
	    for(i=0;i<n;i++){
	        scanf("%lld",&a[i]);
	    }
	   l=(n/2)+1;
	   //Sort the array 
	   mergeSort(a,0,n-1);
	    i=0;
		//If similar elements found inc c else come out of inner loop
		//O(n) complexity is only used for this
	    while(i<n-1){
	        c=1;
	        while(a[i]==a[i+1]&&i<n-1){
	            i++;
	            c++;
	        }
	        if(c>=l){
	            printf("%lld\n",a[i]);
	            q=1;
	            break;
	        }
	        i++;
	    }
	    if(q==0){
	        printf("-1\n");
	    }
	    t--;
	}
	return 0;
}