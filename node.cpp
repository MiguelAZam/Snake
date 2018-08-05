#include<iostream>
#include"node.hpp"

Node::Node(){
  x=0;
  y=0;
  next=NULL;
}

Node::Node(int x, int y){
  this->x = x;
  this->y = y;
  next = NULL;
}
