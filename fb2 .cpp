#include <iostream>
#include <random>
#include <vector>
using namespace ::std;

int main(){
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(1, 100);
    int a = distribution(generator),b = distribution(generator);
    for(int i =0;i < 20;i++){
        int sum[i];
        sum[0] = a + b;
        sum[i] = sum[i-1]+sum[i-2];
    }



}