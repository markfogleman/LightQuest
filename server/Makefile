CXX = g++

#CFLAGS = -std=c++11 -O2 -Wall -g
CFLAGS = -std=c++11 -Wall -g

INCLUDES =

INCS = $(wildcard ./*.hpp)

LFLAGS = 

LIBS = 

SRCS = $(wildcard ./*.cpp)

OBJS = $(SRCS:.cpp=.o)

MAIN = LIGHTQUEST

all:	$(MAIN)

$(MAIN): $(OBJS)
	$(CXX) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

.cpp.o: 
	$(CXX) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm *.o $(MAIN)

