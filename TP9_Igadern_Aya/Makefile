CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGET = TP9_Igadern_aya
SRCS = main.cpp Account_Util.cpp Account.cpp Checking_Account.cpp Savings_Account.cpp Trust_Account.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del /f $(OBJS) $(TARGET).exe
