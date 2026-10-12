CXXFLAGS = -std=c++17 -O2 -Wall -Wextra
TARGET   = coin_flip

$(TARGET): coin_flip.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: run clean

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
