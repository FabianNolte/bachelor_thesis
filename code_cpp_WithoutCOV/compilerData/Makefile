output: main.o StartFunction.o Generation.o Memory.o Setting.o EvolutionExecuter.o ExecuterSetting.o P.o W.o
	g++ main.o StartFunction.o Generation.o Memory.o Setting.o EvolutionExecuter.o ExecuterSetting.o P.o W.o -o output

main.o: ../Source_Files/main.cpp ../Header_Files/PathIntegral/StartFunction.h ../Header_Files/PathIntegral/Data/Generation.h ../Header_Files/PathIntegral/Data/Memory.h ../Header_Files/PathIntegral/Data/Setting.h ../Header_Files/PathIntegral/Evolution/EvolutionExecuter.h ../Header_Files/PathIntegral/Evolution/ExecuterSetting.h ../Header_Files/PathIntegral/Evolution/P.h ../Header_Files/PathIntegral/Evolution/W.h
	g++ -c ../Source_Files/main.cpp

StartFunction.o: ../Source_Files/StartFunction.cpp ../Header_Files/PathIntegral/StartFunction.h ../Header_Files/PathIntegral/Data/Generation.h
	g++ -c ../Source_Files/StartFunction.cpp

Generation.o: ../Source_Files/PathIntegral/Data/Generation.cpp ../Header_Files/PathIntegral/Data/Generation.h 
	g++ -c ../Source_Files/PathIntegral/Data/Generation.cpp

Memory.o: ../Source_Files/PathIntegral/Data/Memory.cpp ../Header_Files/PathIntegral/Data/Memory.h ../Header_Files/PathIntegral/Data/Generation.Header_Files
	g++ -c ../Source_Files/PathIntegral/Data/Memory.cpp

Setting.o: ../Source_Files/PathIntegral/Data/Setting.cpp ../Header_Files/PathIntegral/Data/Setting.h 
	g++ -c ../Source_Files/PathIntegral/Data/Setting.cpp

EvolutionExecuter.o: ../Source_Files/PathIntegral/Evolution/EvolutionExecuter.cpp ../Header_Files/PathIntegral/Evolution/EvolutionExecuter.h ../Header_Files/PathIntegral/Evolution/ExecuterSetting.h ../Header_Files/PathIntegral/Data/Generation.h ../Header_Files/PathIntegral/Data/Memory.h ../Header_Files/PathIntegral/Data/Setting.Header_Files
	g++ -c ../Source_Files/PathIntegral/Evolution/EvolutionExecuter

ExecuterSetting.o: ../Source_Files/PathIntegral/Evolution/ExecuterSetting.cpp ../Header_Files/PathIntegral/Evolution/ExecuterSetting.h 
	g++ -c ../Source_Files/PathIntegral/Evolution/ExecuterSetting.cpp

P.o: ../Source_Files/PathIntegral/Evolution/P.cpp ../Header_Files/PathIntegral/Evolution/P.h ../Header_Files/PathIntegral/Data/Generation.h ../Header_Files/PathIntegral/Data/Setting.h 
	g++ -c ../Source_Files/PathIntegral/Evolution/P.cpp

W.o: ../Source_Files/PathIntegral/Evolution/W.cpp ../Header_Files/PathIntegral/Evolution/W.h ../Header_Files/PathIntegral/Data/Generation.h 
	g++ -c ../Source_Files/PathIntegral/Evolution/W.cpp