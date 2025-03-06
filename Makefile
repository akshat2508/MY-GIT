# # Compiler and flags
# CXX = g++
# CXXFLAGS = -std=c++17
# LDFLAGS = -lssl -lcrypto
# INCLUDES = -I/opt/homebrew/opt/openssl@3/include
# LIBS = -L/opt/homebrew/opt/openssl@3/lib

# # Source files
# # Add utils.cpp to the list of source files
# SRCS = src/main.cpp src/init.cpp src/add.cpp src/status.cpp src/commit.cpp src/log.cpp src/utils.cpp

# # Object files
# OBJS = $(SRCS:.cpp=.o)

# # Output binary
# TARGET = mygit

# # All target to build the project
# all: $(TARGET)

# # Compile the program
# $(TARGET): $(OBJS)
# 	$(CXX) $(OBJS) -o $(TARGET) $(INCLUDES) $(LIBS) $(LDFLAGS)

# # Compile each source file
# %.o: %.cpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# # Clean up object files and binaries
# clean:
# 	rm -f $(OBJS) $(TARGET)

# # Force rebuild
# rebuild: clean all










# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17
LDFLAGS = -lssl -lcrypto
INCLUDES = -I/opt/homebrew/opt/openssl@3/include
LIBS = -L/opt/homebrew/opt/openssl@3/lib

# Source files
# Added checkout.cpp to the list of source files
SRCS = src/main.cpp src/init.cpp src/add.cpp src/status.cpp src/commit.cpp src/log.cpp src/utils.cpp src/checkout.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Output binary
TARGET = mygit

# All target to build the project
all: $(TARGET)

# Compile the program
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(INCLUDES) $(LIBS) $(LDFLAGS)

# Compile each source file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and binaries
clean:
	rm -f $(OBJS) $(TARGET)

# Force rebuild
rebuild: clean all
