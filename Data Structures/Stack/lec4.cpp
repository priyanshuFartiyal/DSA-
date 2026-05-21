// Next Greater Element 

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int main(){
    vector<int> vec = {6,8,0,1,3};

    vector<int> ans;
    stack<int> s;

    for(int i = vec.size()-1; i >= 0; i--){
        while(!s.empty() && s.top() < vec[i]){
            s.pop();
        }

        if(s.empty()){
            ans.push_back(-1);
        } else {
            ans.push_back(s.top());
        }

        s.push(vec[i]);
    }

    reverse(ans.begin(), ans.end());

    for(int val : ans){
        cout << val << " ";
    }

    return 0;
}

