LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
COMP = g++

all: game

game: ${COMMON_OBJECTS} main.o
	(${COMP} -o  $@ $^ ${LIBS})
	(mkdir bin; mv *.o ./bin/)

run: game
	./game

mvh:
	mv *.hpp h/

clean:
	rm -rf bin/ *~ game

