//Name : Piruntha Devi A/P Moganadas
//Matric No : 153210
//Assignment 2 (CPT111)

//This program demonstrates quiz on area of shapes
#include<fstream>
#include<iomanip>
#include<string>
#include<iostream>

using namespace std;

//function prototypes
bool isID(string);
int user(string ,string [],int&  ,int [],int [],int[], int &);
void addUser(string [], string , int &, int [],int [], int [], int &);
void quizTriangle(int[],int[],int[],int,string &,int &,int [],string [], int &);
void quizRectangle(int[],int[],int[],int,string &,int &,int[],string [], int &);
void quizParallelogram(int[],int[],int[],int,string &, int &,int[],string [], int &);
void outputFile(string [], int,int[],int[],int[],int);

//main function
int main()
{
    cout << "\t\t***WELCOME TO THE MATHS CLASS***" << endl << endl;
    cout << "There are three formulas that need to be known in finding the area of shapes:" << endl;
    cout << "_____________________________" << endl;
    cout << "TRIANGLE      | A = 1/2*b*h  " << endl;
	cout << "RECTANGLE     | A = l*w      " << endl;
	cout << "PARALLELOGRAM | A = b*h      " << endl;
	cout << "_____________________________" << endl;
    cout << "Make sure you have revised the formulas properly before attempting the quizzes! " << endl;
	cout << endl;
	
	//declaration of variables
	int index = 0;
	int i = 0;
	int SIZE = 25; //initialize the size of array
	string stu_ID[SIZE] = {" "}; //initialize content in siaze of array
	
	//declaration of variables
	int choice,choice2;
    int arrayT[SIZE] = {-1}; //initialize content in size of array scores of triangle
    int arrayR[SIZE] = {-1}; //initialize content in size of array scores of rectangle
    int arrayP[SIZE] = {-1}; //initialize content in size of array scores of parallelogram
    
	//initialization of variable for quiz score of shapes
    int score_Tri = 0; 
	int score_Rec = 0; 
	int score_Par = 0; 
	
	//declaration of variables
	int icount = 0;

    
	//keep executing the statements in loop until the user chose 8 
	while(choice2 != 8)
	{
		//declaration of variable studentID
	    string studentID = " ";
	    cout << endl;
	    cout << "Please enter student ID to proceed : ";
	    cin >> studentID; //user input studentID
	    
	    while (!isID(studentID)) //checking the validity of studentID
	    {
	    	cout << endl;
		    cout << "INVALID STUDENT ID / 6 digits only!" << endl;
		    cout << "Retype STUDENT ID: ";
		    cin.clear();
		    cin >> studentID; //user input studentID again
	    }
	
	    user(studentID,  stu_ID,  icount,  arrayT, arrayR, arrayP,index);//call user function
	    
        //user Menu
		cout << "\n\t|LEARNING ABOUT AREA OF SHAPES|\t\n" << endl;
		
		cout << "||||||||||||||||||||||||" <<endl;
		cout << "1) TRIANGLE" << endl;
		cout << "2) RECTANGLE"  << endl;
		cout << "3) PARALLELOGRAM" << endl;
		cout << "4) QUIT" << endl;
		cout << "||||||||||||||||||||||||" << endl;
		cout << "Select a choice : ";
		cin >> choice; //user input choice
		cout << endl;
		while(choice < 1 || choice > 4) //if expression true then following statements executed
		{
			cout << "Your choice must be (1-4)" << endl;
			cout << "What is your choice: ";
			cin >> choice; //user input choice again
		}    
		
		//switch cases based on user's choice
	    switch(choice)
	    {
		    case 1:
			{
				//declaration variables
				int *ptr; 
	            int area[SIZE]; 
	            int base[SIZE]; 
	            int height[SIZE]; 
	            ptr = area;
	            ptr = base;  
	            ptr = height; 
	            int count = 0; 
	            int i = 0; 
	            
	            //checking whether the quiz of triangle taken
	            if (arrayT[index] != -1) //if taken following statements executed
	            {
	            	cout << "You've attempted quiz TRIANGLE! Choose RECTANGLE/PARALLELOGRAM" << endl;
				}
				else //else read text file of triangle
				{
					
	            //read data from text file
	            ifstream inputFile;
	            string filename;
	            
	            //process to read data from text file into array
	            while(true) //while  the file is exist
	            { 
	                	cout << endl;
		            	inputFile.open("Triangle.txt"); //open text file
		
			            if(inputFile) //if infile is true
			            { 
				            while(!inputFile.eof()) //while infile not eof yet
				            { 
				                inputFile >> area[i] >> base[i] >> height[i]; //read data from text file
		        	            i++; //increment number of data
		        	            count = i; //assign i to variable count
				            }
				            inputFile.close();//close the file
				            break;
		                }	
		            	else 
		            	{
				            cout<<"Error opening file"<<endl;	//if the text file not found
				            inputFile.clear(); //clear earlier entry
				            continue;
		            	}
	            }
				
               	quizTriangle(area,base,height,SIZE,studentID,score_Tri,arrayT,stu_ID, index);//call quizTriangle function
	       	 	}
	            break;
	        }
		
		    case 2:
			{
				//declaration of variables
				int *ptr;
	            int area[SIZE];
	            int width[SIZE];
	            int length[SIZE];
	            ptr = area;
	            ptr = width;
	            ptr = length;
	            int count = 0; 
	            int i = 0;
	            
	            //checking whether quiz of rectangle taken
	            if (arrayR[index] != -1) //if taken following statements executed
	            {
	            	cout << "You've attempted quiz RECTANGLE! Choose TRIANGLE/PARALLELOGRAM" << endl;
				}
				else
				{
					
	            //read data from text file
	            ifstream inputFile;
	            string filename;
	            
	            //process to read data from text file into array
	            while(true) //while  the file is exist
	            { 
	                cout << endl;
		            inputFile.open("Rectangle.txt"); //open text file
		            
		            if(inputFile) //if infile is true
		            { 
			            while(!inputFile.eof()) //while infile not eof yet
			            { 
			                inputFile >> area[i] >> width[i] >> length[i]; //read data from text file
	        	            i++; //increment number of data
	        	            count = i; //assign i to variable count
			            }
			            inputFile.close();//close the file
			            break;
	                }	
		            else 
		            {
			            cout<<"Error opening file"<<endl;	//if the text file not found
			            inputFile.clear(); //clear earlier entry
			            continue;
		            }
	            }
	        
                quizRectangle(area,width,length,SIZE,studentID,score_Rec,arrayR,stu_ID,index); //call quizRectangle function
			    }
				break;
	            
			}
		
		    case 3:
			{
				//declaration of varaiables
				int *ptr;
	            int area[SIZE];
	            int base[SIZE];
	            int height[SIZE];
	            ptr = area;
	            ptr = base;
	            ptr = height;
	            int count = 0; 
	            int i = 0;
	            
	            //checking whether quiz of parallelogram taken
	            if (arrayP[index] != -1) //if taken following statemets executed
	            {
	            	cout << "You've attempted quiz PARALLELOGRAM! Choose TRIANGLE/RECTANGLE" << endl;
				}
				else
				{
	            
	            //read data from text file
	            ifstream inputFile;
	            string filename;
	 			
	            inputFile.open("Parallelogram.txt"); //open text file
	
	            if(inputFile) //if infile is true
	            { 
		            while(!inputFile.eof()) //while infile not eof yet
		            { 
		                inputFile >> area[i] >> base[i] >> height[i]; //read data from text file
        	            i++; //increment number of data
        	            count = i; //assign i to variable count
		            }
		            inputFile.close();//close the file		          
                }	
	            else 
	            {
		            cout<<"Error opening file"<<endl;	//if the text file not found
		            inputFile.clear(); //clear earlier entry		   
	            }
	  
	            quizParallelogram(area,base,height,SIZE,studentID,score_Par,arrayP,stu_ID,index);//call quizParallelogram function
			    }
				break;
			}
			case 4:
			{
				outputFile(stu_ID,SIZE,arrayT,arrayR,arrayP, icount); //call outputFile function
				break;
			}
			default:
				cout << "Choose 1 - 4 only" <<endl;
				continue;
				break;
			
	    }
	    cout << endl;
	    cout << "Do you want to continue? Press [1-MENU] [8-EXIT] : ";
	    cin >> choice2; //user input choice2
	    while(choice2 == 8)
	    {
		    break;
	    }
    }
    cout << endl;
    cout << "***Thank you for attempting the quiz on area of shapes***" <<endl;	
    outputFile(stu_ID,SIZE,arrayT,arrayR,arrayP, icount); //call outputFile function
	return 0;
}

//function header for isID
bool isID(string id)
{
	for(int i=0; i<id.length(); i++) 
	{
		if (isdigit(id[i]) == false) //if the ID in digit return false
		{
			return false;
		}
	}
	if (id.size() != 6){ //if the size not equals to 6 return false
		return false;
	}
return true;
}

//function header for user
int user(string studentID, string stu_ID[], int &count, int arrayT[],int arrayR[], int arrayP[], int &index)
{
	bool find=false;
	for(int i=0; i<count; i++) 
	{
		if (stu_ID[i] == studentID) //checking whether student ID exist  
		{
			cout << endl;
			cout<<"STUDENT ID EXIST"<<endl;
			index = i;
			find=true;
			break;
		}	
	}
	
	if(!find) //if the student ID not found then execute following statements
	{
		cout << endl;
		cout << "Welcome to our system NEW USER!" << endl;
		cout << "You can attempt any quiz of shapes!" << endl;
		addUser( stu_ID, studentID, count, arrayT, arrayR, arrayP, index); //call adduser function
		//pass id index to all until finish all function
	}
return index;
}

//function header for addUser
void addUser(string stu_ID[], string studentID, int &count, int arrayT[],int arrayR[], int arrayP[], int &index)
{	

    stu_ID[count] = studentID;
	arrayT[count] = -1; //initialize the score of triangle to -1
	arrayR[count] = -1; //initialize the score of rectangle to -1
	arrayP[count] = -1; //initialize the score of parallelogram to -1
	index = count;
	count = count + 1;
}

//function header for quizTriangle
void quizTriangle(int area[],int base[],int height[],int SIZE,string& studentID,int &score_Tri,int arrayT[],string stu_ID[], int &index)
{
	system("pause");
	system("cls");
	//declaration of variables
	int answer;
	int marksSec1 = 0, marksSec2 = 0, marksSec3 = 0;
	
	cout << "Let's test your knowledge in area of shapes!!!" << endl;
    cout << endl;
    cout << "Try to answer the quiz below!" << endl;
    cout << endl;
	
	cout << "\t||SECTION 1||\t" << endl << endl;
	cout << "Given the base(b) and height(h) of triangle." << endl;
	cout << "Find the area(A) using formula A = (1/2 * b * h)" << endl << endl;
	
	for(int j = 0; j < 4; j++) //for first four rows in text file
	{
		cout << "|Base| = " << base[j] << "\t|Height| = " << height[j] << endl;
		cout << "|Area| = " ;
		cin >> answer; ///user input answer
		cout << endl;
		if(answer == area[j]) //if answer input by user equals to value in text file
	    {
	        cout << "Congratulations! It's correct." << endl;
	    	cout << "You got 1 marks!" << endl;
	    	cout << endl;
	    	marksSec1 += 1.0; //add 1.0 marks to marksSec1 if user answer the question correctly
	    }
	    else
		{
		    cout << "Sorry! It's incorrect." << endl;
			cout << "The correct answer is " << area[j] << endl; //display correct answer
			cout << endl;
		}
	}
	cout << "\t||SECTION 2||\t" << endl << endl;
	cout << "Given the base(b) and area(A) of triangle." << endl;
	cout << "Find the height(h) using formula A = (1/2 * b * h)" << endl << endl;
	
	for(int j = 4; j < 8; j++) //for second four rows in text file
	{
		cout << "|Base| = " << base[j] << "\t|Area| = " << area[j] << endl;
		cout << "|Height| = " ;
		cin >> answer; //user input answer 
		cout << endl;
		if(answer == height[j]) //if answer input by user equals to value in text file
	    {
	        cout << "Congratulations! It's correct." << endl;
	    	cout << "You got 1 marks!" << endl;
	    	cout << endl;
	    	marksSec2 += 1.0; //add 1.0 marks to marksSec2 if user answer the question correctly
	    }
	    else
		{
		    cout << "Sorry! It's incorrect." << endl;
			cout << "The correct answer is " << height[j] << endl; //display correct answer
			cout << endl;
		}
	}
		
	cout << "\t||SECTION 3||\t" << endl << endl;
	cout << "Given the area(A) and height(h) of triangle." << endl;
	cout << "Find the base(b) using formula A = (1/2 * b * h)" << endl << endl;
	
	for(int j = 8; j < 12; j++) //for third four rows of text file
	{
		cout << "|Area| = " << area[j] << "\t|Height| = " << height[j] << endl;
		cout << "|Base| = " ;
		cin >> answer; //user input answer 
		cout << endl;
		if(answer == base[j]) //if answer input by user equals to value in text file
	    {
	        cout << "Congratulations! It's correct." << endl;
	    	cout << "You got 1 marks!" << endl;
	    	cout << endl;
	    	marksSec3 += 1.0; //add 1.0 marks to marksSec3 if user answer the question correctly
	    }
	    else
		{
		    cout << "Sorry! It's incorrect." << endl;
			cout << "The correct answer is " << base[j] << endl; //display correct answer
			cout << endl;
		}
	}
    
    score_Tri = marksSec1 + marksSec2 + marksSec3; //sum up the total marks in each section and assign to score_Tri
    arrayT[index] = score_Tri; //score_Tri is strored in array
	cout << "Total Marks For Quiz Of Triangle = " << arrayT[index] << endl; //display the total marks for triangle
}

//function header for quizRectangle
void quizRectangle(int area[],int width[],int length[],int SIZE,string &studentID,int &score_Rec,int arrayR[],string stu_ID[],int &index)
{
	system("pause");
	system("cls");
	//declaration of variables
	int answer;
	int marksSec1 = 0, marksSec2 = 0, marksSec3 = 0;
	
	cout << "Let's test your knowledge in area of shapes!!!" << endl;
    cout << endl;
    cout << "Try to answer the quiz below!" << endl;
    cout << endl;
	
	cout << "\t||SECTION 1||\t" << endl << endl;
	cout << "Given the width(w) and length(l) of rectangle." << endl;
	cout << "Find the area(A) using formula A = (l * w)" << endl << endl;
	
	for(int j = 0; j < 4; j++) //for first four rows of text file
	{
		cout << "|Width| = " << width[j] << "\t|Length| = " << length[j] << endl;
		cout << "|Area| = " ;
		cin >> answer; //user input answer 
		cout << endl;
		if(answer == area[j]) //if answer input by user equals to value in text file
	    {
	        cout << "Congratulations! It's correct." << endl;
	    	cout << "You got 1 marks!" << endl;
	    	cout << endl;
	    	marksSec1 += 1.0; //add 1.0 marks to marksSec1 if user answer the question correctly
	    }
	    else
		{
		    cout << "Sorry! It's incorrect." << endl;
			cout << "The correct answer is " << area[j] << endl; //display correct answer
			cout << endl;
		}
	}
	cout << "\t||SECTION 2||\t" << endl << endl;
	cout << "Given the width(w) and area(A) of rectangle." << endl;
	cout << "Find the length(l) using formula A = (l * w)" << endl << endl;
	
	for(int j = 4; j < 8; j++) //for second four rows of text file
	{
		cout << "|Width| = " << width[j] << "\t|Area| = " << area[j] << endl;
		cout << "|Length| = " ;
		cin >> answer; //user input answer
		cout << endl;
		if(answer == length[j]) //if answer input by user equals to value in text file
	    {
	        cout << "Congratulations! It's correct." << endl;
	    	cout << "You got 1 marks!" << endl;
	    	cout << endl;
	    	marksSec2 += 1.0; //add 1.0 marks to marksSec2 if user answer the question correctly
	    }
	    else
		{
		    cout << "Sorry! It's incorrect." << endl;
			cout << "The correct answer is " << length[j] << endl; //display correct answer
			cout << endl;
		}
	}
		
	cout << "\t||SECTION 3||\t" << endl << endl;
	cout << "Given the area(A) and length(l) of rectangle." << endl;
	cout << "Find the width(w) using formula A = (l * w)" << endl << endl;
	
	for(int j = 8; j < 12; j++) //for third four rows of text file
	{
		cout << "|Area| = " << area[j] << "\t|Length| = " << length[j] << endl;
		cout << "|Width| = " ;
		cin >> answer; //user input answer
		cout << endl;
		if(answer == width[j]) //if answer input by user equals to value in text file
	    {
	        cout << "Congratulations! It's correct." << endl;
	    	cout << "You got 1 marks!" << endl;
	    	cout << endl;
	    	marksSec3 += 1.0; //add 1.0 marks to marksSec3 if user answer the question correctly
	    }
	    else
		{
		    cout << "Sorry! It's incorrect." << endl;
			cout << "The correct answer is " << width[j] << endl; //display correct answer
			cout << endl;
		}
	}
    
    score_Rec = marksSec1 + marksSec2 + marksSec3; //sum up the total marks in each section and assign to score_Rec
    arrayR[index] = score_Rec;  //score_Rec is strored in array
    cout << "Total Marks For Quiz Of Rectangle = " << arrayR[index] << endl; //display the total marks for rectangle

}

//function header for quizParallelogram
void quizParallelogram(int area[],int base[],int height[],int SIZE,string &studentID, int &score_Par,int arrayP[],string stu_ID[], int &index)
{
	system("pause");
	system("cls");
	int answer;
	int marksSec1 = 0, marksSec2 = 0, marksSec3 = 0;
	
	cout << "Let's test your knowledge in area of shapes!!!" << endl;
    cout << endl;
    cout << "Try to answer the quiz below!" << endl;
    cout << endl;
	
	cout << "\t||SECTION 1||\t" << endl << endl;
	cout << "Given the base(b) and height(h) of parallelogram." << endl;
	cout << "Find the area(A) using formula A = (b * h)" << endl << endl;
	
	for(int j = 0; j < 4; j++) //for first four rows of text file
	{
		cout << "|Base| = " << base[j] << "\t|Height| = " << height[j] << endl;
		cout << "|Area| = " ;
		cin >> answer; //user input answer
		cout << endl;
		if(answer == area[j]) //if answer input by user equals to value in text file
	    {
	        cout << "Congratulations! It's correct." << endl;
	    	cout << "You got 1 marks!" << endl;
	    	cout << endl;
	    	marksSec1 += 1.0; //add 1.0 marks to marksSec1 if user answer the question correctly
	    }
	    else
		{
		    cout << "Sorry! It's incorrect." << endl;
			cout << "The correct answer is " << area[j] << endl; //display correct answer
			cout << endl;
		}
	}
	cout << "\t|SECTION 2|\t" << endl << endl;
	cout << "Given the base(b) and area(A) of parallelogram." << endl;
	cout << "Find the height(h) using formula A = (b * h)" << endl << endl;
	
	for(int j = 4; j < 8; j++) //for second four rows of text file
	{
		cout << "|Base| = " << base[j] << "\t|Area| = " << area[j] << endl;
		cout << "|Height| = " ;
		cin >> answer; //user input answer
		cout << endl;
		if(answer == height[j]) //if answer input by user equals to value in text file
	    {
	        cout << "Congratulations! It's correct." << endl;
	    	cout << "You got 1 marks!" << endl;
	    	cout << endl;
	    	marksSec2 += 1.0; //add 1.0 marks to marksSec2 if user answer the question correctly
	    }
	    else
		{
		    cout << "Sorry! It's incorrect." << endl;
			cout << "The correct answer is " << height[j] << endl; //display correct answer
			cout << endl;
		}
	}
		
	cout << "\t||SECTION 3||\t" << endl << endl;
	cout << "Given the area(A) and height(h) of parallelogram." << endl;
	cout << "Find the base(b) using formula A = (b * h)" << endl << endl;
	
	for(int j = 8; j < 12; j++) //for third four rows of text file
	{
		cout << "|Area| = " << area[j] << "\t|Height| = " << height[j] << endl;
		cout << "|Base| = " ;
		cin >> answer; //user input answer
		cout << endl;
		if(answer == base[j]) //if answer input by user equals to value in text file
	    {
	        cout << "Congratulations! It's correct." << endl;
	    	cout << "You got 1 marks!" << endl;
	    	cout << endl;
	    	marksSec3 += 1.0; //add 1.0 marks to marksSec3 if user answer the question correctly
	    }
	    else
		{
		    cout << "Sorry! It's incorrect." << endl;
			cout << "The correct answer is " << base[j] << endl; //display correct answer
			cout << endl;
		}
	}
    
    score_Par = marksSec1 + marksSec2 + marksSec3; //sum up the total marks in each section and assign to score_Par
    arrayP[index] = score_Par;  //score_Par is strored in array
    cout << "Total Marks For Quiz Of Parallelogram = " << arrayP[index]<< endl; //display the total marks for parallelogram
	
}

//function header for outputFile
void outputFile(string stu_ID[], int SIZE,int arrayT[],int arrayR[],int arrayP[], int icount)
{
	system("pause");
	//declaration of variables
	
	ofstream outputfile;
	outputfile.open("studentMarks.txt", ios::out | ios::trunc ); //to delete currrent data, replace with new data
	
    if(outputfile) 
	{
		
		for(int i = 0; i < icount; i++)
		{
			cout << "Tranfering data..." << endl;
			outputfile << stu_ID[i] << "\t\t" << arrayT[i] << "\t" << arrayR[i] << "\t" << arrayP[i] << endl; //display the studentID and totalMarks
		}
	}
	else // else following statement executed
	{
		cout << "No data transferred" << endl;
	}
    outputfile.close();
	system("pause");
	//close the file
}

