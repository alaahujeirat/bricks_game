CXX = g++
CC = $(CXX)

CPPFLAGS = -MMD -MP
CPPFLAGS += -I$(INC_DIR)

# c++ language
CXXFLAGS = -std=c++11
CXXFLAGS+= -Wall -pedantic
CXXFLAGS+= -Werror
CXXFLAGS+= -g3

LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

INC_DIR = ../inc/
SRC_DIR = ../src/

# dependencies:
DEPENDENCY1 = shape
DEPENDENCY2 = ball
DEPENDENCY3 = bricks
DEPENDENCY4 = bricks_base
DEPENDENCY5 = paddle
DEPENDENCY6 = game_manager
DEPENDENCY7 = level_manager
DEPENDENCY8 = screen_manager

TARGET = utest
OBJS = utest.o $(SRC_DIR)/$(DEPENDENCY1).o $(SRC_DIR)/$(DEPENDENCY2).o $(SRC_DIR)/$(DEPENDENCY3).o $(SRC_DIR)/$(DEPENDENCY4).o $(SRC_DIR)/$(DEPENDENCY5).o  $(SRC_DIR)/$(DEPENDENCY6).o $(SRC_DIR)/$(DEPENDENCY7).o $(SRC_DIR)/$(DEPENDENCY8).o

all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v

$(TARGET): $(OBJS)

vala: all
	valgrind ./$(TARGET)

clean:
	@$(RM) $(TARGET) $(OBJS) $(DEPENDS)

.PHONY: all check clean

utest.o: 

DEPENDS = $(OBJS:%.o=%.d)

-include $(DEPENDS)

