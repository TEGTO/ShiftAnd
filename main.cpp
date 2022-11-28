#include <iostream>
#include <vector>
#include <windows.h>  
using namespace std;
void ArrayPrint(int *U , int *ShiftAnd_,int * M, int size,int count,string s3)
{
	cout << "U{T(" << count+1 << ")}" << " = "<< "U(" << s3[count + 1] << ")" << " = ";
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
void MatrixPrint(int** mainMatrix, int size1, int size2,string s1,string s3)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << endl << endl;
	cout << "Matrix: \n";
	cout << "      ";
	SetConsoleTextAttribute(hConsole, 11);
	for (int i = 1; i < s3.size(); i++)
	{
		cout << s3[i]<<" ";
	}
	cout << endl;
	cout << "    ";
	SetConsoleTextAttribute(hConsole, 12);
	for (int i = 0; i < s3.size(); i++)
	{
		cout << i << " ";
	}
	cout << endl;
	for (int i = 0; i < size1; i++)
	{
		SetConsoleTextAttribute(hConsole, 11);
		cout << s1[i] << " ";
		SetConsoleTextAttribute(hConsole, 12);
			cout<< i+1 << " ";
		
		for (int j = 0; j < size2; j++)
		{
			if (mainMatrix[i][j]==1)
				SetConsoleTextAttribute(hConsole, 14);
			else
				SetConsoleTextAttribute(hConsole, 7);
			cout << mainMatrix[i][j]<<" ";
		}
		cout << endl;
	}
	cout << endl << endl;
	SetConsoleTextAttribute(hConsole, 7);
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
				
					for (int t = 0; t <= i; t++)
					{ 
						if ((j - i + t) >= 0)
						{
							if (s1[t] != s3[j - i + t])
							{
								check = 0;
							}
						}
						else
							check = 0;
						
					}
				
				if (check)
				{
					if (s1[i] == s3[j])
					{
					mainMatrix[i][j] = 1;
					}
				}
			}
		}

	
	check = 0;
	MatrixPrint(mainMatrix, s1.size(), s3.size(),s1,s3);
	cout << endl << "M(0)" << " = ";
	for (int i = 0; i < s1.size(); i++)
	{
		cout << 0;
	}
	cout << endl << endl;
	for (int i = 1; i < s3.size(); i++)
	{
		for (int j = 0; j < s1.size(); j++)
		{
			if (s1[j] == s3[i])
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
		ArrayPrint(U, ShiftAnd_, M,s1.size(), i-1,s3);
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
	cout << "made by TE (aka Evgenii)\nShiftAnd\n\n";

	cout << "Ведiть зразок\n";
	cin >> s1;
	cout << "Ведiть текст\n";
	cin >> s2;
	cout << endl << endl;
	ShiftAnd(s1, s2);
	system("pause");

}