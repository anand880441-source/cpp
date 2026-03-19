#include <iostream>
using namespace std;

class Rectangle {
private:
    double width;
    double height;

public:
    void setDimensions(double w, double h) {
        if (w > 0 && h > 0) {
            width = w;
            height = h;
        } else {
            cout << "Invalid dimensions! Must be > 0." << endl;
        }
    }

    double getArea() {
        return width * height;
    }

    double getPerimeter() {
        return 2 * (width + height);
    }
};

int main() {
    Rectangle rect;
    
    rect.setDimensions(5.0, 3.0);

    cout << "area=" << rect.getArea() << endl;        
    cout << "perimeter=" << rect.getPerimeter() << endl; 

    return 0;
}
