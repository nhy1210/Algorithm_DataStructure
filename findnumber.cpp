#include<iostream>
#include<map>
using namespace std;

int findclosestno(int *A, int size, int target)
{
	int min = INT_MAX;
	min = abs(target-A[0]);
	for(int i =1;i < size; i++)
	{
		if(abs(target - A[i])<min) min = abs(target - A[i]);
	}
	return abs(target -min);

}
int main()
{

	int arrA[] = {1,2,3,5,7,9};
	int size = sizeof(arrA)/sizeof(arrA[0]);
	int m= findclosestno(arrA,size, 4);
	cout<<m<<endl;
	return 0;
}
