#include<iostream>
using namespace std;

void min_max_loc(float arr[], int sz, float* min, float* max, int *minloc, int*maxloc); //dataType* <- this is a pointer

int main()
{
    float arr[] = {1, 54, 67, -2, 0, -45, 12, 2}, min, minloc, max, maxloc;
    unsigned int n=8;




    return 0;
}
void min_max_loc(float arr[], int sz, float* min, float* max, int *minloc, int*maxloc)
{
    //min - a memory location (pointer) 0x123AC
    //min = arr[0]; min will point to the adress 1

    //we want to change the value stored at the adress min 0x123AC
    //dereferincing operator *
    //*min = arr[0];
    *min = arr[0];
    *minloc = 0;
    *max = arr[0];
    *maxloc = 0;
    for(int i=1;i<sz;i++)
    {
        if(arr[i]<*min)
        {
            *min=arr[i], *minloc = i;
        }
    }


}
