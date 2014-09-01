#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
using namespace std;

void QuickSort(int* a,int left,int right){
	if(left>=right){
		return;
	}
	int temp = a[left];
	int i,j;
	i=left;
	j=right;
	while(i<j){
		while(a[j]>=temp&j>i)
			j--;
		a[i]=a[j];
		while(a[i]<=temp&j>i)
			i++;
		a[j]=a[i];
		a[i]=temp;
		QuickSort(a,left,i-1);
		QuickSort(a,i+1,right);
	}
}

int* f2(int* a,int len){
	
	int num = len/31+1;
	int *arr = new int[num];
	int *res = new int[len];
	for (int i = 0 ;i<num;i++){
		arr[i] = 0;
	}
	for (int i = 0 ;i<len;i++){
		int ind = a[i]/31;
		arr[ind]=1<<(a[i]%31)|arr[ind];
		char binary[255];
		_itoa(arr[ind],  binary, 2);
		//cout<<binary<<endl;
	}
	for (int i = 0;i<num;i++){
		int base= 0 + 31*i;
		int val = arr[i];
		for (int j =0;j<31;j++){
			if ((val>>j&1)==1)
				res[i]=base+j;
		}
	}
	return res;

}

double diffclock( clock_t clock1, clock_t clock2 ) {

        double diffticks = clock1 - clock2;
        double diffms    = diffticks / ( CLOCKS_PER_SEC / 1000 );

        return diffms;
    }

int main (void){
	const int len = 8000;
	int a[len];
	for (int i = 0 ; i<len;i++)
		a[i]=i;

	clock_t t1 =clock();
	QuickSort(a,0,len-1);
	clock_t t2 =clock();
	cout<<diffclock(t2,t1)<<endl;

	t1 = clock();
	int* res2 = f2(a,len);
	t2 = clock();
	cout<<diffclock(t2,t1)<<endl;


    return 0;
}