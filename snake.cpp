#include<iostream>
#include"snake.hpp"

Snake::Snake(int x, int y){
  head = new Node(x, y);
  preTail = NULL;
  dir = 1;
}

bool Snake::check(){
  Node *temp = new Node();
  for(temp=head->next; temp; temp=temp->next){
    if(head->x == temp->x && head->y == temp->y) return true;
  }
  return false;
}

void Snake::setDir(int direction){
  dir=direction;
}

void Snake::update(){
  Node *newHead = new Node(head->x, head->y);
  if(dir/2 == 0){
    newHead->x = (dir%2) * 10 + head->x;
  } else{
    newHead->y = (dir%2) * 10 + head->y;
  }
  if(preTail == NULL){
    head = newHead;
  } else{
    preTail->next = NULL;
    newHead->next = head;
    head = newHead;
  }
}

void Snake::add(){
  //Node *newTail = new Node(tail->x, tail->y);
  //tail->next = newTail;
  //tail = newTail;
}

int Snake::getX(){
  return head->x;
}

int Snake::getY(){
  return head->y;
}
