CppC=g++
CFlags= -pipe -Wall -Wextra -Wpedantic
EXE=quad
SRC=src/main.cpp
OBJ=build/main.o
DESTDIR=/bin

all: bin/$(EXE)

bin/$(EXE): $(OBJ)
	mkdir -p bin
	$(CppC) $(CFlags) $(OBJ) -o bin/$(EXE)

$(OBJ): $(SRC)
	mkdir -p build
	$(CppC) $(CFlags) -c $(SRC) -o $(OBJ)

clean:
	rm -rf build bin

.PHONY: install
install: bin/$(EXE)
	mkdir -p $(DESTDIR)
	cp bin/$(EXE) $(DESTDIR)

.PHONY: uninstall
uninstall:
	rm $(DESTDIR)/$(EXE)
