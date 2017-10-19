#include <iostream>
#include <cmath>
using namespace std;


void output(int tree[], int i)
{
	if (i >= 128)
	{
		return;
	}
	
	cout << tree[i] << "\t";
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
// not good practice
int main(int argc, char const *argv[])
{
	
	int tree[128] = {0};
	int temp[100], t;
	for (int i = 0; i < 100; ++i)
	{
		temp[i] = i+1;
	}
	tree[0]=50;
	for (int j = 2; j <= 64; j=j*2) //control levels
	{
		t = ceil(100/j)-1;
		for (int k = 1; k < j; k=k+2) // control intervals
		{
			int tt = t*k + k - 1;
			for (int i = 0; i < 100; ) // control children
			{
				if (tree[i] > temp[tt])
				{
					if ( tree[2*i+1] == 0 )
					{
						tree[2*i+1] = temp[tt];
						break;
					}else{
						i = 2*i+1;
					}
				}else if (tree[i] < temp[tt])
				{

					if ( tree[2*i+2] == 0 )
					{
						tree[2*i+2] = temp[tt];
						break;
					}else{
						i = 2*i+2;
					}
				}else{
					// tt = tt-1;
					break;
				}
			}
		}
	}
	for (int j = 0; j < 100; ++j)
	{
		for (int i = 0; i < 128; )
		{
			if (tree[i] > j+1)
			{
				if ( tree[2*i+1] == 0 )
				{
					tree[2*i+1] = j+1;
					break;
				}else{
					i = 2*i+1;
				}			
			}else if (tree[i] < j+1)
			{

				if ( tree[2*i+2] == 0 )
				{
					tree[2*i+2] = j+1;
					break;
				}else{
					i = 2*i+2;
				}
			}else{
				break;	
			}
		}
	}
	// for (int i = 0; i < 128; ++i)
	// {
	// 	cout << tree[i] << " ";
	// }
	// cout << endl;
	output(tree,0);
	cout << endl;
	cout << endl;
	draw(tree);
	

	return 0;
}