CPP = g++ 
FLAGS = -O5 -Wall -W
RM  = rm -f
EXEC = testProg1 

OBJECTS = \
	 q1.o \

all: $(OBJECTS) compile touch 


q1.o : q1.cpp
			   		 $(CPP) $(FLAGS) -c q1.cpp
clean:  
					 $(RM) $(OBJECTS) $(EXEC) 

compile: 
					 $(CPP) $(FLAGS) $(OBJECTS) -o $(EXEC) 

touch:
					 @echo " "
					 @echo "Compilation done successfully..................."
					 @echo 
