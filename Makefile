TARGETS = main.cpp network/client/*
OUTPUT = -o build/chatClient
INCLUDES = -I/usr/include/boost
DEPS = -lboost_system
FLAGS = -w -pthread
CC = g++

all : $(OBJS)
	$(CC) $(TARGETS) $(FLAGS) $(INCLUDES) $(DEPS) $(OUTPUT)
