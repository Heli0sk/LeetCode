#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void displayArr(int a[], int n){
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}


int jump(vector<int>& nums) {
    int n = nums.size();
    int *step = new int[n]();
//    int minstep = 1e4, j;
    for(int i=n-2;i>=0;i--){
        if(nums[i] + i >= n-1)
            step[i] = 1;
        else{
            int minstep = 1e4;
            for(int j = 1;j<=nums[i];j++){
                minstep = min(minstep, step[i+j]);
            }
            step[i] = 1 + minstep;
        }
    }
    return step[0];
}

int main()
{
    int arr[] = {2,3,0,1,4};
	vector<int> inputArr(arr, arr+sizeof(arr)/sizeof(int));
    cout<<jump(inputArr)<<endl;
    return 0;
}
