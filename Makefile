CC = gcc

UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
	CCOPTS = -pipe -O2 -std=c99 -lm
endif
ifeq ($(UNAME), Darwin)
	CCOPTS = -pipe -O2 -std=c11
endif

LIB_CCOPTS = -c

# Unity unit tests - Define UNITY_SRC as an ENV var if it's not local
# and you want to build it from source
ifndef UNITY_SRC
	UNITY_SRC = unity/src
endif
UNITY_DEPS = $(UNITY_SRC)/unity.c $(UNITY_SRC)/unity.h
#UNITY_OBJECTS = $(UNITY_SRC)/unity.o
UNITY_OBJECTS = unity.o
UNITY_INCLUDES = -I $(UNITY_SRC)

BINSEARCH_DEPS = binarysearch.c binarysearch.h
BINSEARCH_OBJECTS = binarysearch.o
OBJECTS = $(BINSEARCH_OBJECTS)

BINSEARCH_TEST = binarysearch_test
BINSEARCH_TEST_DEPS = binarysearch.c binarysearch.h binarysearch_test.c $(UNITY_DEPS)
TEST_BINS = $(BINSEARCH_TEST)
BINSEARCH_TEST_OBJECTS = binarysearch_test.o $(UNITY_OBJECTS)

all: $(OBJECTS)

binarysearch.o: $(BINSEARCH_DEPS)
	$(CC) $(CCOPTS) $(LIB_CCOPTS) -o binarysearch.o binarysearch.c

#unity/src/unity.o: $(UNITY_DEPS)
unity.o: $(UNITY_DEPS)
	$(CC) $(CCOPTS) $(LIB_CCOPTS) -o unity.o $(UNITY_SRC)/unity.c

binarysearch_test.o: $(BINSEARCH_DEPS) $(BINSEARCH_OBJECTS) $(BINSEARCH_TEST_DEPS) $(UNITY_OBJECTS)
	$(CC) $(CCOPTS) $(LIB_CCOPTS) $(UNITY_INCLUDES) -o binarysearch_test.o binarysearch_test.c

binarysearch_test: $(BINSEARCH_DEPS) $(BINSEARCH_OBJECTS) $(BINSEARCH_TEST_DEPS) $(BINSEARCH_TEST_OBJECTS)
	$(CC) $(CCOPTS) -o binarysearch_test binarysearch_test.o binarysearch.o $(UNITY_OBJECTS)

test: $(BINSEARCH_TEST)
	./$(BINSEARCH_TEST)

clean:
	rm $(OBJECTS) || true
	rm $(TEST_BINS) || true
	rm $(BINSEARCH_TEST_OBJECTS) || true
