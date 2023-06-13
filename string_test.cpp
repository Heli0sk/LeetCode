#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    
    int temperature = 1798;
    int speed = ((float)temperature / 1850) * 60;
    int gpt =  (1850 - temperature) * 2 / 5;
    
    cout<<speed<<endl;
	cout<<gpt<<endl;
	return 0;
}

