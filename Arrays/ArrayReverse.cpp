//Write a program to reverse an array or string
//Given an array (or string), the task is to reverse the array/string.
//Examples : 
//Input  : arr[] = {1, 2, 3}
//Output : arr[] = {3, 2, 1}
//
//Input :  arr[] = {4, 5, 1, 2}
//Output : arr[] = {2, 1, 5, 4}

#include<iostream>

using namespace std;

int main()
{
	int arr[50],n;
	int i;
	cout<<"ENTER SIZE OF THE ARRAY : ";
	cin>>n;
	for(i=0;i<n;i++)
		cin>>arr[i];
	cout<<"REVERSED ARRAY : ";
	for(i=n-1; i>=0 ; i--)
	{
		cout<<arr[i]<<"   ";
	}
	return 0;
}
