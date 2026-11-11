#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class A{
private:
    string name;
public:
    A(string n){
        if(n.empty())
            throw invalid_argument("Not a Valid String");
        this->name = n;
        cout << "A created Using Comstructor"<<endl;
    }

    ~A(){
        cout<< " A Deleted Using Destructor" << endl;
    }

    void method1(){
        cout << "Dummy Method in A" << endl;
    }

    string get_name(){
        return this->name;
    }

    void set_name(string n){
        if(n.empty())
            throw invalid_argument("Not a Valid String");
        this->name = n;
        cout << "A Name changed"<<endl;
    }
};


class B_comp{
private:
    A* a;
public:
    B_comp(string a_obj){
        a = new A(a_obj);
        method2();
    }

    void method2(){
        if(!a){
            throw runtime_error("B Compostiion : A is not created So cannot call method 2.");
        }

        cout << " Dummy Method of B_ Compostion" << endl;
    }

    ~B_comp(){
        cout<<"B Compostiion Destructed" << endl;
        delete a;
        a = nullptr;
    }

    A* getA() {
        if (!a)
            throw runtime_error("B-Composition  A is null!");
        return a;
    }    
};


class C_aggr{
private:
    A* a;
public:
    C_aggr(A* aPtr){
        cout << endl << "C Aggregation Constructor called" << endl;
        if(!aPtr)
            throw invalid_argument(" Not a Valid A object pointer");
        this->a = aPtr;
        method3();
    }

    void method3(){
        if(!a) 
            throw runtime_error("In C aggregation A pointer fed is NULL");
        cout << "C aggreation Using A" << a->get_name() << endl;
    }

    ~C_aggr(){
        cout << "Destructor for C agrregation called" << endl;
        a = nullptr;
        cout<< " No need to delete A pointer just make it null becuse it was never created it just referenced" << endl;
    }
    A* getA() {
        if (!a)
            throw runtime_error("C-Aggregation: A is null!");
        return a;
    }

};


int main() {
    // --- Composition ---
    B_comp* b = new B_comp("Alpha");
    b->method2();
    b->getA()->method1();
    delete b;  // A also gets deleted here

    // --- Aggregation ---
    A* a = new A("Beta");
    C_aggr* c = new C_aggr(a);
    c->method3();
    c->getA()->method1();
    delete c;  // A still alive
    a->method1();  // proof A survives
    delete a;

    return 0;
}