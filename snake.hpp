#include"node.hpp"

class Snake{

private:
  Node *preTail;
  Node *head;

public:
  int dir;

  Snake(int x, int y);
  bool check();
  void setDir(int direction);
  void update();
  void add();
  bool eat(Node node);
  int getX();
  int getY();

};
