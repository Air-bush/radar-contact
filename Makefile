all: radar-contact.exe

radar-contact.exe: src/main.cpp
	g++ src/main.cpp -o radar-contact.exe -lraylib -IC:/raylib/raylib/src -LC:/raylib/raylib/src -lopengl32 -lgdi32 -lwinmm