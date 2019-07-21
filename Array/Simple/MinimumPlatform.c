#include<stdio.h>
void merge(int arr[],int d[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2],L1[n1],R1[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i]; 
        L1[i]=d[l+i];
        
    }
    for (j = 0; j < n2; j++){ 
        R[j] = arr[m + 1+ j];
        R1[j]=d[m+1+j];   
    }
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        {   
            d[k]=L1[i];
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            d[k]=R1[j];
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        d[k]=L1[i];
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        d[k]=R1[j];
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[],int d[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr,d, l, m); 
        mergeSort(arr,d, m+1, r); 
  
        merge(arr,d, l, m, r); 
    } 
} 
int main()
{
	//code
	int t;
	scanf("%d",&t);
	while(t>0){
	    int a[10000],d[10000],pla[10000],pld[10000],top=0,i,j,l,n,c=0;
	    scanf("%d",&n);
	    for(i=0;i<n;i++){
	        scanf("%d",&a[i]);
	    }
	    for(i=0;i<n;i++){
	        scanf("%d",&d[i]);
	    }
	    mergeSort(a,d,0,n-1);
	    pla[0]=a[0];
	    pld[0]=d[0];
	    top=1;
	    /*Keep pla[] and pld array for tracking platforms
	    if arrival of new train is less than departure of all the trains 
	    in the plaform thn incre platform and add this train to new platform
	    by increasing */
	    for(i=1;i<n;i++){
	        c=0;
	        for(j=0;j<top;j++){
	            if(pld[j]<a[i]){
	                pla[j]=a[i];
	                pld[j]=d[i];
	                c=1;
	                break;
	            }
	        }
	        if(c==0){
	            pla[top]=a[i];
	            pld[top]=d[i];
	            top++;
	        }
	    }
	    printf("%d\n",top);
	    t--;
	}
	return 0;
}