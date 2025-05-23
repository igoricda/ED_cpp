CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

# Arquivos fonte e de cabeçalho
SOURCES = tree.cpp arvore.cpp
HEADERS = arvore.h

# Nome do executável
TARGET = myavl

# Regras
all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)
