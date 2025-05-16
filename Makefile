MAIN = templates/main.cpp
TASK = a b c d e f g

clean :
	rm -f a.cpp b.cpp c.cpp d.cpp e.cpp f.cpp g.cpp
	rm -f ./a.out ans.txt

new : clean
	for t in $(TASK); do cp $(MAIN) $$t.cpp; done

%:
	c++ $@.cpp && ./a.out > ans.txt && cat ans.txt
