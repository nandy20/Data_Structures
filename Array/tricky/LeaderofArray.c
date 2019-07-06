#include<stdio.h>
int main()
{
	//code
	int t;
	scanf("%d",&t);
	while(t>0){
	    long long int n,a[100000],i,j,c=0,stack[100000],top;
	    scanf("%lld",&n);
	    for(i=0;i<n;i++){
	        scanf("%lld",&a[i]);
	    }
	    top=n-1;
	    stack[top]=a[n-1];
	    /* use a stack to keep track of maximum from right
	    thn if same numbers are present use -ve and +ve sign
	    to detect diff nums*/
	    top--;
	   for(i=n-2;i>=0;i--){
	       if(abs(stack[top+1])>=a[i]){
	           if(abs(stack[top+1])==a[i]){
	               if(stack[top+1]>0){
	                   stack[top]=-(stack[top+1]);
	                   top--;
	               }
	               else{
	                   stack[top]=-(stack[top+1]);
	                   top--;
	               }
	           }
	           else{
	               stack[top]=stack[top+1];
	               top--;
	           }
	       }
	       else{
	           stack[top]=a[i];
	           top--;
	       }
	   }
	   
	    for(i=0;i<n-1;i++){
	      if(stack[i]!=stack[i+1]){
	          printf("%lld ",abs(stack[i]));
	      }
	    }
	    printf("%lld\n",abs(stack[n-1]));
	    t--;
	}
	return 0;
}