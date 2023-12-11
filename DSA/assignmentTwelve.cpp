#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <stdlib.h>

using namespace std;

class emp_class {
private:
    typedef struct emp {
        char name[20];
        int emp_id;
        int salary;
    } rec;

    typedef struct index {
        int emp_id;
        int position;
    } ind_rec;

    rec records;
    ind_rec ind_records;

public:
    emp_class();
    void create();
    void display();
    void update();
    void delet();
    void append();
    void search();
};

emp_class::emp_class() {
    strcpy(records.name, "");
}

void emp_class::create() {
    int i, j;
    char ch = 'y';
    fstream seqfile;
    fstream indexfile;
    i = 0;
    indexfile.open("ind.dat", ios::in | ios::out | ios::binary);
    seqfile.open("emp.dat", ios::in | ios::out | ios::binary);
    do {
        cout << "\n Enter name";
        cin >> records.name;
        cout << "\nEnter emp_id";
        cin >> records.emp_id;
        cout << "\n Enter salary";
        cin >> records.salary;
        seqfile.write((char*)&records, sizeof(records)) << flush;
        ind_records.emp_id = records.emp_id;
        ind_records.position = i;
        indexfile.write((char*)&ind_records, sizeof(ind_records)) << flush;
        i++;
        cout << "\n Do you want to add more records";
        cin >> ch;
    } while (ch == 'y');
    seqfile.close();
    indexfile.close();
}

void emp_class::display() {
    fstream seqfile;
    fstream indexfile;
    int n, i, j;
    seqfile.open("emp.dat", ios::in | ios::out | ios::binary);
    indexfile.open("ind.dat", ios::in | ios::out | ios::binary);
    indexfile.seekg(0, ios::beg);
    seqfile.seekg(0, ios::beg);
    cout << "\n The content of file are" << endl;
    i = 0;
    while (indexfile.read((char*)&ind_records, sizeof(ind_records))) {
        i = ind_records.position * sizeof(rec);
        seqfile.seekg(i, ios::beg);
        seqfile.read((char*)&records, sizeof(records));
        if (records.emp_id != -1) {
            cout << "\n Name" << records.name << flush;
            cout << "\n emp_id:" << records.emp_id;
            cout << "\n Salary:" << records.salary;
            cout << "\n";
        }
    }
    seqfile.close();
    indexfile.close();
}

void emp_class::update() {
    int pos, id;
    char New_name[20];
    int New_emp_id;
    int New_salary;
    cout << "\n for updation";
    cout << "\n Enter the emp_id to search";
    cin >> id;
    fstream seqfile;
    fstream indexfile;
    int n, i, j;
    seqfile.open("emp.dat", ios::in | ios::out | ios::binary);
    indexfile.open("ind.dat", ios::in | ios::out | ios::binary);
    indexfile.seekg(0, ios::beg);
    pos = -1;
    while (indexfile.read((char*)&ind_records, sizeof(ind_records))) {
        if (id == ind_records.emp_id) {
            pos = ind_records.position;
            break;
        }
    }
    if (pos == -1) {
        cout << "\nThe record is not present in the file";
        return;
    } else {
        cout << "\n Enter the values for updation";
        cout << "\n Enter Name";
        cin >> New_name;
        cout << "\n Enter salary";
        cin >> New_salary;
        int offset = pos * sizeof(rec);
        seqfile.seekp(offset);
        strcpy(records.name, New_name);
        records.emp_id = id;
        records.salary = New_salary;
        seqfile.write((char*)&records, sizeof(records)) << flush;
        cout << "\nThe record is updated";
    }
    seqfile.close();
    indexfile.close();
}

void emp_class::delet() {
    int id, pos;
    cout << "\n For deletion";
    cout << "\n Enter the emp_id to search";
    cin >> id;
    fstream seqfile;
    fstream indexfile;
    seqfile.open("emp.dat", ios::in | ios::out | ios::binary);
    indexfile.open("ind.dat", ios::in | ios::out | ios::binary);
    indexfile.seekg(0, ios::beg);
    seqfile.seekg(0, ios::beg);
    pos = -1;
    while (indexfile.read((char*)&ind_records, sizeof(ind_records))) {
        if (id == ind_records.emp_id) {
            pos = ind_records.position;
            ind_records.emp_id = -1;
            break;
        }
    }
    if (pos == -1) {
        cout << "\nThe record is not present in the file";
        return;
    }
    
    int offset = pos * sizeof(rec);
    seqfile.seekp(offset);
    strcpy(records.name, "");
    records.emp_id = -1;
    records.salary = -1;
    seqfile.write((char*)&records, sizeof(records)) << flush;
    offset = pos * sizeof(ind_rec);
    indexfile.seekp(offset);
    ind_records.emp_id = -1;
    ind_records.position = pos;
    indexfile.write((char*)&ind_records, sizeof(ind_records)) << flush;
    seqfile.seekg(0);
    indexfile.close();
    seqfile.close();
    cout << "\n The record is deleted";
}

void emp_class::append() {
    fstream seqfile;
    fstream indexfile;
    int pos;
    indexfile.open("ind.dat", ios::in | ios::binary);
    indexfile.seekg(0, ios::end);
    pos = indexfile.tellg() / sizeof(ind_records);
    indexfile.close();
    indexfile.open("ind.dat", ios::app | ios::binary);
    seqfile.open("emp.dat", ios::app | ios::binary);
    cout << "\n Enter the record for appending";
    cout << "\n Name";
    cin >> records.name;
    cout << "\n emp_id";
    cin >> records.emp_id;
    cout << "\n Salary";
    cin >> records.salary;
    seqfile.write((char*)&records, sizeof(records));
    ind_records.emp_id = records.emp_id;
    ind_records.position = pos;
    indexfile.write((char*)&ind_records, sizeof(ind_records)) << flush;
    seqfile.close();
    indexfile.close();
    cout << "\n The record is appended";
}

void emp_class::search() {
    fstream seqfile;
    fstream indexfile;
    int id, pos, offset;
    cout << "\n Enter the emp_id for searching the records";
    cin >> id;
    indexfile.open("ind.dat", ios::in | ios::binary);
    pos = -1;
    while (indexfile.read((char*)&ind_records, sizeof(ind_records))) {
        if (id == ind_records.emp_id) {
            pos = ind_records.position;
            break;
        }
    }
    if (pos == -1) {
        cout << "\nThe record is not present in the file";
        return;
    }

    offset = pos * sizeof(records);
    seqfile.open("emp.dat", ios::in | ios::binary);
    seqfile.seekg(offset, ios::beg);
    seqfile.read((char*)&records, sizeof(records));
    if (records.emp_id == -1) {
        cout << "\n Records is not present in the file";
        return;
    } else {
        cout << "\n The record is present in the file and it is:";
        cout << "\n Name: " << records.name;
        cout << "\n emp_id: " << records.emp_id;
        cout << "\n salary: " << records.salary;
    }
    seqfile.close();
    indexfile.close();
}

int main() {
    emp_class list;
    char ans = 'y';
    int ch, key;
    do {
        cout << "\n 1.Create \n 2.Display \n 3.Update \n 4.Delete \n 5.Append \n 6.Search \n 7.Exit";
        cout << "\n Enter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                list.create();
                break;
            case 2:
                list.display();
                break;
            case 3:
                list.update();
                break;
            case 4:
                list.delet();
                break;
            case 5:
                list.append();
                break;
            case 6:
                list.search();
                break;
            case 7:
                break;
        }
    } while (ans == 'y');
    return 0;
}
