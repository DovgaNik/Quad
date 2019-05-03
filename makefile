CppC=g++
CFlags= -pipe -Wall -Wextra -Wpedantic
EXE=quad
SRC=src/main.cpp
OBJ=build/main.o
DESTDIR=/bin

all: bin/$(EXE)
	$(CppC) $(CFlags) $(OBJ) -o bin/$(EXE)

bin/$(EXE): $(OBJ)
	$(CppC) $(CFlags) $(OBJ) -o bin/$(EXE)

$(OBJ): $(SRC)
	$(CppC) $(CFlags) -c $(SRC) -o $(OBJ)

clean:
	rm $(OBJ) bin/$(EXE)
	rm $(DESTDIR)/$(EXE)

.PHONY: install
install: bin/$(EXE)
	mkdir -p $(DESTDIR)
	cp bin/$(EXE) $(DESTDIR)

.PHONY: uninstall
uninstall:
	rm $(DESTDIR)/$(EXE)
