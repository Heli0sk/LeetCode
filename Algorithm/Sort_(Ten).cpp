#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


void BubbleSort(vector<int> &array)
{
	int length = array.size();
	for(int i=0;i<length;i++){
		for(int j=0;j<length-i-1;j++)
			// 递增 increase
			if(array[j] > array[j+1])
				swap(array[j], array[j+1]);
			// 递减 decrease
//			if(array[j] < array[j+1])
//				swap(array[j], array[j+1]);
	}
}


void BubbleSort_OPT(vector<int> &array)
{
	int length = array.size();
	int flag = 1;
	for(int i=0;i<length;i++){
		flag = 1;
		for(int j=0;j<length-i-1;j++){
			if(array[j] > array[j+1]){
				flag = 0;
				swap(array[j], array[j+1]);
			}
		}
		if(flag) break;
	}
}


void InsertionSort(vector<int> &array)
{
	int length = array.size();
	for(int i=1;i<length;i++){
		int key = array[i];
		int j = i-1;  		// [0,j] 已排序区间
		while((j>=0)&&(array[j]>key)){
			array[j+1] = array[j];
			j--;
		}	
		array[j+1] = key;
	}
	
}


void SelectionSort(vector<int> &array)
{
	int length = array.size();
	for(int i=0;i<length-1;i++){
		int minIndex = i;
		for(int j=i+1;j<length;j++)
			if(array[j]<array[minIndex]) minIndex = j;
		
		swap(array[i], array[minIndex]);
	}
}


void Merge(vector<int> &array, int left, int mid, int right)
{
	vector<int> tmp(right-left+1);
	int i=left, j=mid+1, k=0;
	while(i<=mid && j<=right){
		if(array[i] < array[j])
			tmp[k++] = array[i++];
		else tmp[k++] = array[j++];
	}
	while(i<=mid)
		tmp[k++] = array[i++];
	while(j<=right)
		tmp[k++] = array[j++];
	for (int m = 0; m < right-left+1; m++)
		array[left + m] = tmp[m];
}

void MergeSort(vector<int> &array, int left, int right)
{
	if(left >= right) return;
//	int mid = (left + right) / 2;
	int mid = left + (right - left) / 2; // 可以避免溢出
	MergeSort(array, left, mid);
	MergeSort(array, mid+1, right);
	Merge(array, left, mid, right);
}

void MergeSort_it(vector<int>& array, int len) {
	vector<int> ans(len);  // 存储归并排序结果
	for (int seg = 1; seg < len; seg += seg) {  		  // seg为当前归并的子数组长度
		for (int beg = 0; beg < len; beg += seg + seg) {  // beg为当前子数组的起始位置
			int low = beg;  // 子数组的低位索引
			int mid = min(beg + seg, len);  // 子数组的中间位置索引（最大为len）
			int high = min(beg + seg + seg, len);  // 子数组的高位索引（最大为len）
			
			int i = low;  // 左侧子数组的起始索引
			int j = mid;  // 右侧子数组的起始索引
			int k = low;  // 临时数组ans的索引
			
			// 在左右子数组中进行归并排序
			while (i < mid && j < high) {
				// 选择左右子数组中较小的元素放入临时数组ans中
				ans[k++] = array[i] > array[j] ? array[j++] : array[i++];
			}
			
			// 将剩余的元素放入临时数组ans中
			while (i < mid) {
				ans[k++] = array[i++];
			}
			while (j < high) {
				ans[k++] = array[j++];
			}
			// 将临时数组ans中的排序结果拷贝回原始数组arr中
			for (k = beg; k < high; ++k) {
				array[k] = ans[k];
			}
		}
	}
}


int partition(vector<int> &array, int left, int right)
{
	int pivot = right;
	int location = left;
	for(int i=left;i<right;i++){
		if(array[i] < array[pivot]){
			swap(array[i], array[location]);
			location++;
		}
	}
	swap(array[pivot], array[location]);
	return location;
}

void QuickSort(vector<int> &array, int left, int right)
{
	if(left >= right) return;
	int pivot = partition(array, left, right);
	QuickSort(array, left, pivot-1);
	QuickSort(array, pivot+1, right);
}


void CountSort(vector<int> &array)
{
	int max = -1;
	for(auto x:array)
		if(x > max) max = x;
	vector<int> counter(max+1,0);
	for(int i=0;i<array.size();i++)
		counter[array[i]]++;
	int index = 0;
	for(int k=0; k<counter.size();k++){
		for(int cnt=0; cnt<counter[k];cnt++)
			array[index++] = k;
	}
}


// num: 桶的个数
void BucketSort(vector<int> &array, int num)
{
	queue<int> buckets[10];  // 10个桶
	
	for(int digit=1; digit<=1e9; digit*=10){
		
	}
	
}

void PrintArray(vector<int> array)
{
	int length = array.size();
	for(int i=0;i<length;i++)
		cout<<array[i]<<" ";
	cout<<endl;
}

int main()
{
	vector<int> test={3,5,1,0,45,2,8,9,4,10,3,10000};
//	BubbleSort_OPT(test); PrintArray(test); random_shuffle(test.begin() , test.end());
	BubbleSort(test);	  PrintArray(test); random_shuffle(test.begin() , test.end());
//	InsertionSort(test);  PrintArray(test); random_shuffle(test.begin() , test.end());
	SelectionSort(test);  PrintArray(test); random_shuffle(test.begin() , test.end());
	
	MergeSort(test, 0, test.size());
	PrintArray(test); random_shuffle(test.begin() , test.end());
	MergeSort_it(test, test.size()); PrintArray(test);random_shuffle(test.begin() , test.end());
	QuickSort(test, 0, test.size()); PrintArray(test);random_shuffle(test.begin() , test.end());
	CountSort(test);  	 PrintArray(test); random_shuffle(test.begin() , test.end());
	return 0;
}
