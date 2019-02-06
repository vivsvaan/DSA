#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
#include <string.h>
#include "studentinfo.h"
#include "schemeinfo.h"

using namespace std;

struct report
{
    struct report* datast;
    struct report* datasc;
    struct report* next;
    report* createnode();
    int entermrks();
    int readstudent();
    int readscheme();
    report* readreport();
    student* loadstudent(char* b);
    scheme* loadscheme(char* b);
    scheme* loadscheme(int b);
    int savetolist(char* b);
    int savetofile();
    void headingrpt(report* temp)
    {
        cout<<"\t"<<setw(41)<<left<<""<<setw(89)<<left<<"CHANDIGARH COLLEGE OF ENGINEERING AND TECHNOLOGY"<<"\t"
        <<endl<<"\t"<<setw(59)<<left<<""<<setw(71)<<left<<"Affilated to"<<"\t"
        <<endl<<"\t"<<setw(51)<<left<<""<<setw(79)<<left<<"PUNJAB UNIVERSITY CHANDIGARH"<<"\t"
        <<endl<<"\t"<<setw(59)<<left<<""<<setw(71)<<left<<"REPORT  CARD"<<"\t"<<endl<<endl
        <<endl<<"\t"<<setw(118)<<left<<"Roll Number:- "<<temp->datast->roll<<setw(12)<<left<<"Semester:- "<<temp->datast->sem<<"\t"
        <<endl<<"\t"<<setw(119)<<left<<"Name:- "<<temp->datast->name<<setw(11)<<left<<"Year:- "<<temp->datasc->year<<"\t"
        <<endl<<"\t"<<"Father's Name:- "<<temp->datast->fname
        <<endl<<"\t"<<"Date Of Birth:- "<<temp->datast->dd<<"/"<<temp->datast->mm<<"/"<<temp->datast->yyyy<<endl<<endl;

        cout<<"\t"<<setw(18)<<left<<"Subject Code"<<setw(48)<<left<<"Subject Title"
        <<setw(17)<<left<<"Maximum Marks"<<setw(17)<<left<<"Marks Awarded"
        <<setw(17)<<left<<"Maximum Marks"<<setw(13)<<left<<"Marks Awarded"<<"\t"
        <<endl<<"\t"<<setw(66)<<left<<""<<setw(17)<<left<<"(Sessional)"
        <<setw(18)<<left<<"(Sessional)"<<setw(17)<<left<<"(Theory)"<<setw(12)<<left<<"(Theory)"<<"\t"<<endl<<endl;
    }

    void printrpt(report* temp)
{
    cout<<"\t"<<setw(18)<<left<<temp->datasc->subcode<<setw(48)<<left<<temp->datasc->subtitle
    <<setw(17)<<left<<temp->datasc->mxms<<setw(17)<<left<<temp->datasc->mas
    <<setw(17)<<left<<temp->datasc->mxmt<<setw(13)<<left<<temp->datasc->mat<<"\t"<<endl;

}
}*headrpt;

report* report::createnode()
{
    struct report *n, *newn;
    if(headrpt == NULL)
    {
        cout<<"\n\thead is null";
        newn = new(struct report);
        newn->next = NULL;
        headrpt = newn;
        headrpt->next = NULL;
        return newn;
    }
    else{
    n = headrpt;
    cout<<"\n\thead is not null";
    while(n->next !=NULL)
    {
        n = n->next;
    }
    newn = new(struct report);
    newn->next = NULL;
    n->next = newn;
    return newn;
    }
}

int report::readstudent()
{
    struct student *temp, stu;
    fstream file;
    file.open("studentinfo.dat",ios::in| ios::binary);
    if(!file)
        {
            cout<<"\n\tFile not Found\n\t";
            system("pause");
            return 0;
        }
    else
    {	cout<<"\n";
        temp = stu.createnode();
        file.read((char*)temp, sizeof(*temp));
        while(!file.eof())
        {
            temp = stu.createnode();
            file.read((char*)temp, sizeof(*temp));
        }
    }
    file.close();
}

int report::readscheme()
{
    struct scheme *temp, sch;
    fstream file;
    file.open("schemeinfo.dat",ios::in| ios::binary);
    if(!file)
        {
            cout<<"\n\tFile not Found\n\t";
            system("pause");
            return 0;
        }
    else
    {	cout<<"\n";
        temp = sch.createnode();
        file.read((char*)temp, sizeof(*temp));
        while(!file.eof())
        {
            temp = sch.createnode();
            file.read((char*)temp, sizeof(*temp));
        }
    }
    file.close();
}

report* report::readreport()
{
    struct report *temp,*head, rpt;
    fstream file;
    file.open("reportinfo.dat",ios::in| ios::binary);
    if(!file)
        {
            cout<<"\n\tFile not Found\n\t";
            system("pause");
            return 0;
        }
    else
    {	cout<<"\n";
        temp = rpt.createnode();
        file.read((char*)temp, sizeof(*temp));
        headrpt = temp;
        //while(!file.eof())
        while(file.read((char*)temp, sizeof(*temp)))
        {
            temp = rpt.createnode();
            file.read((char*)temp, sizeof(*temp));
        }
    }
    file.close();
    return headrpt;
}

int report::entermrks()
{
    char subcod[10], rolln[10];
    int choice, sem;
    struct report rpt;
    struct student *stuinfo;
    struct scheme *schinfo;
    rpt.readstudent();
    rpt.readscheme();
    cout<<"\n\tEnter Roll No. of Student"<<endl;
    fflush(stdin);
    gets(rolln);
    stuinfo = rpt.loadstudent(rolln);
    if(stuinfo == NULL)
    {
        cout<<"\n\tStudent's Record NOT FOUND!!!\n\t";
        system("pause");
        return 0;
    }
    cout<<"\n\t1. Enter marks per subject\n";
    cout<<"\n\t2. Enter marks per semester\n";
    cout<<"\n\t   Enter your choice...";
    cin>>choice;
    if(choice == 1)
    {
        while(1)
            {
                system("cls");
                cout<<"\n\tEnter Subject Code (if you want to GO BACK, Press x)"<<endl;
                fflush(stdin);
                gets(subcod);
                if(subcod == "x")
                {
                    break;
                }
                schinfo = rpt.loadscheme(subcod);
                if(schinfo == NULL)
                {
                    cout<<"\n\tSubject Code NOT FOUND!!!\n\t";
                    system("pause");
                    break;
                }
                cout<<"\n\tEnter marks of "<<schinfo->subtitle<<" Sessional...";
                cin>>schinfo->mas;
                cout<<"\n\tEnter marks of "<<schinfo->subtitle<<" Theory...";
                cin>>schinfo->mat;
                cout<<"\nMarks Added Successfully"<<endl;
            }
        //write data to file...................................
        rpt.savetolist(rolln);

    }



}


int report::savetolist(char* b)
{
    //string str = b;
    struct student *tempst;
    struct scheme *tempsc;
    struct report *temprpt, rpt;
    tempst = rpt.loadstudent(b);
    int sem = tempst->sem;
    tempsc = headsc;
    while(tempsc->next != NULL)
    {
        if(tempsc->sem == sem)
        {
            temprpt = rpt.createnode();
            temprpt->datasc = tempsc;
            temprpt->datast = tempst;
            rpt.savetofile();
        }
        tempsc = tempsc->next;
    }

}

int report::savetofile()
{
    fstream file;
    struct report *temp;
    temp = headrpt;
    while(temp->next != NULL)
        {
            temp = temp->next;
        }
    file.open("reportinfo.dat", ios::binary | ios::out |ios::app);
    file.write((char*)temp, sizeof(*temp));
    file.close();
}

student* report::loadstudent(char* b)
{
    string str = b;
    struct student *temp;
    temp = headst;
    while(temp->next != NULL)
    {
        if(str.compare(temp->roll)==0)
        {
            return temp;
        }
        else
        {
            temp = temp->next;
        }
    }
    return NULL;
}

scheme* report::loadscheme(char* b)
{
    string str = b;
    struct scheme *temp;
    temp = headsc;
    while(temp->next != NULL)
    {
        if(str.compare(temp->subcode)==0)
        {
            return temp;
        }
        else
        {
            temp = temp->next;
        }
    }
    return NULL;
}


int main()
{
    struct report rpt;
    system("color f5");
    char choice;
    while(1){
        system("cls");
        cout<<"\n\n";
        cout<<"\t1. Perform Operations on Student's Database.\n";
        cout<<"\t2. Perform Operations on Scheme's Database\n";
        cout<<"\t3. Enter Marks and make Report Card of a Student\n";
        cout<<"\t4. Print Report Card of a Student\n";
        cout<<"\t5. Print all Results\n";
        cout<<"\t6. Sort the Results List\n";
        cout<<"\t7. EXIT\n";
        cout<<"\n\tENTER YOUR CHOICE : ";
        fflush(stdin);
        cin>>choice;
        system("cls");
        switch(choice){
            case '1':{
                gotostudent();
                break;
            }
            case '2':{
                gotoscheme();
                break;
            }
            case '3':{
                rpt.entermrks();
                //headrpt = NULL;
                break;
            }
            case '4':{/*
                system("cls");
                struct report *temp, *head, rpt;
                string roln;
                fstream file;
                file.open("reportinfo.dat",ios::in| ios::binary);
                if(!file)
                    {
                        cout<<"\n\tFile not Found\n\t";
                        system("pause");
                        return 0;
                    }
                else
                {   cout<<"\n";
                    temp = rpt.createnode();
                    file.read((char*)temp, sizeof(*temp));
                    head = temp;
                    while(!file.eof())
                    {
                        temp = rpt.createnode();
                        file.read((char*)temp, sizeof(*temp));
                    }
                }
                file.close();
                //head = rpt.readreport();
                //rpt.readreport();*/
                cout<<"\n\tEnter Roll No. of Student...";
                fflush(stdin);
                cin>>roln;

                temp = headrpt;
                if(temp==NULL)
                {
                    cout<<"\n\nNo Data Found\n";
                    system("pause");
                    break;
                }
                int flag = 0;

                while(temp != NULL)
                    {
                        //cout<<"\nhello";
                        //cout<<endl<<temp->
                        bool c1 = roln == temp->datast->roll;
                        bool c2 = temp->datast->sem == temp->datasc->sem;
                        if(c1 && flag == 0)
                            {
                                rpt.headingrpt(temp);
                                flag = 1;
                            }
                        if(c2 && flag == 1)
                            {
                                rpt.printrpt(temp);
                                temp = temp->next;

                                //temp = temp->next;
                            }
                        else
                            {
                                temp = temp->next;
                            }
                    }
                fflush(stdin);
                cout<<"\n";
                system("pause");
                break;
            }
            case '6':
            {
            	system("cls");
            	struct report *temp, *newlist, rpt;
            	//temp = headrpt;
            	temp = rpt.readreport();
            	if(headrpt == NULL)
            	{
            		cout<<"\nNo list Found!!\n";
            		system("pause");
            	}


            }
        }
    }
    return 0;
}





















