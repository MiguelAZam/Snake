#ifndef snake_h
#define snake_h

#include"node.hpp"
#include"area.hpp"

class Snake{

private:
  Node *preTail;
  Node *head;

public:
  int dir;

  Snake(int x, int y);
  bool checkGameOver();
  void setDir(int direction);
  void updatePreTail();
  void advance();
  bool eat(Node fruit);
  void drawSnake(Area *ptrSnake, sf::Color fill, sf::Color outline, int lineWeight, sf::RenderWindow *ptrWindow);

};

#endif
