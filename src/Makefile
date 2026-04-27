# Hvb generic makefile

CXX = g++
CXXSTD = -std=c++17

hvb=

FLAGS = $(CXXSTD) -pedantic -Wall -g -I$(hvb) -O3 #-DDEBUG
LIBS = -llapack -lblas -lm 

HVBS = 

OBJECTS = 

objects: $(HVBS) $(OBJECTS)

%.o: %.cc
	$(CXX) -c $< $(FLAGS) -o $@

x%: x%.o objects
	$(CXX) $(FLAGS) -o $@ $< $(OBJECTS) $(HVBS) $(LIBS)
	

clean:
	ls x* | grep -v "\." | xargs rm -f
	rm -f *.o 

mrproper:
	rm -f *.o $(hvb)/*.o

