pixel_engine:main.cpp
	g++ -o build/pixel_engine main.cpp Render-Engine.h Image-Converter.h -lm -lpthread -lX11 -lpng -Wall -Wextra

# CXX = g++
# CXXFLAGS = -Wall -Wextra -std=c++11
# LDFLAGS = -lm -lpthread -lX11 -lpng

# SOURCES = main.cpp
# HEADERS = Render-Engine.h Image-Converter.h
# OBJECTS = $(SOURCES:.cpp=.o)
# TARGET = build/pixel_engine

# all: $(TARGET)

# $(TARGET): $(OBJECTS)
# 	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS) $(LDFLAGS)

# %.o: %.cpp $(HEADERS)
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# clean:
# 	rm -f $(OBJECTS) $(TARGET)
