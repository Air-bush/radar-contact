all: radar-contact.exe

radar-contact.exe: src/main.cpp
	g++ src/main.cpp -o radar-contact.exe