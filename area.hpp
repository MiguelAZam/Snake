#ifndef area_h
#define area_h
#include<SFML/Graphics.hpp>

class Area{

public:
  sf::RectangleShape area;

  Area(int width, int height);
  void drawRect(sf::Color fill, sf::Color outline, int lineWeight, int xPos, int yPos, sf::RenderWindow *ptrWindow);
};

#endif
