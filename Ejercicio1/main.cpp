#include<iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
int main(){
     srand(time(0));
    int a=0;
    for(int i=0; i<=9;++i){
        a=rand() % 20 + 2;
        cout<< a <<endl;
    }
}
