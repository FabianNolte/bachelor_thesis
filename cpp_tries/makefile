CC=g++
CFLAGS=-c -g -Wall `root-config --cflags`
LDFLAGS=`root-config --glibs` -lMinuit

SOURCES= main.cpp chiqFit.cpp

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main

#default: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $(EXECUTABLE) $(OBJECTS) $(LDFLAGS)

$(OBJECTS): $(SOURCE)
	$(CC) $(SOURCES) $(CFLAGS)

clean:
	rm ./*.o ./main
