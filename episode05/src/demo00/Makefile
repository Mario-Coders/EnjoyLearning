CXX= g++ -std=c++17
CXXFLAGS= -g -O3 -Wall -Wextra -I.
LDFLAGS= -L.
LIBS= -pthread -lm -mavx2

ALL_T= main
ALL_O= main.o

RM= rm -rf

# Targets start here

t: $(ALL_T)

$(ALL_T): $(ALL_O)
	$(CXX) -o $@ $(LDFLAGS) $(ALL_O) $(LIBS)

clean:
	$(RM) $(ALL_T) $(ALL_O)

.PHONY: t clean

main.o: main.cc
