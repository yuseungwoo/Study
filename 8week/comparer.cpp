#include <iostream>
#include <algorithm>

using namespace std;

struct Interval{

	int start, end;

};

typedef struct Interval Interval;

bool compareInterval(Interval i1, Interval i2){

	return (i1.end< i2.end);

}

int main(int argc, char* argv[]){

    //std::cout << "hello world" << std::endl;

	Interval arr[]={{6,8},{1,9},{2,4},{4,7}};
	int n = sizeof(arr)/sizeof(Interval);

	sort(arr, arr+n, compareInterval);

	  cout << "Intervals sorted by start time : \n";
	    for (int i=0; i<n; i++)
	       cout << "[" << arr[i].start << "," << arr[i].end
	            << "] ";

	return 0;
}
