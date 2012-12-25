#include <iostream>

using namespace std;

class rgb_color{
 public:
  int red;
  int green;
  int blue;
};

void fade(rgb_color, rgb_color);
void set(rgb_color &, int, int, int);

int main(){
  rgb_color color1;
  rgb_color color2;
  fade(color1, color2);

  return 0;
}

void fade(rgb_color start, rgb_color end){
  cout << "start r - end r: " << start.red - end.red << endl;
  cout << "start g - end g: " << start.green - end.green << endl;
  cout << "start b - end b: " << start.blue - end.blue << endl;
}

void set(rgb_color & color, int red, int green, int blue){
  color.red = red;
  color.green = green;
  color.blue = blue;
}