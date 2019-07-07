{
#include<bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        
        cin >> n;
        
        int a[n];
        
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        
        cout << trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
}
/*This is a function problem.You only need to complete the function given below*/
   
// function to find the trapped water in between buildings
// arr: input array
// n: size of array
int trappingWater(int a[], int n){
    // Your code here
    int i,j,k=0,cntleft[10000],cntryt[10000];
    cntleft[0]=a[0];
	// use array to track max from ryt
	// another array to track max from left
    for(i=1;i<n;i++){
        if(a[i]>=cntleft[i-1]){
            cntleft[i]=a[i];
        }
        else{
            cntleft[i]=cntleft[i-1];
        }
    }
    cntryt[n-1]=a[n-1];
    for(i=n-1;i>=0;i--){
        if(a[i]>=cntryt[i+1]){
            cntryt[i]=a[i];
        }
        else{
            cntryt[i]=cntryt[i+1];
        }
    }
	// min from left and ryt decides the amt of water
    k=0;
    for(i=1;i<n-1;i++){
        if(cntleft[i]>=cntryt[i]){
            if(a[i]<=cntryt[i]){
                k=k+(cntryt[i]-a[i]);
            }
        }
        else{
            if(a[i]<=cntleft[i]){
                k=k+(cntleft[i]-a[i]);
            }
        }
       
    }
    
    return k;
}