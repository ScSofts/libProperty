#include "libProperty"
#include <iostream>
class test{
    public:
        test(){
            std::cout << "ctor is called!" << std::endl;
        }
        void func(){
            std::cout << "func is called!" << std::endl;
        }

        void getterTest(){
            std::cout << "getterTest is called!" << std::endl;
        }
};


class Test{
    public:
    Property<test*> i{
        decltype(i)::get{
            [](decltype(i)::BaseType &value){
                value->getterTest();
                return value;
            }
        },
        decltype(i)::set{
            [](test* value){
                return value;
            }
        },
        new test{}
    };

    //the number will plus 1 whenever it was stored
    Property<int> j{
        {},
        decltype(j)::set{
            [](int value){
                return value + 1;
            }
        }
    };
};
int main(){
    Test test;
    (test.i)->func();
    ::test* x = (test.i);
    test.j = 0;//j is 0+1
    test.j += 1;//j is (1+1)+1
    std::cout << test.j << std::endl;
    return 1;
}