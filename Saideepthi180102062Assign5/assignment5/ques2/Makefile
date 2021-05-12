CPP = g++ 
FLAGS = -O5 -Wall -W
RM  = rm -f
EXEC = testProg1 

OBJECTS = \
	 q2.o \

all: $(OBJECTS) compile touch 


q2.o : q2.cpp
			   		 $(CPP) $(FLAGS) -c q2.cpp
clean:  
					 $(RM) $(OBJECTS) $(EXEC) 

compile: 
					 $(CPP) $(FLAGS) $(OBJECTS) -o $(EXEC) 

touch:
					 @echo " "
					 @echo "Compilation done successfully..................."
					 @echo 
