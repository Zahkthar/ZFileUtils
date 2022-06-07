CXX = gcc
CXXFLAGS = -Wall -g

LDFLAGS =

EXEC = ZFileUtils

all : release

release : main.o ZFileUtilsFunctions.o
	$(CXX) obj\main.o obj\ZFileUtilsFunctions.o -o bin\$(EXEC)  $(LDFLAGS)

main.o : src\main.c
	$(CXX) $(CXXFLAGS) -c src\main.c -o obj\main.o

ZFileUtilsFunctions.o : src\ZFileUtilsFunctions.c
	$(CXX) $(CXXFLAGS) -c src\ZFileUtilsFunctions.c -o obj\ZFileUtilsFunctions.o