#include <iostream>
using namespace std;

int main()
{

	int a[4][4], b[4][4], c[4][4], choice;
	void add(int a[4][4], int b[4][4], int c[4][4]);
	void multiplication(int a[4][4], int b[4][4], int c[4][4]);
	void transpose(int a[4][4], int b[4][4]);

	cout << "Enter matrix A: \n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> a[i][j];
		}
	}

	cout << "\nEnter matrix B: \n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> b[i][j];
		}
	}

	cout << "\nThe elements of Matrix A : " << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << " " << a[i][j] << " ";
		}
		cout << endl;
	}

	cout << "\nThe elements of Matrix B : " << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << " " << b[i][j] << " ";
		}
		cout << endl;
	}
	do
	{
		cout << "\n 1.For Addition";
		cout << "\n 2.For Multiplication";
		cout << "\n 3.For Transpose";
		cout << "\n 4.Exit";
		cout << "\n Enter your option: ";
		cin >> choice;
		cout << "----------------------------------------------------" << endl;
		switch (choice)
		{
		case 1:
			add(a, b, c);
			cout << "----------------------------------------------------" << endl;
			break;
		case 2:
			multiplication(a, b, c);
			cout << "----------------------------------------------------" << endl;
			break;
		case 3:
			transpose(a, b);
			cout << "----------------------------------------------------" << endl;
			break;
		case 4:
			cout << "Exiting the program...." << endl;
			cout << "----------------------------------------------------" << endl;
			break;
		default:
			cout << "\n\nPlease Enter Valid Choice\n\n";
			cout << "----------------------------------------------------" << endl;
		}
	} while (choice != 4);

	return 0;
}

void add(int a[4][4], int b[4][4], int c[4][4])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	}

	cout << "\nThe Addition of Matrices (A+B) : " << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << " " << c[i][j] << " ";
		}
		cout << endl;
	}
}

void multiplication(int a[4][4], int b[4][4], int c[4][4])
{
	int temp, i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			c[i][j] = 0;
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (temp = 0; temp < 3; temp++)
			{

				c[i][j] = c[i][j] + (a[i][temp] * b[temp][j]);
			}
		}
	}
}

void transpose(int a[4][4], int b[4][4])
{

	cout << "\nThe Transpose of Matrix A (A^T)is: " << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << " " << a[j][i] << " ";
		}
		cout << endl;
	}
	cout << "\nThe Transpose of Matrix B (B^T) is: " << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << " " << b[j][i] << " ";
		}
		cout << endl;
	}
}
