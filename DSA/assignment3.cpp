#include <iostream>
using namespace std;

struct Student
{
	string name;
	long long mobilenum;
	int billamt;
};

int main()
{
	Student a[100];
	int len, choice;
	void bubblesort(Student a[], int len);
	void selectionsort(Student a[], int len);
	void binarysearch(Student a[], int len);
	void displaydatabase(Student a[], int len);
	void create(Student a[], int len);

	do
	{
		cout << "\n 1.Create database";
		cout << "\n 2.Display database";
		cout << "\n 3.Display database in ascending order (bubble sort)";
		cout << "\n 4.Display database in descending order (selection sort)";
		cout << "\n 5.Display details of username, specied by user (binary search)";
		cout << "\n 6.Exit";
		cout << "\n\n Enter your option: ";
		cin >> choice;
		cout << "----------------------------------------------------" << endl;
		switch (choice)
		{
		case 1:
			cout << "\n >>Enter size of your database: ";
			cin >> len;
			create(a, len);
			cout << "----------------------------------------------------" << endl;
			break;
		case 2:
			displaydatabase(a, len);
			cout << "----------------------------------------------------" << endl;
			break;
		case 3:
			bubblesort(a, len);
			cout << "----------------------------------------------------" << endl;
			break;
		case 4:
			selectionsort(a, len);
			cout << "----------------------------------------------------" << endl;
			break;
		case 5:
			binarysearch(a, len);
			cout << "----------------------------------------------------" << endl;
			break;
		case 6:
			cout << "Exiting the program...." << endl;
			cout << "----------------------------------------------------" << endl;
			break;
		default:
			cout << "\n\nPlease Enter Valid Choice\n\n";
			cout << "----------------------------------------------------" << endl;
		}
	} while (choice != 6);

	return 0;
}


void bubblesort(Student a[], int len)
{

	string temp;
	for (int i = 0; i < (len - 1); i++)
	{
		for (int j = 0; j < (len - 1); j++)
		{
			if (a[j].name > a[j + 1].name)
			{
				temp = a[j].name;
				a[j].name = a[j + 1].name;
				a[j + 1].name = temp;
			}
		}
	}

	cout << "Bubble sorted (Ascending) database is: \n\n";
	cout << "Name"<< "\t"<< "MobileNum"<< "\t"<< "Billamount"<< "" << endl;

	for (int i = 0; i < len; i++)
	{
		cout << a[i].name << "\t|" << a[i].mobilenum << "\t\t|" << a[i].billamt << endl;
	}
}

void selectionsort(Student a[], int len)
{
	int i, j, k, comp = 0;
	string temp;

	for (i = 0; i < len; i++)
	{

		k = i;
		for (j = i + 1; j < len; j++)
		{
			if ((a[j].name > a[k].name))
				k = j;
		}
		temp = a[i].name;
		a[i].name = a[k].name;
		a[k].name = temp;
	}

	cout << "Selection sorted (Descending) database is: \n\n";
	cout << "Name" << "\t" << "MobileNum" << "\t" << "Billamount" << "" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << a[i].name << "\t|" << a[i].mobilenum << "\t\t|" << a[i].billamt << endl;
	}
}

void binarysearch(Student a[], int len)
{

	string key;
	cout << "Enter the key you want to find: \n\n";
	cin >> key;
	int start = 0;
	int end = (len - 1);
	int mid = ((start + end) / 2);
	bool found = false;
	while (start <= end)
	{
		if (key > a[mid].name)
		{
			start = mid + 1;
		}
		else if (key < a[mid].name)
		{
			end = mid - 1;
		}

		if (key == a[mid].name)
		{
			found = true;
			break;
		}

		mid = ((start + end) / 2);
	}

	if (found)
	{
		cout << endl << key << " found at index " << mid << endl << endl;
		cout << "Name"<< "\t"<< "MobileNum" << "\t" << "Billamount" << "" << endl;
		cout << a[mid].name << "\t|" << a[mid].mobilenum << "\t\t|" << a[mid].billamt << endl;
	}
}

void displaydatabase(Student a[], int len)
{
	cout << "\nDisplaying database: \n\n";
	cout << "Name"<< "\t"<< "MobileNum"<< "\t"<< "Billamount"<< "" << endl;
	
	for (int i = 0; i < len; i++)
	{
		cout << a[i].name << "\t|" << a[i].mobilenum << "\t\t|" << a[i].billamt << endl;
	}
}

void create(Student a[], int len)
{
	cout << "Enter your database: \n\n";
	for (int i = 0; i < len; i++)
	{
		cout << "Entering for student: " << i + 1 << endl;
		cout << "Enter name of student: ";
		cin >> a[i].name;
		cout << "\nEnter mobile of student: ";
		cin >> a[i].mobilenum;
		cout << "\nEnter bill amount of student: ";
		cin >> a[i].billamt;
		cout << endl;
	}
	cout << endl;
}
