#include<SFML/Graphics.hpp>
#include<time.h>
#include"area.hpp"

#define W 600
#define H 600
#define thick 1

int main(){

  sf::RenderWindow *ptrWindow;
  sf::RenderWindow window(sf::VideoMode(W, H), "Snake Game");
  ptrWindow = &window;

  Area walls = Area(W-20, H-20);
  Area fruitSquare = Area(10, 10);
  Area snakeSquare = Area(10, 10);


  while(window.isOpen()){
    sf::Event event;

    while(window.pollEvent(event)){
      if(event.type == sf::Event::Closed) window.close();
    }

    window.clear(sf::Color::Black);

    walls.drawRect(sf::Color::Black, sf::Color::White, thick, 9, 9, ptrWindow);
    fruitSquare.drawRect(sf::Color::Red, sf::Color::White, thick, 100, 100, ptrWindow);
    snakeSquare.drawRect(sf::Color::White, sf::Color::Black, thick, W/2, H/2, ptrWindow);
    
    window.display();
  }

  
  return 0;

}
