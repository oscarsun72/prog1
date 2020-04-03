﻿#ifndef HASPTR_H
#define HASPTR_H
#include<string>
#include<iostream>
class HasPtr
{
    friend void swap(HasPtr&, HasPtr&);
public:
    HasPtr(const std::string& s = std::string()) : ps(new std::string(s)), i(0) {}
    //拷貝建構器：每個HasPtr物件都有一個ps指標指向的那個string的副本
    HasPtr(const HasPtr& p) : ps(new std::string(*p.ps)), i(p.i) {}
    HasPtr& operator=(HasPtr);
    bool operator<(const HasPtr&);
    std::string& getStr();
    ~HasPtr() { delete ps; }
    
private:
    std::string* ps;
    int i;
};
inline void swap(HasPtr&lhs,HasPtr&rhs){//頁517
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "swap here！感恩感恩 南無阿彌陀佛" << std::endl;
}
inline HasPtr& HasPtr::operator=(HasPtr rhs) {//頁518
    swap(rhs, *this);
    return *this;
}
inline bool HasPtr::operator<(const HasPtr& rhs) {
    if ((*ps < *rhs.ps) && (i<=rhs.i))
    {
        return true;
    }
    return false;
}
inline std::string& HasPtr::getStr() {
    return *ps;
}

#endif // !HASPTR_H
