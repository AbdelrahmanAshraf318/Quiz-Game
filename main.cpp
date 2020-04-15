#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <iterator>
#include <string.h>
#include <cstring>
#include <stdio.h>
using namespace std;

char letters[4]={'a','b','c','d'};


fstream myfile("exam_questions.txt");
fstream choices("Choices.txt");//Right Answer
//vector<string>newquestions;
vector <string> CopyQuestionsOfFile;
vector <string> QuestionsOfFile;
vector <string>choice;//Right Answers in Exam Questions file

vector <string>NewQuestion;
vector<string>choice2;//for the right answer which will take it from the user

///////////////////////////////////////////////
/*Administration Menu*/

void ViewAllQuestions(vector <string> NewQuestion)
{
    cout<<"Number of Questions available: "<<(NewQuestion.size()/4)<<endl;
    cout<<"**************************************** \n";
    cout<<"Questions List \n";
    cout<<"************** \n";
    int counter1=0;//for letters
    int counter2=0;//for no questions
    int counter3=0;//for choices
    for(int i=0 ; i<NewQuestion.size() ; i++)
    {
        if(i%5==0)
        {
            cout<<endl;
            cout<<"**************************************************** \n";
            cout<<endl;
            cout<<counter2+1<<")"<<NewQuestion[i]<<endl;
            cout<<endl;
            counter2++;
            counter1=0;
        }
        else
        {
           if(NewQuestion[i]==choice2[counter3])
           {
               cout<<"*"<<letters[counter1]<<")"<<NewQuestion[i]<<"   ";
               counter1++;
               counter3++;
           }
           else
           {
               cout<<letters[counter1]<<")"<<NewQuestion[i]<<"   ";
               counter1++;
           }
        }
    }
}
//int NewSize=CopyQuestionsOfFile.size()+5;
void AddNewQuestions(string Newquestion)
{
    NewQuestion.push_back(Newquestion);
}

void TakeChoices(string schoices)
{
    NewQuestion.push_back(schoices);
}

void DeleteQuestion(int ID)
{
    int r=(ID*5)-5;
    for(int i=0 ; i<NewQuestion.size() ; i++)
    {
        if(r==i)
        {
            NewQuestion.erase(NewQuestion.begin()+i);
            choice2.erase(choice2.begin()+i);
            for(int i=r+1 ; i<=r+5 ; i++)
            {
                NewQuestion.erase(NewQuestion.begin()+i);
            }
            break;
        }
    }
}


void LoadFromFile(string FileName)
{
    ofstream FileFromUser;
    FileFromUser.open( FileName.c_str() );
    for(int i=0 ; i<NewQuestion.size() ; i++)
    {
        FileFromUser<<NewQuestion[i]<<endl;
    }
    for(int i=0 ; i<NewQuestion.size() ; i++)
    {
        while(myfile.eof())
        {
          myfile<<endl;
          myfile<<NewQuestion[i];
       }
    }
    for(int i=0 ; i<choice2.size() ; i++)
    {
        while(choices.eof())
        {
            choices<<endl;
            choices<<choice2[i];
        }
    }
    if(FileFromUser.is_open())
    {
        cout<<"The file has been created successfully"<<endl;
    }
    else
    {
        cout<<"Created is failed \n";
    }
}

string UserName="USER";

int main()
{
    string inputstring;
    string input;
    if(myfile.is_open())
    {
        while(getline(myfile,inputstring))
        {
            QuestionsOfFile.push_back(inputstring);
            CopyQuestionsOfFile.push_back(inputstring);
        }
    }
    else
    {
        cout<<"Sorry,The file does not exist \n";
    }
    if(choices.is_open())
    {
        while(getline(choices,input))
        {
            choice.push_back(input);
        }
    }
    /*string Newquestion , CorrectAnswer;
    string schoices;
    string answer;
    int k=0;
    do
    {
        cout<<"Enter the question: ";
        getline(cin,Newquestion);
        AddNewQuestions(Newquestion);
        do
        {
            cout<<"Enter choice number "<<k+1<<" :";
            getline(cin,schoices);
             TakeChoices(schoices);
            k++;
        }while(k<4);
        cout<<"Enter the correct choice: ";
        getline(cin,CorrectAnswer);
        choice.push_back(CorrectAnswer);
        cout<<"Do you want to Enter another Question?"<<endl;
        cin>>answer;
    }while(answer=="Yes"||answer=="yes");
    ViewAllQuestions(NewQuestion);
    cout<<endl;
    for(int i=0 ; i<choice.size() ; i++)
    {
        cout<<choice[i]<<endl;
    }*/
    /////////////////////////////
      /*ofstream f;
     string filename;

     cout << "Please enter a file name to write: ";
     getline( cin, filename );

     f.open( filename.c_str() );
     f << "Hello world!\n";
     f.close();*/
     cout<<"Welcome "<<UserName<<",please choose from the following options: ";
     int choose;
     cout<<"[1]Go to administration menu \n";
     cout<<"[2] Update your name \n";
     cout<<"[3] Start a new quiz \n";
     cout<<"[4] Display your scores statistics \n";
     cout<<"[5] Display all your scores \n";
     cout<<"[6] Exit \n";
    return 0;
}
