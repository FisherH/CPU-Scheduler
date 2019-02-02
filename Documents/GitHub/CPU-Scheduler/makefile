OBJS	= fcfs.o main.o rr.o scheduleSim.o srtf.o
SOURCE	= fcfs.cpp main.cpp rr.cpp scheduleSim.cpp srtf.cpp
HEADER	= fcfs.h rr.h scheduleSim.h srtf.h
OUT	= schedsim
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

fcfs.o: fcfs.cpp
	$(CC) $(FLAGS) fcfs.cpp 

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

rr.o: rr.cpp
	$(CC) $(FLAGS) rr.cpp 

scheduleSim.o: scheduleSim.cpp
	$(CC) $(FLAGS) scheduleSim.cpp 

srtf.o: srtf.cpp
	$(CC) $(FLAGS) srtf.cpp 


clean:
	rm -f $(OBJS) $(OUT)

