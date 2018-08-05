#include "area.hpp"

Area::Area(int width, int height){
  area = sf::RectangleShape(sf::Vector2f(width, height));
}

void Area::drawRect(sf::Color fill, sf::Color outline, int lineWeight, int xPos, int yPos, sf::RenderWindow *ptrWindow){
  area.setFillColor(fill);
  area.setOutlineThickness(lineWeight);
  area.setOutlineColor(outline);
  area.setPosition(sf::Vector2f(xPos, yPos));
  ptrWindow->draw(area);
}
