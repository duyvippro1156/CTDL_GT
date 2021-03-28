#include<stdio.h>
void Input(int a[],int &n)
{
	printf("Nhap so phan tu: ");
	scanf("%d" ,&n);
	printf("\nNhap day so:\n");
	for(int i=1;i<=n;i++)
	{
		printf("\nSo thu %d: " ,i);
		scanf("%d" ,&a[i]);
	}
}
void Output(int a[],int low, int high)
{
	for(int i=low;i<=high;i++)
		printf(" %d ",a[i]);
}
void Permutation(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
int Partition(int a[], int low, int high)
{
    int pivot = a[high];
    int left = low;
    int right = high - 1;
    while(true)
	{
        while(left <= right && a[left] < pivot) 
			left++;
        while(right >= left && a[right] > pivot) 
			right--;
        if (left >= right) 
			break;
        Permutation(a[left],a[right]);
        left++;
        right--;
    }
    Permutation(a[left], a[high]);
    return left;
}
void Sort(int a[], int low, int high,int i)
{
    if (low < high)
    {
    	printf("\nDay so can sap xep cap %d: \nPivot=%3d Left=%3d Right=%3d :" ,i ,high ,low ,high-1);
    	Output(a,low,high);
        int pi = Partition(a, low, high);
        Sort(a, low, pi - 1,i+1);
        Sort(a, pi + 1, high,i+1);
    }
}
int main()
{
    int a[100],n;
    Input(a,n);
	printf("\n\nDay so: \n");	
    Output(a,1,n);
    printf("\n\n Qua trinh sap xep ");
   	Sort(a,1,n,1);
   	printf("\n\nDay so da sap xep: \n");
   	Output(a,1,n);
}
