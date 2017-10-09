# Tools
RM = rm -rf
MKDIR = mkdir -p

# Files
BIN = server

CXXFILES = src/main.cpp

OBJS = $(CXXFILES:.cpp=.o)

# Options
CXXFLAGS = -ggdb
LDFLAGS = -lpthread

$(BIN): $(OBJS)
	$(CXX) -o $(BIN) $(OBJS) $(LDFLAGS)

all: $(BIN)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(BIN)

re: fclean all

.PHONY: re fclean clean