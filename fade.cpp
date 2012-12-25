#include <iostream>

using namespace std;

class rgb_color{
 public:
  int red;
  int green;
  int blue;
};

void balancedFade(rgb_color, rgb_color);
void set(rgb_color &, int, int, int);
void printColor(rgb_color const);

int main(){
  rgb_color color1;
  set(color1, 255, 0,0);
  rgb_color color2;
  set(color2, 2989, 155, 10);
  printColor(color1);
  balancedFade(color1, color2);

  return 0;
}

void balancedFade(rgb_color start, rgb_color end){
  int redChange = start.red - end.red;
  int greenChange = start.green - end.green;
  int blueChange = start.blue - end.blue;
  int absRed = redChange<0? 0-redChange : redChange;
  int absRed = redChange<0? 0-redChange : redChange;
  int absRed = redChange<0? 0-redChange : redChange;

  cout << absRed << endl;

  cout << "Change in red: " << redChange << endl;
  cout << "Change in green: " << greenChange << endl;
  cout << "Change in blue: " << blueChange << endl;
  
  int step = redChange > blueChange ? blueChange > greenChange ? greenChange : blueChange
                                      :redChange>greenChange?greenChange:redChange;
  cout << "Step: " << step << endl;
}

void set(rgb_color & color, int red, int green, int blue){
  color.red = red;
  color.green = green;
  color.blue = blue;
}

void printColor(rgb_color const color){
  cout << "Red: " << color.red << ", green: " << color.green << ", blue: " << color.blue << endl;
}