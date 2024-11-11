#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
void quicksort(int a[],int,int);
void merge(int a[], int low, int mid, int high);
void divide(int a[], int low, int high);
int main()
{
int a[20],n,i;
pid_t pid;
printf("Enter size of the array: ");
scanf("%d",&n);
printf("Enter %d elements: ",n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
pid = fork();
switch(pid)
{
case 0:
printf ("I am child, my ID: %d", getpid() );
printf ("\nI am child, my Parent id: %d \n",getppid() );
quicksort(a,0,n-1);
break;
case -1:
printf ("The child process has not created");
break;
default:
printf ("\nI am in default , process id: %d ",getpid());
divide( a, 0, n-1);
sleep(3);
break;
} // switch case closed
printf("\n Sorted elements:\n ");
for(i=0;i<n;i++)
printf(" \t %d",a[i]);
return 0;
}
void divide(int a[], int low, int high)
{
if(low<high) 
{
int mid = (low+high)/2;
divide(a, low, mid); 
divide(a, mid+1, high); 
merge(a, low, mid, high);
}
}
void merge(int a[], int low, int mid, int high)
{
int i, j, k, m = mid-low+1, n = high-mid;
int first_half[m], second_half[n];
for(i=0; i<m; i++) 
first_half[i] = a[low+i];
for(i=0; i<n; i++) 
second_half[i] = a[mid+i+1];
i = j = 0;
k = low;
while(i<m || j<n) 
{
if(i >= m)
{
a[k++] = second_half[j++];
continue;
}
if(j >= n)
{
a[k++] = first_half[i++];
continue;
}
if(first_half[i] < second_half[j])
a[k++] = first_half[i++];
else
a[k++] = second_half[j++];
}
}
void quicksort(int a[],int first,int last)
{
int pivot,j,temp,i;
if(first<last){
pivot=first;
i=first;
j=last;
while(i<j){
while(a[i]<=a[pivot]&&i<last)
i++;
while(a[j]>a[pivot])
j--;
if(i<j){
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
temp=a[pivot];
a[pivot]=a[j];
a[j]=temp;
quicksort(a,first,j-1);
quicksort(a,j+1,last);
}
}
