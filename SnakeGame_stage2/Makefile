
CC		= g++
LDFLAGS = -lncurses 
CPPFLAGS= -std=c++11 -stdlib=libc++

SOURCES = main.cpp snakegame.cpp map.cpp snake.cpp
HEADERS = snakegame.h map.h snake.h


main: $(HEADERS) $(SOURCES)
	$(CC) -o $@ $(SOURCES) $(LDFLAGS) $(CPPFLAGS)

clean:
	@rm -rf *.o main
