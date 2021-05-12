# include "global.h"

void printfile(){

    ifstream f("myfile.txt"); 
    string line; 
    while(getline(f, line)){ 
        cout << line << '\n';
    } 
    
}

void replace(){
    string strReplace;
    cout<<"Enter the string to be replaced: ";
    cin>>strReplace;      //String to search 
    string strNew;
    cout<<"Enter the string to be replaced: ";
    cin>>strNew; 	//String To replace 
    ifstream filein("myfile.txt"); //File to read from 
    ofstream fileout("temp.txt");  //Temporary file 
    
    string strTemp; 
    bool found = false; 
    while(filein >> strTemp)  //it will check line from test to strTemp string 
     { 
        if(strTemp == strReplace)//if your word found then replace 
        { 
            strTemp = strNew; 
            found = true; 
        } 
        strTemp += ' '; 
        fileout << strTemp;//output everything to fileout(temp.txt) 
        //if(found) break; 
    } 
    if(found == false) cout<<"Word not found to replace.."<<endl;
    else{
       cout<<"Done replacing.."<<endl;
       rename("temp.txt", "myfile.txt");
       cout<<"Check myfile.txt for edited file"<<endl;
    }
   
}

void deleteline(const char *file_name){
       cout<<"-------Delete text in nth line-----"<<endl;
       cout<<"Enter n: ";
       int n;
       cin>>n;
	// open file in read mode or in mode
	ifstream is(file_name);

	// open file in write mode or out mode
	ofstream fileout;
	fileout.open("sample.txt", ofstream::out);

	// loop getting single characters
	char ch;
	int line_no = 1;
	while (is.get(ch))
	{
		// if a newline character
		if (ch == '\n')
		line_no++;

		// file content not to be deleted
		if (line_no != n)
			fileout << ch;
	}

	// closing output file
	fileout.close();

	// closing input file
	is.close();

	// remove the original file
	remove(file_name);

	// rename the file
	rename("sample.txt", file_name);
	cout<<"Deleted line "<<n<<endl;
}


void append(){
   cout<<"-------Append text-----"<<endl;
   string filename("myfile.txt");
   ofstream file_out;
   
   
  
    file_out.open(filename, std::ios_base::app);
    string quit = "n";
    string line;
    while (quit != "y") {
    cout << "Enter a line of text: ";
    getline(cin, line);
    file_out << line <<endl;
    cout << "Stop entering text (y/n)? ";
    getline(cin, quit);
  }
    
    cout << "Done appending.." << endl;
 
}
