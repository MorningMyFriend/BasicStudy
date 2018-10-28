//
// Created by wurui on 18-10-26.
//

#ifndef ALGORITHM_COPY_FORBIDDEN_H
#define ALGORITHM_COPY_FORBIDDEN_H

#endif //ALGORITHM_COPY_FORBIDDEN_H

class CopyForbidden{
public:
    CopyForbidden(){};

private:
    CopyForbidden(const CopyForbidden& copyForbidden){}
};

class obj: public CopyForbidden{
public:
    obj(){}
    obj(int i):data(i){

    }

    int data;
};