
#include<iostream>
#include<fstream>
#include<cstring>
#include<conio.h>
using namespace std;

class Student
{
private:
    int roll_no;
    char name[20];
    int marks;

public:
    Student()
    {
        roll_no = 0;
        strcpy(name,"");
        marks = 0;
    }
    void setStudentData()
    {
        cout<<"\t\t\t\t Enter RollNo of student : ";
        cin>>roll_no;
        cout<<"\t\t\t\t Enter name of student : ";
        cin.ignore();
        cin.getline(name,20);
        cout<<"\t\t\t\t Enter Marks of student : ";
        cin>>marks;

        if(marks<0 || marks>100)
        {
            throw "Marks must be between 0 and 100!";
        }
    }
    void displayStudentData()
    {
        cout<<"\t\t--------------------------------------------------------------"<<endl;
        cout<<"\t\t\t\t RollNo of student is : "<<roll_no<<endl;
        cout<<"\t\t\t\t Name of student is : "<<name<<endl;
        cout<<"\t\t\t\t Marks of student is : "<<marks<<endl;
    }
    int getRollNo()
    {
        return roll_no;
    }
    int getMarks()
    {
        return marks;
    }
};
int main()
{
    int choice;

    do
    {
        system("cls");
        cout<<"\n\t\t--------------------------------------------------------------"<<endl;
        cout<<"\t\t\t\t STUDENT MANAGEMENT SYSTEM"<<endl;
        cout<<"\t\t--------------------------------------------------------------"<<endl;
        cout<<"\t\t\t\t 1. Insert Student Data"<<endl;
        cout<<"\t\t\t\t 2. Display Student Data"<<endl;
        cout<<"\t\t\t\t 3. Search Student Data"<<endl;
        cout<<"\t\t\t\t 4. Delete Student Data"<<endl;
        cout<<"\t\t\t\t 5. Update Student Data"<<endl;
        cout<<"\t\t\t\t 6. Highest Marks"<<endl;
        cout<<"\t\t\t\t 7. Exit"<<endl;
        cout<<"Enter Your Choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
        {
            try
            {
                Student s;
                s.setStudentData();

                ofstream ofs;
                ofs.open("student.txt",ios::app|ios::binary);


                ofs.write((char*)&s,sizeof(s));
                ofs.close();

                cout<<"\tRecord Inserted Successfully"<<endl;
            }
            catch(const char* msg)
            {
                cout<<"\t Error:"<<msg<<endl;
            }
            cout<<"\tEnter any key to continue!!!"<<endl;
            getch();
            break;
        }
        case 2:
        {
            Student s;

            ifstream ifs;
            //Exception Handling
            try
            {
                ifs.open("student.txt");

                if(!ifs)
                {
                    throw "File could not be opened!";
                }
            }
            catch(const char* msg)
            {
                cout<<"\t Error:"<<msg<<endl;
                getch();
                break;
            }
            while(ifs.read((char*)&s,sizeof(s)))
            {
                s.displayStudentData();
            }
            ifs.close();
            cout<<"\tEnter any key to continue!!!"<<endl;
            getch();
            break;
        }
        case 3:
        {

            Student s;

            ifstream ifs;
            //Exception Handling
            try
            {
                ifs.open("student.txt");

                if(!ifs)
                {
                    throw "File could not be opened!";
                }
            }
            catch(const char* msg)
            {
                cout<<"\t Error:"<<msg<<endl;
                getch();
                break;
            }
            int rno;
            cout<<"\t Enter RollNo to Search Student Record : ";
            cin>>rno;

            bool found = false;
            while(ifs.read((char*)&s,sizeof(s)))
            {
                if(s.getRollNo() == rno)
                {
                    s.displayStudentData();
                    found = true;
                }

            }
            ifs.close();
            if(found==false)
            {
                cout<<"\t Student Not found"<<endl;
            }
            cout<<"\tEnter any key to continue!!!"<<endl;
            getch();
            break;
        }
        case 4:
        {

            Student s;

            ifstream ifs;
            ifs.open("student.txt");

            ofstream ofs;
            ofs.open("temp.txt",ios::app|ios::binary);

            //Exception Handling
            try
            {

                if(!ifs)
                {
                    throw "File could not be opened!";
                }
            }
            catch(const char* msg)
            {
                cout<<"\t Error:"<<msg<<endl;
                getch();
                break;
            }

            int rno;
            cout<<"\t Enter RollNo to Delete Student Record : ";
            cin>>rno;

            bool found = false;
            while(ifs.read((char*)&s,sizeof(s)))
            {
                if(s.getRollNo() != rno)
                {
                    ofs.write((char*)&s,sizeof(s));
                }
                else
                {
                    found = true;
                }

            }
            ifs.close();
            ofs.close();

            remove("student.txt");
            rename("temp.txt","student.txt");

            if(found==false)
            {
                cout<<"\t Student Not found"<<endl;
            }
            else
            {
                cout<<"\t Student deleted successfully"<<endl;
            }
            cout<<"\tEnter any key to continue!!!"<<endl;
            getch();
            break;
        }
        case 5:
        {
            try
            {
                Student s;

                ifstream ifs;
                ifs.open("student.txt");

                ofstream ofs;
                ofs.open("temp.txt",ios::app|ios::binary);

                //Exception Handling
                try
                {

                    if(!ifs)
                    {
                        throw "File could not be opened!";
                    }
                }
                catch(const char* msg)
                {
                    cout<<"\t Error:"<<msg<<endl;
                    getch();
                    break;
                }

                int rno;
                cout<<"\t Enter RollNo to Update Student Record : ";
                cin>>rno;

                bool found = false;
                while(ifs.read((char*)&s,sizeof(s)))
                {
                    if(s.getRollNo() == rno)
                    {
                        cout<<"\t Enter New Data : "<<endl;
                        s.setStudentData();
                        found = true;
                    }
                    ofs.write((char*)&s,sizeof(s));


                }
                ifs.close();
                ofs.close();

                remove("student.txt");
                rename("temp.txt","student.txt");

                if(found==false)
                {
                    cout<<"\t Student Not found"<<endl;
                }
                else
                {
                    cout<<"\t Student updated successfully"<<endl;
                }
            }
            catch(const char* msg)
            {
                cout<<"\t Error:"<<msg<<endl;
            }
            cout<<"\tEnter any key to continue!!!"<<endl;
            getch();
            break;
        }
        case 6:
        {
            Student s;

            ifstream ifs;
            //Exception Handling
            try
            {
                ifs.open("student.txt");

                if(!ifs)
                {
                    throw "File could not be opened!";
                }
            }
            catch(const char* msg)
            {
                cout<<"\t Error:"<<msg<<endl;
                getch();
                break;
            }
            //find max marks
            int maxMarks = -1;
            while(ifs.read((char*)&s,sizeof(s)))
            {
                if(s.getMarks() > maxMarks)
                {
                    maxMarks = s.getMarks();
                }
            }
            ifs.close();

            ifstream ifs2;
            ifs2.open("student.txt");
            //display max marks student
            while(ifs2.read((char*)&s,sizeof(s)))
            {
                if(s.getMarks() == maxMarks)
                {
                    s.displayStudentData();
                }
            }
            ifs2.close();
            cout<<"\tEnter any key to continue!!!"<<endl;
            getch();
            break;
        }
        case 7:
        {
            cout<<"\n\t\t--------------------------------------------------------------"<<endl;
            cout<<"\t\t\t\t THANKS FOR VISITING OUR SYSTEM"<<endl;
            cout<<"\t\t--------------------------------------------------------------"<<endl;
            cout<<"\tEnter any key to continue!!!"<<endl;
            getch();
            exit(0);
            break;
        }
        default:
        {
            cout<<"\tInvalid choice!!!"<<endl;
            getch();
            break;
        }

        }
    }
    while(choice!=7);


    return 0;
}
