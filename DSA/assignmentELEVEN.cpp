#include <iostream>
#define MAX_SIZE 10 

using namespace std;

class heap {
private:
    int arr[MAX_SIZE]; 
    int n;

public:
    heap();
    void insert(int num);
    void makeheap();
    void heapsort();
    void display();
};

heap::heap() {
    n = 0;
    for (int i = 0; i < MAX_SIZE; i++) 
        arr[i] = 0;
}

void heap::insert(int num) {
    if (n < MAX_SIZE) { 
        arr[n] = num;
        n++;
    } else
        cout << "\n Array is Full"; 
}

void heap::makeheap() {
    for (int i = 1; i < n; i++) {
        int val = arr[i];
        int j = i;
        int f = (j - 1) / 2;
        while (j > 0 && arr[f] < val) {
            arr[j] = arr[f];
            j = f;
            f = (j - 1) / 2;
        }
        arr[j] = val;
    }
}

void heap::heapsort() {
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[i];
        arr[i] = arr[0];
        int k = 0;
        int j;
        if (i == 1)
            j = -1;
        else
            j = 1;
        if (i > 2 && arr[2] > arr[1])
            j = 2;
        while (j >= 0 && temp < arr[j]) { 
            arr[k] = arr[j];
            k = j;
            j = 2 * k + 1;
            if (j + 1 <= i - 1 && arr[j] < arr[j + 1])
                j++;
            if (j > i - 1)
                j = -1;
        }
        arr[k] = temp;
    }
}

void heap::display() {
    for (int i = 0; i < n; i++)
        cout << "\n" << arr[i];
    cout << "\n";
}

int main() {
    heap obj;
    obj.insert(14);
    obj.insert(12);
    obj.insert(9);
    obj.insert(8);
    obj.insert(7);
    obj.insert(10);
    obj.insert(18);
    cout << "\n The elements are:"; 
    obj.display();
    obj.makeheap();
    cout << "\n Heapified" << endl; 
    obj.heapsort();
    obj.display();

    return 0;
}
