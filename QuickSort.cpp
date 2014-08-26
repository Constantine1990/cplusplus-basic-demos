#include "stdafx.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
using namespace std;  


void QuickSort(int a[],int left,int right){
	int i = left;
	int j = right;
	int temp  = a[left];
	if (left>=right)
		return;
	while(i!=j){
		while(j>i&&a[j]>=temp)
			j--;
		a[i]=a[j];
		while(j>i&&a[i]<=temp)
			i++;
		a[j]=a[i];
		a[i]=temp;
	}
	
	for (int i = 0 ;i<6;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	QuickSort(a,left,i-1);
	QuickSort(a,i+1,right);
}

int main()
{	
	int	a[]={2,3,4,5,6,1};
	QuickSort(a,0,5);
	for (int i = 0 ;i<6;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0 ;
}
