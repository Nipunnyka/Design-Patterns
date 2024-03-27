/*
TODOs for this method:
-code doesnt compile, make it run
-add notes + uml diagram for this method
-organize it into "creational design pattern folder"
*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

enum class ProductType { ConcreteProduct1, ConcreteProduct2 };

class Product{
public:
    virtual void drive() = 0;
};

class ConcreteProduct1 : public class Product{
    void drive(){
        cout<<"driving product 1";
    }
};

class ConcreteProduct2 : class Product{
    void drive(){
        cout<<"driving product 2";
    }
};

class Creator{
    public:
        virtual ~Creator() {};
        
        static unique_ptr<Product> createProduct(ProductType productType){
            switch(productType){
                case ConcreteProduct1:
                    return make_unique<ConcreteProduct1>();
                case ConcreteProduct2:
                    return make_unique<ConcreteProduct2>();
                default:
                    throw invalid_argument("Invalid product type");
            }
        }
};

int main() {
    unique_ptr<Product> p = Creator::createProduct(ConcreteProduct1);
    p.drive();
    unique_ptr<Product> p2 = Creator::createProduct(ConcreteProduct2);
    p2.drive();

    return 0;
}
