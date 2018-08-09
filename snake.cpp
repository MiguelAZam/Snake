#include<iostream>
#include"snake.hpp"

Snake::Snake(int x, int y){
  head = new Node(x, y);
  preTail = NULL;
  dir = 1;
}

bool Snake::checkGameOver(){
  Node *temp = new Node();
  if(head->x<10|| head->x>580 || head->y<10 || head->y>580) return true;
  for(temp=head->next; temp; temp=temp->next){
    if(head->x == temp->x && head->y == temp->y) return true;
  }
  return false;
}

void Snake::setDir(int direction){
  dir=direction;
}

void Snake::updatePreTail(){
  for(preTail=head; preTail->next->next; preTail=preTail->next);
}

void Snake::advance(){
  Node *newHead = new Node(head->x, head->y);
  if(dir/2 == 0){
    newHead->x = (dir%2) * 10 + head->x;
  } else{
    newHead->y = (dir%2) * 10 + head->y;
  }
  newHead->next = head;
  head = newHead;
  updatePreTail();
}

bool Snake::eat(Node fruit){
  if(head->x == fruit.x && head->y == fruit.y) return true;
  preTail->next = NULL;
  return false;
}

void Snake::drawSnake(Area *ptrSnake, sf::Color fill, sf::Color outline, int lineWeight, sf::RenderWindow *ptrWindow){
  Node *temp = new Node();
  temp = head;
  for(; temp; temp=temp->next){
    ptrSnake->drawRect(fill, outline, lineWeight, temp->x, temp->y, ptrWindow);
  }
}
