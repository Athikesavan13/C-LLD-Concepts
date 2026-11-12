#include <iostream>
#include <vector>

using namespace std;

class Product{
public:
    string name;
    double price;

    Product(string name, double price){
        this->name = name;
        this-> price = price;
    }
};


class ShoppingCart{

private:
    vector<Product*> products;

public:
    void addProduct(Product* p){
        products.push_back(p);
    }

    const vector<Product*> getCart(){
        return products;
    }

    double calculateTotal(){
        double total = 0;

        for(auto p : products){
            total += p->price;
        }
        return total;
    }


    //Violating SRP
    void printInvoice(){
        cout << "Shopping Cart Invoice" << endl;
        int i = 1;
        for(auto p : products){
            cout << i++ <<" "<< p->name << "Rs : " <<p->price << endl; 
        }

        cout << "Total Price " << calculateTotal() << endl;
    }

    //Violated SRP
    void saveToDatabase(){
        cout << "Saving To Database" << endl;
    }
};


int main()
{
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 5000000));
    cart->addProduct(new Product("Mouse", 1200));

    cart->printInvoice();
    cart->saveToDatabase();

    return 0;
}