#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <iomanip>

using namespace std;

struct date
{
	int dd, mm, yyyy;
	void display()
	{
		cout<<setw(2)<<dd<<"/"<<setw(2)<<mm<<"/"<<yyyy<<"\t";
	}

};


int count=1;
fstream f;
    char rolo[10];

  ofstream o;
    fstream fil;

    class student
{
	public:
	char roll[10];
	char name[30], fname[30], addr[50];

	struct date dob, doj;

	int checkrollno(char* b);
    int check(char* rc);
    int getdetails(int r);


	void heading()
	{
		cout<<setw(10)<<left<<"Roll no."<<setw(25)<<left<<"Name"<<setw(25)<<left<<"Father's Name"<<setw(15)<<left<<"D.O.B"<<setw(15)<<left<<"D.O.J"<<"Address"<<endl;

	}
	void show()
	{
			cout<<setw(10)<<left<<roll<<setw(25)<<left<<name<<setw(25)<<left<<fname;
			dob.display();
			doj.display();
			cout<<addr<<endl;
	}


}stdt;

int student::getdetails(int r)
	{
	    if(r==0)
	    {
        cout<<"\nEnter roll no. \n";
        fflush(stdin);
        gets(rolo);
        if(!stdt.check(rolo))
        {
            cout<<"\n\tRoll No. Already Exists...\n";
            return 0;
        }
        strcpy(roll, rolo);
	    }
		cout<<"\nEnter your name:"<<endl;

        fflush(stdin);
		gets(name);


		cout<<"\nEnter the Father's name"<<endl;
		fflush(stdin);
		gets(fname);

		cout<<"\nEnter the Date of Birth(dd/mm/yyyy):"<<endl;
		scanf("%d/%d/%d", &(dob.dd), &(dob.mm), &(dob.yyyy));

		cout<<"\nEnter the Date of joining(dd/mm/yyyy):"<<endl;
		scanf("%d/%d/%d", &(doj.dd), &(doj.mm), &(doj.yyyy));

		cout<<"\nEnter the Address:"<<endl;
		fflush(stdin);
		gets(addr);
		return 1;

	}


int student::checkrollno(char* b)
{

                string str = b;
				if(str.compare(roll)==0)
				{

				    return 1;

				}
                else return 0;
}

int student::check(char* rc)
{
    student ss;

	 	        f.open("studentrecord.dat",ios::out|ios::in | ios::app | ios::binary);

	 	        while(!f.eof())
                    {
                        f.read((char*)&ss, sizeof(ss));
                        if(ss.checkrollno(rolo))
                        {

                            f.close();
                            return 0;
                        }
                    }
    f.close();
    return 1;
}

void swap(student array[], int y)
{


						student temp = array[y+1];

						array[y+1] = array[y];

						array[y] = temp;
}
void sorteddisplay(int n, int field)
{
	fil.open("studentrecord.dat", ios::in | ios::binary );
	student array[n];
	if(!fil)
	{
		cout<<"File not Found";
	}
	else
	{
		fil.read((char*)array, n*sizeof(stdt));
	}
	fil.close();

	for(int x=0; x<n; x++)

	{

		for(int y=0; y<n-1; y++)

		{

			switch(field)
			{
				case 1:
					if(strcmpi(array[y].name,array[y+1].name)>0)
					{
						swap(array, y);
					}
					break;
				case 2:
					if(strcmpi(array[y].fname,array[y+1].fname)>0)
					{
						swap(array, y);
					}
					break;
				case 5:
					if(strcmpi(array[y].addr,array[y+1].addr)>0)
					{
						swap(array, y);
					}
					break;
				case 0:
					if(strcmpi(array[y].roll,array[y+1].roll)>0)
					{
						swap(array, y);
					}
					break;


			}

		}

	}
	array[0].heading();
	for(int i=0;i<n;i++)
	{
		array[i].show();
	}
}

int main()
{


    fil.open("studentrecord.dat",ios::in| ios::binary);
if(!fil)
{
	count=0;
}
else
{
	while(!fil.eof())
	{
		fil.read((char*)&stdt, sizeof(stdt));
		count++;
	}
}
fil.close();
    	//int roll;
    	int flag=0;
		char choice;
		int sch=0;

    while(1){
        system("cls");
        cout<<"\n\n";
        cout<<"\t1.Add a student's record.\n";
        cout<<"\t2. Delete a student's record.\n";
        cout<<"\t3. Update a student's record'\n";
        cout<<"\t4. Print all Records.\n";
        cout<<"\t5. Delete all Records\n";
        cout<<"\t6. Print a particular Record.\n";
        cout<<"\t7.Sort the list.\n";

        cout<<"\t8. EXIT\n";

        cout<<"\n\tENTER YOUR CHOICE : ";
        fflush(stdin);
        choice=getche();
        system("cls");
        switch(choice){
            case '1':
				if(stdt.getdetails(0))
				{
					fstream f("studentrecord.dat", ios::binary | ios::out |ios::app);
					f.write((char*)&stdt, sizeof(stdt));
					f.close();
					cout<<"\n\tRecords successfully added!!\n";
				}
				else
					cout<<"\n\tRecords couldn't be added.\t"<<endl;
					fflush(stdin);
                system("pause");
                break;
            case '2' :
				cout<<"\tEnter the Roll no. to delete the record:\n";
				cin>>rolo;
				flag=0;
				o.open("new.dat",ios::out|ios::binary);
				fil.open("studentrecord.dat",ios::in| ios::binary);
				if(!fil)
				{
					cout<<"\n\tFile not Found";
					exit(0);
				}
				else
				{
					fil.read((char*)&stdt, sizeof(stdt));
					while(!fil.eof())
					{
						if(stdt.roll!=rolo)
						{
							o.write((char*)&stdt, sizeof(stdt));
							flag=1;
						}

						fil.read((char*)&stdt, sizeof(stdt));
					}
				}
				if(flag)
					{cout<<"\n\tRecord Deleted!!!\n";
					system("pause");}
				else
					{cout<<"\n\tRecord not found!!";
					system("pause");}
				o.close();
				fil.close();
				remove("studentrecord.dat");
				rename("new.dat", "studentrecord.dat");
				fflush(stdin);
                break;
            case '3':

					cout<<"\n\tEnter the Roll no. to update the record:\n";
					gets(rolo);
					flag=0;
					fil.open("studentrecord.dat",ios::in| ios::out|ios::binary);
					if(!fil)
					{
						cout<<"\n\tFile not Found";
						exit(0);
					}
					else
					{
						fil.read((char*)&stdt, sizeof(stdt));
						while(!fil.eof())
						{
							if(stdt.roll==rolo)
							{
								fil.seekg(0,ios::cur);
								cout<<"\n\tRECORD FOUND!! Enter New Record..\n"<<endl;
								stdt.getdetails(1);
								fil.seekp(fil.tellg() - sizeof(stdt));
								fil.write((char*)&stdt, sizeof(stdt));
								flag=1;
							}

							fil.read((char*)&stdt, sizeof(stdt));
						}
						if(flag)
							{cout<<"\n\tRecord Updated!!!\n";
							system("pause");}
						else
							{cout<<"\n\tRecord not found!!";
							system("pause");}
					}
					fflush(stdin);
					system("pause");
					fil.close();
				break;
            case '4':
				    fil.open("studentrecord.dat",ios::in| ios::binary);
					if(!fil)
					{
						cout<<"\n\tFile not Found";
						system("pause");
					}
					else
					{	cout<<"\n";
					    stdt.heading();
					cout<<"\n";
						fil.read((char*)&stdt, sizeof(stdt));
						while(!fil.eof())
						{
							stdt.show();
							fil.read((char*)&stdt, sizeof(stdt));
						}
					}
					fil.close();
					fflush(stdin);
					cout<<"\n";
					system("pause");
                break;
            case '5':
                cout<<"\n\tDeleting Records...\n";
                fil.open("studentrecord.dat",ios::out | ios::trunc);
					if(!fil)
					{
						cout<<"\n\tFile not Found\n";
						exit(0);
					}
					else
                    {
                        cout<<"\n\tAll Records deleted\n";
                        system("pause");
                    }
					fil.close();
					break;


            case '6':
                cout<<"\n\tEnter the roll no. to fetch the details:\t";
            	cin>>rolo;
            	flag=0;
				            	fil.open("studentrecord.dat",ios::in| ios::binary);
					if(!fil)
					{
						cout<<"\n\tFile not Found\n";
						exit(0);
					}
					else
					{
						fil.read((char*)&stdt, sizeof(stdt));
						while(!fil.eof())
						{
							if(stdt.roll==rolo)
							{
							    cout<<"\n";
								stdt.heading();
								cout<<"\n";
								stdt.show();
								flag=1;
								system("pause");
							}
							fil.read((char*)&stdt, sizeof(stdt));
						}
					}
					if(!flag)
						cout<<"\n\tRecords not found!!!"<<endl;
					fil.close();
					fflush(stdin);
					system("pause");
                break;

            case '7' :
                cout<<"\n\tWhich field to be considered while sorting?"<<endl;
            	 cout<<"\t0 for roll no."<<endl;
            	 cout<<"\t1 for name"<<endl;
            	 cout<<"\t2 for Father's name"<<endl;
            	 cout<<"\t3 for Address"<<endl;
            	 cout<<"\tEnter your choice:";
            	 fflush(stdin);
            	 cin>>sch;
            	 sorteddisplay(count, sch);
            	 fflush(stdin);
                 system("pause");
			    break;


            case '8':
                exit(0);
                break;

        }
    }
	return 1;
}




















