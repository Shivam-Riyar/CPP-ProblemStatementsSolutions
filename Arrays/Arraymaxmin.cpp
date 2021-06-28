//Program to find the minimum (or maximum) element of an array

#include<iostream>

using namespace std;

void findmax(int ar[],int size);
void findmin(int ar[],int size);

int main()
{
	int arr[50],n;
	int i;
	cout<<"ENTER SIZE OF ARRAY : ";
	cin>>n;
	for(i = 0 ; i < n ; i++)
		cin>>arr[i];
	findmax(arr,n);
	findmin(arr,n);
	return 0;
}

void findmax(int ar[], int size)
{
	int max = ar[0];
	for(int i = 0; i < size ; i++)
	{
		if(ar[i] >= max)
		{
			max = ar[i];
		}
	}
	cout<<"MAXIMUM OF ARRAY : "<<max<<endl;
}

void findmin(int ar[], int size)
{
	int min = ar[0];
	for(int i = 0; i < size ; i++)
	{
		if(ar[i] <= min)
		{
			min = ar[i];
		}
	}
	cout<<"MINIMUM OF ARRAY : "<<min<<endl;
}
