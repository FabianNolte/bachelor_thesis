output: main.o StartFunction.o Generation.o Memory.o Setting.o EvolutionExecuter.o ExecuterSetting.o P.o W.o
	g++ main.o StartFunction.o Generation.o Memory.o Setting.o EvolutionExecuter.o ExecuterSetting.o P.o W.o -o output

main.o: ../Source_Files/main.cpp ../Header_Files/StartFunction.h ../Header_Files/Data/Generation.h ../Header_Files/Data/Memory.h ../Header_Files/Data/Setting.h ../Header_Files/Evolution/EvolutionExecuter.h ../Header_Files/Evolution/ExecuterSetting.h ../Header_Files/Evolution/P.h ../Header_Files/Evolution/W.h
	g++ -c ../Source_Files/main.cpp

StartFunction.o: ../Source_Files/StartFunction.cpp ../Header_Files/StartFunction.h ../Header_Files/Data/Generation.h
	g++ -c ../Source_Files/StartFunction.cpp

Generation.o: ../Source_Files/Data/Generation.cpp ../Header_Files/Data/Generation.h 
	g++ -c ../Source_Files/Data/Generation.cpp

Memory.o: ../Source_Files/Data/Memory.cpp ../Header_Files/Data/Memory.h ../Header_Files/Data/Generation.Header_Files
	g++ -c ../Source_Files/Data/Memory.cpp

Setting.o: ../Source_Files/Data/Setting.cpp ../Header_Files/Data/Setting.h 
	g++ -c ../Source_Files/Data/Setting.cpp

EvolutionExecuter.o: ../Source_Files/Evolution/EvolutionExecuter.cpp ../Header_Files/Evolution/EvolutionExecuter.h ../Header_Files/Evolution/ExecuterSetting.h ../Header_Files/Data/Generation.h ../Header_Files/Data/Memory.h ../Header_Files/Data/Setting.Header_Files
	g++ -c ../Source_Files/Evolution/EvolutionExecuter

ExecuterSetting.o: ../Source_Files/Evolution/ExecuterSetting.cpp ../Header_Files/Evolution/ExecuterSetting.h 
	g++ -c ../Source_Files/Evolution/ExecuterSetting.cpp

P.o: ../Source_Files/Evolution/P.cpp ../Header_Files/Evolution/P.h ../Header_Files/Data/Generation.h ../Header_Files/Data/Setting.h 
	g++ -c ../Source_Files/Evolution/P.cpp

W.o: ../Source_Files/Evolution/W.cpp ../Header_Files/Evolution/W.h ../Header_Files/Data/Generation.h 
	g++ -c ../Source_Files/Evolution/W.cpp