#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include <fstream>

using namespace std;

    struct student
{
	char roll[10], name[30], fname[30];
	int sem, year;
    struct student *next;
	int dd, mm, yyyy;
	void display(student* temp)
	{
		cout<<setw(2)<<temp->dd<<"/"<<setw(2)<<temp->mm<<"/"<<setw(4)<<left<<temp->yyyy<<setw(10)<<left<<" ";
	}
	int getdetails();
    student* createnode();
    int show(student* temp);
    int checkrollno(char* b);
    void heading()
	{
		cout<<endl<<setw(10)<<left<<"Roll no."<<setw(30)<<left<<"Name"<<setw(30)<<left<<"Father's Name"<<setw(20)<<left<<"D.O.B"<<setw(15)<<left<<"Semester"<<setw(10)<<left<<"Year"<<endl;
        cout<<endl<<endl;
	}
}*headst;

student* student::createnode()
{
    struct student *n, *newn;
    if(headst == NULL)
    {
        newn = new(struct student);
        newn->next = NULL;
        headst = newn;
        headst->next = NULL;
        return newn;
    }
    else{
    n = headst;
    while(n->next !=NULL)
    {
        n = n->next;
    }
    newn = new(struct student);
    newn->next = NULL;
    n->next = newn;
    return newn;
    }
}

int student::checkrollno(char* b)
{
    string str = b;
    int flag = 0;
    struct student *rol;
    rol = headst;
    while(rol->next != NULL)
    {
        if(str.compare(rol->roll)==0)
        {
            flag = 1;
        }
        rol = rol->next;
    }
    if(flag == 1)
    {
        return 1;
    }
    else return 0;
}

int student::getdetails()
{
    struct student *temp, s;
    temp = createnode();
    char rolo[10];
	    cout<<"\nEnter roll no: "<<endl;
	    fflush(stdin);
	    gets(rolo);
	    if(s.checkrollno(rolo))
        {
            cout<<"\n\n\tRoll No. Already Exists...Enter Roll No. Again\n\t";
            system("pause");
            return 0;
        }
        else
        {
            strcpy(temp->roll,rolo);
        }
		cout<<"\nEnter your name:"<<endl;
        fflush(stdin);
		gets(temp->name);
		cout<<"\nEnter the Father's name"<<endl;
		fflush(stdin);
		gets(temp->fname);
		cout<<"\nEnter the Date of Birth(dd/mm/yyyy):"<<endl;
		scanf("%d/%d/%d", &(temp->dd), &(temp->mm), &(temp->yyyy));
		cout<<"\nEnter Semester:"<<endl;
		fflush(stdin);
		cin>>temp->sem;
		cout<<"\nEnter Year of Admission:"<<endl;
		fflush(stdin);
		cin>>temp->year;
		//..................................ERROR..................................ERROR....................................ERROR...............................ERROR..........
		//..................................ERROR..................................ERROR....................................ERROR...............................ERROR..........
		//..................................ERROR..................................ERROR....................................ERROR...............................ERROR..........
		//delete temp;......................ERROR..................................ERROR....................................ERROR...............................ERROR..........
		return 1;
}

int student::show(student* temp)
{
    cout<<setw(10)<<left<<temp->roll<<setw(30)<<left<<temp->name<<setw(30)<<left<<temp->fname;
    display(temp);
    cout<<setw(15)<<left<<temp->sem<<setw(10)<<left<<temp->year<<endl;
    return 0;
}


int gotostudent()

{
    	int flag=0;
    	headst = NULL;
		char choice, add;
		system("color F5");
		student s, *temp;
		fstream file;

    while(1){
        system("cls");
        cout<<"\n\n";
        cout<<"\t1. Add a student's record.\n";
        cout<<"\t2. Print all Records.\n";
        cout<<"\t3. GO BACK\n";
        cout<<"\n\tENTER YOUR CHOICE : ";
        fflush(stdin);
        cin>>choice;
        system("cls");
        switch(choice){
            case '1':{
                add = 'y';
                int i=0;
                while(add=='y')
                    {
                        system("cls");
                        if(s.getdetails())
                            {
                                temp = headst;
                                while(temp->next != NULL)
                                    {
                                        temp = temp->next;
                                    }
                                file.open("studentinfo.dat", ios::binary | ios::out |ios::app);
                                file.write((char*)temp, sizeof(*temp));
                                file.close();
                                cout<<"\n\tRecords successfully added!!\nWant to add more records? (y/n)\n";
                                fflush(stdin);
                                cin>>add;
                                system("cls");
                            }
                    }
                    headst = NULL;
                break;
            }
            case '2':{
                file.open("studentinfo.dat",ios::in| ios::binary);
                if(!file)
                    {
						cout<<"\n\tFile not Found\n\t";
						system("pause");
						break;
					}
                else
                {	cout<<"\n";
					temp = s.createnode();
                    file.read((char*)temp, sizeof(*temp));
                    while(!file.eof())
                    {
                        temp = s.createnode();
						file.read((char*)temp, sizeof(*temp));
                    }
                }
                file.close();

                temp = headst;
                if(temp==NULL)
                {
                    cout<<"\n\nNo Data Found\n";
                    system("pause");
                    break;
                }
                s.heading();
                while(temp->next != NULL)
                {
                    s.show(temp);
                    temp = temp->next;
                }
                fflush(stdin);
                cout<<"\n";
				system("pause");
                break;
            }
            case '3':{
            return 0;
            }
        }
    }
    return 0;

}
