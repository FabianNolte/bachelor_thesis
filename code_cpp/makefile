CC=g++
CFLAGS=-c -g -Wall `root-config --cflags`
LDFLAGS=`root-config --glibs`

MAINPATH= ./Source_Files
DATAPATH= ./Source_Files/Data
EVOLUTIONPATH= ./Source_Files/Evolution
SOURCENAMES_=main.cpp StartFunction.cpp
SOURCENAMES_DATA= Generation.cpp Memory.cpp Setting.cpp
SOURCENAMES_EVOLUTION= EvolutionExecuter.cpp ExecuterSetting.cpp P.cpp W.cpp
ALLSOURCENAMES= $(SOURCENAMES_) $(SOURCENAMES_DATA) $(SOURCENAMES_EVOLUTION)
SOURCES= $(addprefix $(MAINPATH)/,$(SOURCENAMES_)) $(addprefix $(DATAPATH)/,$(SOURCENAMES_DATA)) $(addprefix $(EVOLUTIONPATH)/,$(SOURCENAMES_EVOLUTION)) 

OBJECTS=$(ALLSOURCENAMES:.cpp=.o)
EXECUTABLE=main

#default: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $(EXECUTABLE) $(OBJECTS) $(LDFLAGS)

$(OBJECTS): $(SOURCE)
	$(CC) $(SOURCES) $(CFLAGS)

clean:
	rm ./*.o ./main
