#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include <fstream>

using namespace std;

    struct scheme
{
	char subcode[10], subtitle[30];
	int sem, year, mxmt, mxms, mat, mas;
    struct scheme *next;
	int getscheme();
    scheme* createnode();
    int printscheme(scheme* temp);
    int checksubcode(char* b);
    void heading()
	{
		cout<<endl<<setw(12)<<left<<"Semester"<<setw(9)<<left<<"Year"<<setw(20)<<left<<"Subject Code"
		<<setw(40)<<left<<"Subject Title"<<setw(22)<<left<<"M.M.(Sessionals)"<<setw(18)<<left<<"M.M.(Theory)"<<endl;
        cout<<endl;
	}
}*head;

scheme* scheme::createnode()
{
    struct scheme *n, *newn;
    if(head == NULL)
    {
        newn = new(struct scheme);
        newn->next = NULL;
        head = newn;
        head->next = NULL;
        return newn;
    }
    else{
    n = head;
    while(n->next !=NULL)
    {
        n = n->next;
    }
    newn = new(struct scheme);
    newn->next = NULL;
    n->next = newn;
    return newn;
    }
}

int scheme::checksubcode(char* b)
{
    string str = b;
    int flag = 0;
    struct scheme *sub;
    sub = head;
    while(sub->next != NULL)
    {
        if(str.compare(sub->subcode)==0)
        {
            flag = 1;
        }
        sub = sub->next;
    }

    if(flag == 1)
    {
        return 1;
    }
    else return 0;
}

int scheme::getscheme()
{
    int flag = 0;
    struct scheme *temp, s, *del;
    temp = createnode();
    cout<<"\nEnter Semester: "<<endl;
    cin>>temp->sem;
    cout<<"\nEnter Year: "<<endl;
    cin>>temp->year;
    char subc[10];
    cout<<"\nEnter Subject Code: "<<endl;
    fflush(stdin);
    gets(subc);
    if(s.checksubcode(subc))
    {
        cout<<"\n\n\tSubject Code Already Exists...Enter Subject Code Again\n\t";
        system("pause");
        flag = 1;
    }
    if(flag == 1)
    {
        del = head;
        while(del->next->next != NULL)
        {
            del = del->next;
        }
        del->next = NULL;
        return 0;
    }
    else if(flag == 0)
    {
        strcpy(temp->subcode,subc);
    }
    cout<<"\nEnter Subject Title: "<<endl;
    fflush(stdin);
    gets(temp->subtitle);
    /*if(!checkname(name))
    {
        cout<<"Invalid Name!!! No special characters or Numerics!";
        return 0;
    } */
    cout<<"\nEnter Maximum Marks for Sessionals of "<<temp->subtitle<<":"<<temp->subcode<<endl;
    fflush(stdin);
    cin>>temp->mxms;
    cout<<"\nEnter Maximum Marks for Theory of "<<temp->subtitle<<":"<<temp->subcode<<endl;
    fflush(stdin);
    cin>>temp->mxmt;
    //..................................ERROR..................................ERROR....................................ERROR...............................ERROR..........
    //..................................ERROR..................................ERROR....................................ERROR...............................ERROR..........
    //..................................ERROR..................................ERROR....................................ERROR...............................ERROR..........
    //delete temp;......................ERROR..................................ERROR....................................ERROR...............................ERROR..........
    return 1;
}

int scheme::printscheme(scheme* temp)
{
    cout<<setw(12)<<left<<temp->sem<<setw(9)<<left<<temp->year<<setw(20)<<left<<temp->subcode
    <<setw(40)<<left<<temp->subtitle<<setw(22)<<left<<temp->mxms<<setw(18)<<left<<temp->mxmt<<endl;
    return 0;
}

int main()
{
    	int flag=0;
    	head = NULL;
		char choice, add;
		system("color F5");
		scheme s, *temp;
		fstream file;

    while(1){
        system("cls");
        cout<<"\n\n";
        cout<<"\t1. Add a Scheme.\n";
        cout<<"\t2. Print all Schemes.\n";
        cout<<"\t3. EXIT\n";
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
                        if(s.getscheme())
                            {
                                temp = head;
                                while(temp->next != NULL)
                                    {
                                        temp = temp->next;
                                    }
                                file.open("schemeinfo.dat", ios::binary | ios::out |ios::app);
                                file.write((char*)temp, sizeof(*temp));
                                file.close();
                                cout<<"\n\tScheme added successfully!!\nWant to add more Schemes? (y/n)\n";
                                fflush(stdin);
                                cin>>add;
                                system("cls");
                            }
                    }
                    head = NULL;
                break;
            }
            case '2':{
                file.open("schemeinfo.dat",ios::in| ios::binary);
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
                temp = head;
                if(temp==NULL)
                {
                    cout<<"\n\nNo Data Found\n";
                    system("pause");
                    break;
                }
                s.heading();
                while(temp != NULL)
                {
                    s.printscheme(temp);
                    temp = temp->next;
                }
                fflush(stdin);
                cout<<"\n";
				system("pause");
                break;
            }
            case '3':{
            exit(1);
            }
        }
    }
    return 0;

}
