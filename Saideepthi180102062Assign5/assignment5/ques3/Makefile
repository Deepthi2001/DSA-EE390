CPP = g++ 
FLAGS = -O5 -Wall -W
RM  = rm -f
EXEC = testProg1 

OBJECTS = \
	 q3.o \

all: $(OBJECTS) compile touch 


q3.o : q3.cpp
			   		 $(CPP) $(FLAGS) -c q3.cpp
clean:  
					 $(RM) $(OBJECTS) $(EXEC) 

compile: 
					 $(CPP) $(FLAGS) $(OBJECTS) -o $(EXEC) 

touch:
					 @echo " "
					 @echo "Compilation done successfully..................."
					 @echo 
