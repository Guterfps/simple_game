
DCC = g++ -std=c++98 -pedantic-errors -Wall -Wextra -g
RCC = g++ -std=c++98 -pedantic-errors -Wall -Wextra -DNDEBUG -O3
FILES = first_try.cpp game.cpp agent.cpp movebehaviour.cpp seek.cpp flee.cpp

debug: $(FILES)
	$(DCC) $(FILES) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o game.out
        
realese: $(FILES)
	$(RCC) $(FILES) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o game.out   
