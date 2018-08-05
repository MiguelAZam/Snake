#include<SFML/Graphics.hpp>
#include<time.h>
#include<cmath>
#include"area.hpp"
//#include"node.hpp"
#include"snake.hpp"

#define W 600
#define H 600
#define thick 1
#define squareSize 10

int main(){

  srand(time(0));
  sf::Clock clock;
  float timer=0, delay=0.1;
  
  sf::RenderWindow *ptrWindow;
  sf::RenderWindow window(sf::VideoMode(W, H), "Snake Game");
  ptrWindow = &window;

  Area walls = Area(W-20, H-20);
  Area fruitSquare = Area(squareSize, squareSize);
  Area snakeSquare = Area(squareSize, squareSize);
  Snake snake = Snake(W/2-10, H/2-10);


  while(window.isOpen()){
    float time = clock.getElapsedTime().asSeconds();
    clock.restart();
    timer += time;    
    sf::Event event;

    while(window.pollEvent(event)){
      if(event.type == sf::Event::Closed) window.close();
      
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && std::abs(snake.dir/2) != 0) snake.setDir(-1);
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && std::abs(snake.dir/2) != 0) snake.setDir(1);
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && std::abs(snake.dir/2) != 1) snake.setDir(-3);
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && std::abs(snake.dir/2) != 1) snake.setDir(3);

    }

    if(timer>delay){
      timer=0;
      snake.update();
    }

    window.clear(sf::Color::Black);

    walls.drawRect(sf::Color::Black, sf::Color::White, thick, 9, 9, ptrWindow);
    fruitSquare.drawRect(sf::Color::Red, sf::Color::White, thick, rand()%W, rand()%H, ptrWindow);

    snakeSquare.drawRect(sf::Color::White, sf::Color::Black, thick, snake.getX(), snake.getY(), ptrWindow);
    
    window.display();
  }
  
  return 0;

}
