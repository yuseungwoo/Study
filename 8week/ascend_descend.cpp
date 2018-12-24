#include <iostream>
#include <algorithm>

using namespace std;

void show(int a[]){

	for(int i=0; i<10; i++){

		cout << a[i] <<" ";
	}

}

int main(void){

	//std::cout << "hi" << std::endl;

	int a[10]={1,5,8,9,6,7,3,4,2,0};
	int n=sizeof(a)/sizeof(int);
	show(a);

	sort(a,a+n);  //오름차순 
	sort(a,a+n,greater<int>()); //내림차순

	cout << endl;

	show(a);

	return 0;
}
