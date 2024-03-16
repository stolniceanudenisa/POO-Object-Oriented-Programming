#include <iostream>
#include <functional>
using namespace std;
#include <windows.h>

// callback function prototype
typedef void (*ProgressListener) ( int percent ) ;

// compute: function that notifies the progress of a computation using callbacks
// the callback function is passed as pointer to function parameter to the compute method
void compute(void (*callback)(int))
// alternative syntax for the callback function to the processing (compute) function
//void compute(std::function<void(int)> callback) // using the std::function class template: syntax: std::function<ret_type(param1_type,param2_type)>
//void compute(ProgressListener callback) // using the user defined name
{
    for ( int i = 0; i < 100; i ++)
    {
        // doing some heavy computation
        Sleep(50); // sleep for 0.05 seconds, just to simulate a heavy computation
        callback( i ) ; // after each iteration, the callback function is called (notification of the event)
    }
    cout<<"\nDone.\n";
}

// we define a progress listener function with the required prototype
void onProgress( int percent)
{
    cout<< "\rprogress: " << percent<<std::flush;
}
int main()
{
    compute(onProgress);
    return 0;
}
