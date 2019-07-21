#include<stdio.h>
#include<string.h>
int main()
{
	//code
	int t;
	scanf("%d",&t);
	while(t>0){
	    int i,j,k,n;
	    char a[1000][1000],b[10000],c[10000];
	    scanf("%s",b);
	    i=0,j=0;
	    int l=0;
	    n=strlen(b);
	    /* Store each word separately in 2d array, thn starting from the last
	    word add evry word to a string and after adding each word add .
	    to the new string, continue this till all the words are added*/
	    while(i<n){
	        j=i;
	        k=0;
	        while(j<n&&b[j]!='.'){
	            c[k]=b[j];
	            j++;
	            i++;
	            k++;
	            
	        }
	        c[k]='\0';
	        strcpy(a[l],c);
	        l++;
	        if(b[i]=='.'){
	            i++;
	        }
	    }
	    char d[1000];
	    i=l-1;
	    j=0;
	    int u=0,h;
	    while(i>=0){
	        strcpy(d,a[i]);
	        k=strlen(d);
	        h=0;
	        while(h<k){
	            c[u]=d[h];
	            h++;
	            u++;
	        }
	        if(i>0){
	            c[u]='.';
	            u++;
	        }
	        i--;
	    }
	    c[u]='\0';
	    printf("%s\n",c);
	    t--;
	}
	return 0;
}