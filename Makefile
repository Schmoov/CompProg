
clean :
	rm -f a.cpp b.cpp c.cpp d.cpp e.cpp f.cpp
	rm -f ./a.out ans.txt

new : clean
	cp t.cpp a.cpp && cp t.cpp b.cpp && cp t.cpp c.cpp && cp t.cpp d.cpp && cp t.cpp e.cpp && cp t.cpp f.cpp
%:
	c++ $@.cpp && ./a.out > ans.txt && cat ans.txt
