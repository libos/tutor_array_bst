#include <iostream>

using namespace std;


void output(int tree[], int i)
{
	if (i >= 100)
	{
		return;
	}

	cout << tree[i] << "\t";
	output(tree,i*2+1);
	output(tree,i*2+2);
}

// bad practice
int main(int argc, char const *argv[])
{
	
	int tree[100] = {0};

	tree[0] = 50;
	
	for (int j = 0; j < 100; ++j)
	{
		for (int i = 0; i < 100; )
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
	// for (int i = 0; i < 100; ++i)
	// {
	// 	cout << tree[i] << " ";
	// }
	output(tree,0);

	return 0;
}