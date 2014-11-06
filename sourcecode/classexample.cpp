// classes example
#include <iostream>
using namespace std;

class Rectangle {
    int width, height;
  public:
    Rectangle(int,int);
    int area() {return width*height;}
};

Rectangle::Rectangle(int width,int height)
{
	this->width = width;
	this->height = height;
}

/*void Rectangle::set_values (int x, int y) {
  width = x;
  height = y;
}*/

int main () {
  Rectangle rect(3,4);
  cout << "area: " << rect.area();
  return 0;
}