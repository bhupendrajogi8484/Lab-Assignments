#include <iostream>
using namespace std;
int main()
{
	int op;
	int size;
	cout << "Enter size of your sets: ";
	cin >> size;
	int a[size];
	int b[size];
	int c[size * 2];
	cout << "\nEnter first set: \n";
	for (int i = 0; i < size; i++)
	{
		cout << "Enter element number " << i + 1 << ":" << endl;
		cin >> a[i];
	}
	cout << "\n\nEnter second set: \n";
	for (int i = 0; i < size; i++)
	{
		cout << "Enter element number " << i + 1 << ":" << endl;
		cin >> b[i];
	}
	cout << "\nFirst set is: ";
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	cout << "\nSecond set is: ";
	for (int i = 0; i < size; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;

	cout << "----------------------------------------------------" << endl;
	int uni(int a[], int b[], int c[], int size);
	int inter(int a[], int b[], int c[], int size);
	int diff(int a[], int b[], int c[], int size);
	int syme(int a[], int b[], int c[], int size);
	int display(int a[], int size);

	do
	{
		cout << "\n 1.For Union of sets";
		cout << "\n 2.For Intersection of sets";
		cout << "\n 3.For Difference of sets";
		cout << "\n 4.For symmatic differnce of sets";
		cout << "\n 5.Exit";
		cout << "\n Enter your option: ";
		cin >> op;
		cout << "----------------------------------------------------" << endl;
		switch (op)
		{
		case 1:
			uni(a, b, c, size);
			cout << "----------------------------------------------------" << endl;
			break;
		case 2:
			inter(a, b, c, size);
			cout << "----------------------------------------------------" << endl;
			break;
		case 3:
			diff(a, b, c, size);
			cout << "----------------------------------------------------" << endl;
			break;
		case 4:
			syme(a, b, c, size);
			cout << "----------------------------------------------------" << endl;
			break;
		case 5:
			cout << "Exiting the program...." << endl;
			cout << "----------------------------------------------------" << endl;
			break;
		default:
			cout << "\n\nPlease Enter Valid Choice";
		}
	} while (op != 5);
}



int display(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}

	return 0;
}

int uni(int a[], int b[], int c[], int size)
{

	cout << "Union of Your Sets is:  ";
	for (int i = 0; i < size; i++)
	{
		c[i] = a[i];
	}
	int cSize = size;
	for (int i = 0; i < size; i++)
	{
		bool unique = true;
		for (int j = 0; j < size; j++)
		{
			if (b[i] == a[j])
			{
				unique = false;
				break;
			}
		}

		if (unique)
		{
			c[cSize] = b[i];
			cSize++;
		}
	}
	display(c, cSize);
	cout << endl;

	return 0;
}



int inter(int a[], int b[], int c[], int size)
{
	int cSize = 0;
	cout << "Intersection of Your Sets is:  ";
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (a[i] == b[j])
			{
				c[cSize] = a[i];
				cSize++;
				break;
			}
		}
	}
	display(c, cSize);
	cout << endl;

	return 0;
}


int diff(int a[], int b[], int c[], int size)
{
	cout << "Difference of Your Sets [A-B] is:  ";

	int cSize = 0;
	for (int i = 0; i < size; i++)
	{
		int unique = 1;
		for (int j = 0; j < size; j++)
		{
			if (a[i] == b[j])
			{
				unique = 0;
				break;
			}
		}

		if (unique == 1)
		{
			c[cSize] = a[i];
			cSize++;
		}
	}
	display(c, cSize);

	cout << "\nDifference of Your Sets [B-A] is:  ";
	cSize = 0;
	for (int i = 0; i < size; i++)
	{
		int unique = 1;
		for (int j = 0; j < size; j++)
		{
			if (b[i] == a[j])
			{
				unique = 0;
				break;
			}
		}

		if (unique == 1)
		{
			c[cSize] = b[i];
			cSize++;
		}
	}
	display(c, cSize);

	cout << endl;
	return 0;
}

int syme(int a[], int b[], int c[], int size)
{

	cout << "Symmatic Difference of Your Sets is:  ";
	int cSize = 0;
	//------
	for (int i = 0; i < size; i++)
	{
		bool unique = true;
		for (int j = 0; j < size; j++)
		{
			if (a[i] == b[j])
			{
				unique = false;
				break;
			}
		}

		if (unique)
		{
			c[cSize] = a[i];
			cSize++;
		}
	}
	for (int i = 0; i < size; i++)
	{
		bool unique = true;
		for (int j = 0; j < size; j++)
		{
			if (b[i] == a[j])
			{
				unique = false;
				break;
			}
		}

		if (unique)
		{
			c[cSize] = b[i];
			cSize++;
		}
	}
	display(c, cSize);
	cout << endl;
	return 0;
}
