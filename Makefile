MAIN = templates/main.cpp
TASK = a b c d e f g

clean :
	find . -maxdepth 1 -type f ! -name Makefile -exec rm -f {} +

new : clean
	for t in $(TASK); do cp $(MAIN) $$t.cpp; done

%:
	c++ $@.cpp && ./a.out > ans.txt && cat ans.txt
