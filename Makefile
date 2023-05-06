FLAGS = -pedantic-errors -std=c++11

main: main.o inputWindows.o inputLinuxMac.o screen.o fileRead.o maze.o player.o menu.o sleep.o helpers.o
	g++ $(FLAGS) $^ -o $@

main.o: src\main.cpp src\input.h src\screen.h src\fileRead.h src\maze.h src\player.h src\menu.h src\sleep.h src\helpersConsts.h src\statusConstants.h
	g++ $(FLAGS) -c $<

inputWindows.o: src\inputWindows.cpp src\inputWindows.h src\inputConstants.h
	g++ $(FLAGS) -c $<

inputLinuxMac.o: src\inputLinuxMac.cpp src\inputLinuxMac.h src\inputConstants.h
	g++ $(FLAGS) -c $<

screen.o: src\screen.cpp src\screen.h src\helpers.h src\fileRead.h src\sleep.h
	g++ $(FLAGS) -c $<

fileRead.o: src\fileRead.cpp src\fileRead.h src\helpers.h
	g++ $(FLAGS) -c $<

maze.o: src\maze.cpp src\maze.h src\screen.h src\sleep.h 
	g++ $(FLAGS) -c $<

player.o: src\player.cpp src\player.h src\helpers.h src\screen.h src\maze.h src\input.h src\fileRead.h
	g++ $(FLAGS) -c $<

menu.o: src\menu.cpp src\menu.h src\screen.h src\input.h src\statusConstants.h
	g++ $(FLAGS) -c $<

sleep.o: src\sleep.cpp src\sleep.h
	g++ $(FLAGS) -c $<

helpers.o: src\helpers.cpp src\helpers.h 
	g++ $(FLAGS) -c $<