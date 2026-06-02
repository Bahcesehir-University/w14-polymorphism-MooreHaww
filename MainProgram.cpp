#include <iostream>
#include <string>
#include <vector>
#include <cmath>

// ================================
// CLASS DEFINITIONS
// ================================

class Shape {
protected:
    std::string name;
public:
    Shape(const std::string& n) : name(n) {}

    // TODO 1: Virtual destructor
    virtual ~Shape() {}

    virtual double area() const = 0;

    virtual std::string describe() const {
        return name + " with area " + std::to_string(area());
    }

    std::string getName() const { return name; }
};

// ----------------------------------------------------------------

class Circle : public Shape {
private:
    double radius;
public:
    // TODO 2: Constructor
    Circle(double r) : Shape("Circle"), radius(r) {}

    // TODO 3: Override area()
    double area() const override {
        return M_PI * radius * radius;
    }
};

// ----------------------------------------------------------------

class Rectangle : public Shape {
protected:
    double width;
    double height;
public:
    // TODO 4: Constructor
    Rectangle(double w, double h) : Shape("Rectangle"), width(w), height(h) {}

    // TODO 5: Override area()
    double area() const override {
        return width * height;
    }
};

// ----------------------------------------------------------------

class Square : public Rectangle {
public:
    // TODO 6: Constructor
    Square(double side) : Rectangle(side, side) {
        name = "Square";
    }
};

// ================================
// FUNCTION IMPLEMENTATIONS
// ================================

// TODO 7: totalArea
double totalArea(const std::vector<Shape*>& shapes) {
    double total = 0.0;
    for (const Shape* s : shapes) {
        total += s->area();
    }
    return total;
}

// TODO 8: largestShapeName
std::string largestShapeName(const std::vector<Shape*>& shapes) {
    if (shapes.empty()) return "";
    Shape* largest = shapes[0];
    for (int i = 1; i < shapes.size(); i++) {
        if (shapes[i]->area() > largest->area()) {
            largest = shapes[i];
        }
    }
    return largest->getName();
}

// ================================
// MAIN (unchanged)
// ================================

int main() {
    std::vector<Shape*> shapes;
    shapes.push_back(new Circle(2.0));
    shapes.push_back(new Rectangle(3.0, 4.0));
    shapes.push_back(new Square(5.0));

    for (const Shape* s : shapes) {
        std::cout << s->describe() << std::endl;
    }

    std::cout << "Total area: " << totalArea(shapes) << std::endl;
    std::cout << "Largest:    " << largestShapeName(shapes) << std::endl;

    for (Shape* s : shapes) delete s;
    return 0;
}
