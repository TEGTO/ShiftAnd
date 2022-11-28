#include <iostream>
#include <vector>
using namespace std;
void ArrayPrint(int *U , int *ShiftAnd_,int * M, int size,int count)
{
	cout << "U{T(" << count+1 << ")}" << " = ";
	for (int i = 0; i < size; i++)
	{
		cout << U[i];
	}
	cout <<endl<< "ShiftAnd(" << count << ")" << " = ";
	for (int i = 0; i < size; i++)
	{
		cout << ShiftAnd_[i];
	}
	cout <<endl<< "M(" << count+1 << ")" << " = ";
	for (int i = 0; i < size; i++)
	{
		cout << M[i];
	}
	cout << endl<<endl;
}
void MatrixPrint(int** mainMatrix, int size1, int size2)
{
	cout << endl << endl;
	cout << "Matrix: \n";
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2+1; j++)
		{
			cout << mainMatrix[i][j]<<" ";
		}
		cout << endl;
	}
	cout << endl << endl;
}
void ShiftAnd(string s1, string s2)
{
	int** mainMatrix = new int* [s1.size()];
	for (int count = 0; count < s1.size(); count++)
		mainMatrix[count] = new int[s2.size()+1]{};
	int* U = new int[s1.size()]{};
	int* ShiftAnd_ = new int[s1.size()]{};
	ShiftAnd_[0] = 1;
	int* M = new int[s1.size()]{};
	int check = 0;
	string s3;
	s3.append("0");
	for (size_t i = 0; i < s2.size(); i++)
	{
		s3.push_back(s2[i]);
	}
		for (int i = 0; i < s1.size(); i++)
		{
			for (int j = 0; j < s3.size(); j++)
			{
				check = 1;
				if (s1[i] == s3[j])
				{
					for (int t = 0; t <= i; t++)
					{ 
						if (s1[t] != s3[j-i+t])
						{
							check = 0;
						}
					}
				}
				if (check)
				{
					mainMatrix[i][j] = 1;
				}
			}
		}

	
	check = 0;
	MatrixPrint(mainMatrix, s1.size(), s3.size());
	for (int i = 0; i < s2.size(); i++)
	{
		for (int j = 0; j < s1.size(); j++)
		{
			if (s1[j] == s2[i])
			{
				U[j] = 1;
			}
		}
		if (check==1)
		{
			ShiftAnd_[0] = 1;
			for (int j = 0; j < s1.size()-1; j++)
			{
				ShiftAnd_[j+1] = mainMatrix[j][i-1];
			}
		}
		else
		{
			
			check = 1;
		}
	
		for (int t = 0; t < s1.size(); t++)
		{
			M[t] = ShiftAnd_[t] & U[t];
		}
		ArrayPrint(U, ShiftAnd_, M,s1.size(), i);
		for (int t = 0; t < s1.size(); t++)
		{
			M[t] = 0;
			ShiftAnd_[t] = 0;
			U[t] = 0;
		}
		
	}
}
int main()
{
	setlocale(LC_ALL, "RUS");
	string s1;
	string s2;
	cout << "Ведiть зразок\n";
	cin >> s1;
	cout << "Ведiть текст\n";
	cin >> s2;
	cout << endl << endl;
	ShiftAnd(s1, s2);
	system("pause");

}