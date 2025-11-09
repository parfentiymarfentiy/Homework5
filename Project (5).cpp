#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Shape {
public:
    virtual ~Shape() {}
    virtual void Show() const = 0;
    virtual void Save(ofstream& file) const = 0;
    virtual void Load(ifstream& file) = 0;
    virtual string GetType() const = 0;
};

class Square : public Shape {
private:
    double x, y;
    double side;
public:
    Square(double x = 0, double y = 0, double side = 0) : x(x), y(y), side(side) {}
    
    void Show() const override {
        cout << "Square: top-left(" << x << ", " << y 
             << "), side=" << side << ", area=" << side*side << endl;
    }
    
    void Save(ofstream& file) const override {
        file << "Square " << x << " " << y << " " << side << endl;
    }
    
    void Load(ifstream& file) override {
        file >> x >> y >> side;
    }
    
    string GetType() const override { return "Square"; }
};

class Rectangle : public Shape {
private:
    double x, y;
    double width, height;
public:
    Rectangle(double x = 0, double y = 0, double w = 0, double h = 0) 
        : x(x), y(y), width(w), height(h) {}
    
    void Show() const override {
        cout << "Rectangle: top-left(" << x << ", " << y 
             << "), width=" << width << ", height=" << height 
             << ", area=" << width*height << endl;
    }
    
    void Save(ofstream& file) const override {
        file << "Rectangle " << x << " " << y << " " << width << " " << height << endl;
    }
    
    void Load(ifstream& file) override {
        file >> x >> y >> width >> height;
    }
    
    string GetType() const override { return "Rectangle"; }
};

class Circle : public Shape {
private:
    double centerX, centerY;
    double radius;
public:
    Circle(double cx = 0, double cy = 0, double r = 0) 
        : centerX(cx), centerY(cy), radius(r) {}
    
    void Show() const override {
        cout << "Circle: center(" << centerX << ", " << centerY 
             << "), radius=" << radius 
             << ", area=" << M_PI * radius * radius << endl;
    }
    
    void Save(ofstream& file) const override {
        file << "Circle " << centerX << " " << centerY << " " << radius << endl;
    }
    
    void Load(ifstream& file) override {
        file >> centerX >> centerY >> radius;
    }
    
    string GetType() const override { return "Circle"; }
};

class Ellipse : public Shape {
private:
    double x, y;
    double width, height;
public:
    Ellipse(double x = 0, double y = 0, double w = 0, double h = 0) 
        : x(x), y(y), width(w), height(h) {}
    
    void Show() const override {
        cout << "Ellipse: bounding-rect(" << x << ", " << y 
             << ", " << width << ", " << height 
             << "), area=" << M_PI * (width/2) * (height/2) << endl;
    }
    
    void Save(ofstream& file) const override {
        file << "Ellipse " << x << " " << y << " " << width << " " << height << endl;
    }
    
    void Load(ifstream& file) override {
        file >> x >> y >> width >> height;
    }
    
    string GetType() const override { return "Ellipse"; }
};

int main() {
    vector<Shape*> shapes;
    shapes.push_back(new Square(10, 10, 5));
    shapes.push_back(new Rectangle(20, 30, 8, 6));
    shapes.push_back(new Circle(15, 15, 3));
    shapes.push_back(new Ellipse(5, 5, 10, 7));
    
    cout << "Original shapes:" << endl;
    for (const auto& shape : shapes) {
        shape->Show();
    }
    
    ofstream outFile("shapes.txt");
    if (outFile.is_open()) {
        for (const auto& shape : shapes) {
            shape->Save(outFile);
        }
        outFile.close();
    }
    
    for (auto& shape : shapes) {
        delete shape;
    }
    shapes.clear();
    
    vector<Shape*> loadedShapes;
    ifstream inFile("shapes.txt");
    if (inFile.is_open()) {
        string type;
        while (inFile >> type) {
            Shape* shape = nullptr;
            if (type == "Square") {
                shape = new Square();
            } else if (type == "Rectangle") {
                shape = new Rectangle();
            } else if (type == "Circle") {
                shape = new Circle();
            } else if (type == "Ellipse") {
                shape = new Ellipse();
            }
            
            if (shape) {
                shape->Load(inFile);
                loadedShapes.push_back(shape);
            }
        }
        inFile.close();
    }
    
    cout << "\nLoaded shapes:" << endl;
    for (const auto& shape : loadedShapes) {
        shape->Show();
    }
    
    for (auto& shape : loadedShapes) {
        delete shape;
    }
    
    return 0;
}