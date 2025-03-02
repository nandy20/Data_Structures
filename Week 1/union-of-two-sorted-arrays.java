// Problem link - https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        vector<int> res;
        int i=0, j=0;
        while(i<a.size()&& j<b.size()){
            if(a[i]<b[j]){
                if(res.size()==0 || res[res.size()-1]!=a[i]){
                    res.push_back(a[i]);
                }
                i++;
            } else if(a[i]>b[j]){
                if(res.size()==0 || res[res.size()-1]!=b[j]){
                    res.push_back(b[j]);
                }
                j++;
            } else {
                 if(res.size()==0 || res[res.size()-1]!=b[j]){
                    res.push_back(b[j]);
                 }
                j++;
                i++;
            }
        }
        cout<< 
        while(j<b.size()){
             if(res.size()==0 || res[res.size()-1]!=b[j]){
                    res.push_back(b[j]);
                }
                j++;
        }
        return res;
    }
