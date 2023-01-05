csvGrapher.out:	csvGrapher.o
	clang++ -o csvGrapher.out  `sdl2-config --cflags --libs` -lSDL2_ttf csvGrapher.o /usr/include/jgraph/bin/jgraph.a

csvGrapher.o:	csvGrapher.cpp
	clang++ -c -o csvGrapher.o `sdl2-config --cflags --libs` -lSDL2_ttf csvGrapher.cpp

