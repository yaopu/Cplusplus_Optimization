#include<stdio.h>
#include<iostream>
  using namespace std;
void bubble_sort(int a[],int n); //array,number of items
int main()
{
    int a[5] = {1,9,6,2,3};

const int n= sizeof(a)/sizeof(a[0]);
cout << n <<endl;
    bubble_sort(a,n);

    for(int i=0;i<n;i++)
    {
        std::cout << a[i] <<"  ";
    }
    std::cout<< "\n";

}


void bubble_sort(int a[],int n)
{
    int temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++) //第二层循环
        {
            if(a[j] <a[j+1]) //降序
            {
               temp =  a[j];
               a[j] = a[j+1];
               a[j+1] = temp;
            }
        }
    }
}
