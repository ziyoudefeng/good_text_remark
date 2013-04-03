// 为什么要用member initialization ，尤其是template里面。


#include <iostream>

using namespace std;

class Based {
public:
    Based() {cout << "Based()" << endl;}
    Based& operator=(const Based &rhs) {cout << "operator=" << endl;}
    Based(const Based &rhs) {cout << "Based(const Based&)" << endl; }
};

template <typename T>
class temp {
public:
    // 以下两种不同的constructor会对main里面temp<Based> t(b1);差生截然不同的结果。
    //temp(const T &val) {_val = val;} //一次Based() 一次operator=(const Based &rhs)
    temp(const T &val) : _val(val) {} // 只有一次Based(const Based &rhs)
    temp() {cout << "temp()" << endl;}

private:
    T _val;

};

int main(void)
{
    Based b1;
    cout << "---" << endl;
    temp<Based> t(b1);
}
