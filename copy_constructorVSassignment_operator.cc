
//그냥 선언을 하면 기본 생성자를,

//생성시기 때 같은 타입을 인자로 넣어준다면 복사 생성자를,

//생성시기 때 같은 타입을 대입 연산한다면 복사 생성자를,

//그 이후 일반 상황에서 대입 연산한다면 복사 대입 연산자를

//사용하게 됩니다.

#include <iostream>
using namespace std;
 
class Test {
private:
    int m_i;
public:
    // 기본 생성자(default constructor)
    Test(){
        this->m_i = 0;
        cout << "call the default constructor" << endl;
    }
    // 복사 생성자(copy constructor)
    Test(const Test &t) {
        this->m_i = t.m_i;
        cout << "call the copy constructor" << endl;
    }
    // 복사 대입 연산자(copy assignment operator)
    Test& operator=(const Test &t) {
        this->m_i = t.m_i;
        cout << "call the copy assignment operator" << endl;
        return *this;
    }
     
    int getMember() const {
        return this->m_i;
    }
};
 
// "값에 의한 호출"은 "복사 생성자"를 이용하는 것을 알기 위한 테스트 함수
bool isEmpty(Test t) {
    if (t.getMember() == 0)
        return true;
    return false;
}
 
int main() {
    Test t1;        // call default constructor
    Test t2(t1);    // call copy constructor
    Test t3 = t1;   // call copy constructor
    t1 = t2;        // call copy assignment operator
     
    cout << isEmpty(t1) << endl;
    // call copy constructor
     
    return 0;
}

