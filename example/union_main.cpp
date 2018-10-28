#include <iostream>
#include <memory>
#include <sys/time.h>
#include "Union.h"

double getTime(timeval &startTime){
    timeval timeval1;
    gettimeofday(&timeval1, NULL);
    return timeval1.tv_sec-startTime.tv_sec+(timeval1.tv_usec-startTime.tv_usec)/1000000;
}

void UnionTest(){
    vector<int> tree = {0,1,2,3,4,5,6,7,8,9,10,11,12};
    Union<int> anUnion(tree);
    anUnion.quickUnion(0,2);
    anUnion.quickUnion(1,4);
    anUnion.quickUnion(1,5);
    anUnion.quickUnion(3,7);
    anUnion.quickUnion(3,0);
    anUnion.quickUnion(0,1);
    anUnion.quickUnion(6,8);
    anUnion.quickUnion(8,10);
    anUnion.quickUnion(8,0);
    anUnion.quickUnion(9,11);
    anUnion.quickUnion(12,11);
    anUnion.quickUnion(12,0);
    cout << "ok";
}

void PtrTest(){
    int *a = new int[2];
    a[0] = 1;
    a[1] = 2;
    shared_ptr<int> shared_a(a);
    cout << shared_a.use_count();

    shared_ptr<int> shared_ptr1(a);
    cout << shared_a.use_count();

    shared_ptr<int> shared_ptr2(shared_a);
    cout << shared_a.use_count();
    cout << shared_ptr2.use_count();

//    delete [] a;
}

int main() {
    PtrTest();
    return 0;
}