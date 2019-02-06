/*#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include "studentinfo.h"

using namespace std;


int gotostudent()
{
    	int flag=0;
    	head = NULL;
		char choice, add;
		system("color F5");
		student s, *temp;
		fstream file;
		system("pause");

    while(1){
        system("cls");
        cout<<"\n\n";
        cout<<"\t1. Add a student's record.\n";
        cout<<"\t2. Print all Records.\n";
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
                        if(s.getdetails())
                            {
                                temp = head;
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
                    head = NULL;
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

                temp = head;
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
            break;
            }
        }
    }
    return 0;

}
*/
