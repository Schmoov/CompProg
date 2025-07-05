MAIN = templates/main.cpp
LEET = templates/leet.cpp
TASK = a b c d e f g
QUES = q1 q2 q3 q4
FLAGS = -Wall -Wextra -pedantic -Wshadow

all:
	@

clean :
	find . -maxdepth 1 -type f ! -name Makefile -exec rm -f {} +

new : clean
	for t in $(TASK); do cp $(MAIN) $$t.cpp; done

leet : clean
	for t in $(QUES); do cp $(LEET) $$t.cpp; done

%:
	g++ $(FLAGS) $@.cpp && ./a.out > ans.txt && echo "~~~~~~~~~" && cat ans.txt

.PHONY: leet new clean
