#include <iostream>
#include <algorithm>
using namespace std;

int getArrPos(int arr[], int *ptr, int n)
{
    int i = 0;
    while (arr[i] != *ptr)
    {
        if (i < n)
            i++;
        else
            return -1;
    }

    return (i + 1);
}

int main()
{

    int arr[] = {2,4, 1, 7 ,6 ,5, 0};
    int n = sizeof(arr) / sizeof(arr[0]);


    cout << "Input number: ";
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    // pointer initiation
    int *lstptr = (arr + n - 1);
    int *ptr = lstptr;
  

    int c = 0;
    while (c < n)
    {
        if (*ptr < *(ptr - 1))
        {
            if (c == n - 1) sort (arr, arr + n);
            c++;
            ptr--;
        }
        else
        {
            ptr--;

            // swap
            int temp = *ptr;

            //set lstptr
            while (*lstptr <= *ptr)
            {
                lstptr--;
            }
            
            *ptr = *lstptr;
            *lstptr = temp;
            int posi = getArrPos(arr, ptr, n);
            sort(arr + posi, arr + n);

            break;
        }
    }

    cout<<"Next Permutation: ";
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}



