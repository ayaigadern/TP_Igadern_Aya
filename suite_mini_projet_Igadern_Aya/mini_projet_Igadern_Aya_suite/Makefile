CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra
SOURCES = Resource.cpp Container.cpp Pod.cpp Server.cpp KubernetesCluster.cpp Cloud_Util.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = suite

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean