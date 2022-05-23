
NAME = timer

MAIN = example.cpp

HEADER = timer.hpp

all: $(NAME)

$(NAME): $(HEADER) $(MAIN)
	g++ $(MAIN) -o $(NAME)

clean:
	rm -f $(NAME)
