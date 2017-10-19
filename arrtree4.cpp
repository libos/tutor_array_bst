#include <iostream>
#include <cmath>
using namespace std;


void output(int tree[], int i)
{
	if (i >= 100)
	{
		return;
	}
	
	cout << tree[i] << endl;
	output(tree,i*2+1);
	output(tree,i*2+2);
}
void draw(int tree[])
{
	int sum = 0;
	for (int i = 0; i < 8; ++i)
	{
		int pw = pow(2,i);
		if (sum+pw > 128)
		{
			continue;
		}
		for (int j = sum; j < sum+pw; ++j)
		{
			cout << tree[j] << "\t";	
		}
		cout << endl;
		sum += pw;
	}
}

void construct(int temp[],int *tree,int i,int start, int end)
{
	if (start > end)
	{
		return;
	}
	int mid = (start + end)/2;

	tree[i] = temp[mid];
	construct(temp,tree,i*2+1,start,mid-1);
	construct(temp,tree,i*2+2,mid+1,end);

}
int main(int argc, char const *argv[])
{
	
	int tree[128] = {0};
	int temp[100];
	for (int i = 0; i < 100; ++i)
	{
		temp[i] = i+1;
	}

	construct(temp,tree,0,0,99);

	for (int i = 0; i < 100; ++i)
	{
		cout << tree[i] << " ";
	}
	cout << endl;
	output(tree,0);
	cout << endl;
	draw(tree);

	return 0;
}