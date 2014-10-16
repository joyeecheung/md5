CC=g++
#CFLAGS=-c -Wall
CFLAGS=-c -Wall -DSAMPLE_TEST

TEST=test.cpp
MD5=md5.cpp
MAIN=main.cpp

SOURCES=$(MD5) $(TEST) $(MAIN)
OBJECTS=$(patsubst %.cpp,obj/%.o,$(SOURCES))
EXECUTABLE=md5

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

$(OBJECTS): | obj

obj:
	@mkdir -p $@

obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm obj/*.o $(EXECUTABLE)

test:

cleantest:

.PHONY: test cleantest