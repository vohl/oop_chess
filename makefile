FILES :=    .travis.yml \
            Chess.h \
            Chess.c++ \
            RunChess.c++ \
            RunChess.out \
            TestChess.c++ \
            TestChess.out \

CXX := g++
CXXFLAGS := -pedantic -std=c++11 -Wall
LDFLAGS := -lgtest -lgtest_main -pthread

check:
	@not_found=0;                                 \
	for i in $(FILES);                            \
	do                                            \
		if [ -e $$i ];                            \
		then                                      \
			echo "$$i found";                     \
		else                                      \
			echo "$$i NOT FOUND";                 \
			not_found=`expr "$$not_found" + "1"`; \
		fi                                        \
	done;                                         \
	if [ $$not_found -ne 0 ];                     \
	then                                          \
		echo "$$not_found failures";              \
		exit 1;                                   \
	fi;                                           \
	echo "success";

clean:
	rm -f RunChess
	rm -f TestChess

config:
	git config -l

test: RunChess.out TestChess.out

RunChess: Chess.h Chess.c++ RunChess.c++
	$(CXX) $(CXXFLAGS) Chess.c++ RunChess.c++ -o RunChess

RunChess.out: RunChess
	./RunChess > RunChess.out

TestChess: Chess.h Chess.c++ TestChess.c++
	$(CXX) $(CXXFLAGS) Chess.c++ TestChess.c++ -o TestChess $(LDFLAGS)

TestChess.out: TestChess
	./TestChess > TestChess.out
	cat TestChess.out