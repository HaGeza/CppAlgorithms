SRCDIR := src
BUILDDIR := target
SRCS := $(wildcard $(SRCDIR)/*.cpp)
OBJS := $(SRCS:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)
EXES := $(SRCS:$(SRCDIR)/%.cpp=$(BUILDDIR)/%)

# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17

# Default target to build all executables
all: $(EXES)

# Mark object files as secondary to prevent them from being deleted
.SECONDARY: $(OBJS)

# Rule to build each executable
$(BUILDDIR)/%: $(BUILDDIR)/%.o
	$(CXX) $(CXXFLAGS) -o $@ $<

# Rule to compile each source file into an object file
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create the build directory if it doesn't exist
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Phony target to clean up the build directory
# clean:
# 	rm -rf $(BUILDDIR)

# Phony target to run individiaual executables
run-%: $(BUILDDIR)/%
	./$<

# Phony targets
.PHONY: all run-%
