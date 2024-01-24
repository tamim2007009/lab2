#include <bits/stdc++.h>
using namespace std;
class Shape {
public:
    virtual void draw() = 0; 
    virtual ~Shape() {} 
};


class Rectangle : public Shape {
public:
    
    void draw() override {
        std::cout << "Inside Rectangle::draw() method." << std::endl;
    }
};

class Square : public Shape {
public:
    
    void draw() override {
        std::cout << "Inside Square::draw() method." << std::endl;
    }
};
class ShapeFactory {




public:
    
    Shape* getShape(const std::string& shapeType) {
        if (shapeType.empty()) {
            return nullptr;
        }

        if (shapeType == "RECTANGLE") {
            return new Rectangle();
        } else if (shapeType == "SQUARE") {
            return new Square();
        }

        return nullptr;
    }
};
int main() {
   
    ShapeFactory shapeFactory;

    Shape* shape1 = shapeFactory.getShape("CIRCLE"); 
    if (shape1) {
        shape1->draw();
        delete shape1;
    } else {
        std::cout << "Unsupported shape: CIRCLE" << std::endl;
    }

    Shape* shape2 = shapeFactory.getShape("RECTANGLE");
    if (shape2) {
        shape2->draw();
        delete shape2;
    }

    return 0;
}
 