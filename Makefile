all: compile link

compile:
	g++ -c main.cpp -I"C:\mingw64\sfml\include" -DSFML_STATIC

link:
	g++ main.o -o main -L"C:\mingw64\sfml\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows
	./main
clean:
	rm -f main *.o

