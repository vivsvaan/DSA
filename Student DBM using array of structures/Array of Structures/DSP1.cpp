#include <iostream>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include <ctime>
#include <cctype>

using namespace std;

struct date
{
	int dd, mm, yyyy;
	void display()
	{
		cout<<setw(2)<<dd<<"/"<<setw(2)<<mm<<"/"<<yyyy<<"\t";
	}

};







    struct student
{


	//public:
	char roll[10];
	char name[30], fname[30], addr[50];

	struct date dob[100], doj[100];

	int checkrollno(char* b);
    int getdetails(int r, int j);
    int deleterecords(int j, int sizerec);
    int deletedates(int j, int sizerec);
    int deleteallrecords();
    int sorteddisplay(int n, int field);
    bool checkname(char str[30]);
    bool check(struct date d, char type);
    int getNumberOfDays(int month,int year);
    bool isleap(int y);
    int show(int j);


	void heading()
	{
		cout<<setw(10)<<left<<"Roll no."<<setw(25)<<left<<"Name"<<setw(25)<<left<<"Father's Name"<<setw(15)<<left<<"D.O.B"<<setw(15)<<left<<"D.O.J"<<"Address"<<endl;

	}
}stdt[100];

int student::show(int j)
	{
	    if(stdt[j].roll){
			cout<<setw(10)<<left<<roll<<setw(25)<<left<<name<<setw(25)<<left<<fname;
			dob[j].display();
			doj[j].display();
			cout<<addr<<endl;
	    }
	}

int student::deleterecords(int j, int sizerec)
{
    for(int k=j;k<sizerec;k++)
    {
        stdt[k] = stdt[k+1];

    }
    return 0;

}

int student::deletedates(int j, int sizerec)
{
    for(int k=j;k<sizerec;k++)
    {
        dob[k] = dob[k+1];
        doj[k] = doj[k+1];

    }
    return 0;


}

int student::getdetails(int r, int j)
	{
	    char rolo[10];
	    if(r==0)
	    {
        cout<<"\nEnter roll no. \n";
        fflush(stdin);
        gets(rolo);
        for(int i=0;i<=j;i++){
        if(stdt[i].checkrollno(rolo))
        {
            cout<<"\n\tRoll No. Already Exists...\n";
            return 0;
        }
        else
        strcpy(roll, rolo);
	    }
	    }
		cout<<"\nEnter your name:"<<endl;

        fflush(stdin);
		gets(name);
		if(!checkname(name))
		{
			cout<<"Invalid Name!!! No special characters or Numerics!";
			return 0;
		}


		cout<<"\nEnter the Father's name"<<endl;
		fflush(stdin);
		gets(fname);
		if(!checkname(fname))
		{
			cout<<"Invalid Name!! No special characters or Numerics!";
			return 0;
		}

		cout<<"\nEnter the Date of Birth(dd/mm/yyyy):"<<endl;
		scanf("%d/%d/%d", &(dob[j].dd), &(dob[j].mm), &(dob[j].yyyy));
		if(!check(dob[j], 'b'))
		{
			cout<<"Invalid Date of Birth!!!"<<endl;
			return 0;
		}

		cout<<"\nEnter the Date of joining(dd/mm/yyyy):"<<endl;
		scanf("%d/%d/%d", &(doj[j].dd), &(doj[j].mm), &(doj[j].yyyy));
		if(!check(doj[j], 'j'))
		{
			cout<<"Invalid Date of Joining!!!"<<endl;
			return 0;
		}

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

bool student::checkname(char str[30])
{
	int i=0;
	while(str[i]!='\0')
	{
		if(!isalpha(str[i])){
			return 0;
		}
		i++;
	}
		return 1;
}


bool student::check(struct date d, char type)
{
	if(type=='j')
	{
		time_t t=time(0);
		struct tm *now= localtime(&t);
		if((now->tm_year)%100<d.yyyy%100 || 2002>d.yyyy)
		{
				  	return 0;
		}
		else if(now->tm_year==d.yyyy)
		{
			if(now->tm_mon<d.mm)
			{
					return 0;

			}
			else if(now->tm_mon==d.mm)
				if(now->tm_mday<d.dd)
				  {

					return 0;
					}
		}
	}
	else
	{
		if(d.yyyy>=2001 || d.yyyy<=1984)
			return 0;
	}
	if(d.dd<=getNumberOfDays(d.mm, d.yyyy) && d.dd>0)
		return 1;
	return 0;
}

int datecmpi(date a, date b)
{
	if(a.yyyy>=b.yyyy)
		return a.yyyy-b.yyyy;
	else
		{
			if(a.mm>=b.mm)
				return a.mm-b.mm;
				else
				{
					if(a.dd>=b.dd)
						return a.dd-b.dd;
					else
						return -1;
				}
		}
}

bool student::isleap(int y)
{
	if(y%4==0)
	{
		if(y%100==0)
		{
			if(y%400==0)
				return 1;
			else
				return 0;
		}
		else
			return 1;
	}
	else
		return 0;
}

int student::getNumberOfDays(int month,int year)
{
   switch(month){
      case 1 : return(31);
      case 2 : if(isleap(year))
		 return(29);
	       else
		 return(28);
      case 3 : return(31);
      case 4 : return(30);
      case 5 : return(31);
      case 6 : return(30);
      case 7 : return(31);
      case 8 : return(31);
      case 9 : return(30);
      case 10: return(31);
      case 11: return(30);
      case 12: return(31);
      default: return(-1);
   }
}




void swap(student stdt[], int y)
{


						student temp = stdt[y+1];

						stdt[y+1] = stdt[y];

						stdt[y] = temp;
}
int student::sorteddisplay(int n, int field)
{


	for(int x=0; x<n; x++)

	{

		for(int y=0; y<n-1; y++)

		{

			switch(field)
			{
			    case 0:
					if(strcmpi(stdt[y].roll,stdt[y+1].roll)>0)
					{
						swap(stdt, y);
					}
					break;
				case 1:
					if(strcmpi(stdt[y].name,stdt[y+1].name)>0)
					{
						swap(stdt, y);
					}
					break;
				case 2:
					if(strcmpi(stdt[y].fname,stdt[y+1].fname)>0)
					{
						swap(stdt, y);
					}
					break;
				case 3:
					if(strcmpi(stdt[y].addr,stdt[y+1].addr)>0)
					{
						swap(stdt, y);
					}
					break;
                case 4:
					if(datecmpi(stdt[y].dob[y],stdt[y+1].dob[y+1])>0)
					{
						swap(stdt, y);
					}
					break;
                case 5:
                    if(datecmpi(stdt[y].doj[y],stdt[y+1].dob[y+1])>0)
					{
						swap(stdt, y);
					}



			}

		}

	}
	stdt[0].heading();
	for(int i=0;i<n;i++)
	{
		stdt[i].show(i);
	}
}

int student::deleteallrecords()
{
    roll[0] = '\0';
    name[0] = '\0';
    fname[0] = '\0';
    addr[0] = '\0';
    return 0;

}

int main()
{
    	int flag=0;
		char choice;
		int sch=0;
		char add;
		char rolo[10];
		int noofrecords=0;
		string rol;
		system("color F5");

    while(1){
        system("cls");
        cout<<"\n\n";
        cout<<"\t1. Add a student's record.\n";
        cout<<"\t2. Delete a student's record.\n";
        cout<<"\t3. Update a student's record'\n";
        cout<<"\t4. Print all Records.\n";
        cout<<"\t5. Print a particular Record.\n";
        cout<<"\t6. Sort the list.\n";
        cout<<"\t7. Delete all Records.\n";
        cout<<"\t8. EXIT\n";
        cout<<"\n\tENTER YOUR CHOICE : ";
        fflush(stdin);
        choice=getche();
        system("cls");
        switch(choice){
            case '1':
                {
                add = 'y';
                int i=0;
                while(add=='y')
                {

				if(stdt[i].getdetails(0,i))
				{

				    i++;
					//fstream f("studentrecord.dat", ios::binary | ios::out |ios::app);
					//f.write((char*)&stdt, sizeof(stdt));
					//f.close();
					cout<<"\n\tRecords successfully added!!\nWant to add more records? (y/n)\n";
					fflush(stdin);
					cin>>add;
					noofrecords+=i;
					system("cls");


				}

                //system("pause");

                }
                break;
                }

        case '2' :
				cout<<"\tEnter the Roll no. to delete the record:\n";
				fflush(stdin);
				cin>>rolo;
				flag=0;
					for(int i=0;i<noofrecords;i++)
                    {
                    if(stdt[i].checkrollno(rolo))
						{
							flag=1;
							stdt[0].deleterecords(i,noofrecords);
							stdt[0].deletedates(i,noofrecords);
						}
					}
				if(flag)
					{

					    cout<<"\n\tRecord Deleted!!!\n";
					system("pause");}
				else
					{cout<<"\n\tRecord not found!!";
					system("pause");}
				fflush(stdin);
                break;
            case '3':

					cout<<"\n\tEnter the Roll no. to update the record:\n";
					gets(rolo);
					flag=0;
						for(int i=0;i<noofrecords;i++){
							if(stdt[i].checkrollno(rolo))
							{
								cout<<"\n\tRECORD FOUND!! Enter New Record..\n"<<endl;
								stdt[i].getdetails(1,i);
								flag=1;
							}
						}
						if(flag)
							{cout<<"\n\tRecord Updated!!!\n";

							}
						else
							{cout<<"\n\tRecord not found!!\n";

							}

					fflush(stdin);
					system("pause");
				break;
            case '4':
					cout<<"\n";
					    stdt[0].heading();
					cout<<"\n";
						for(int i=0;i<noofrecords;i++){
							stdt[i].show(i);
						}
					fflush(stdin);
					cout<<"\n";
					system("pause");
                break;
            case '5':
                cout<<"\n\tEnter the roll no. to fetch the details:\t";
            	cin>>rolo;
            	flag=0;
					for(int i=0;i<noofrecords;i++)
                        {
							if(stdt[i].checkrollno(rolo))
							{
							    cout<<"\n";
								stdt[0].heading();
								cout<<"\n";
								stdt[i].show(i);
								flag=1;

							}
						}
					if(!flag)
						cout<<"\n\tRecords not found!!!"<<endl;
					fflush(stdin);
					system("pause");
                break;

            case '6' :
                cout<<"\n\tWhich field to be considered while sorting?"<<endl;
            	 cout<<"\t0 for roll no."<<endl;
            	 cout<<"\t1 for name"<<endl;
            	 cout<<"\t2 for Father's name"<<endl;
            	 cout<<"\t3 for Address"<<endl;
            	 cout<<"\t4 for Date of Birth"<<endl;
            	 cout<<"\t5 for Date of Joining"<<endl;
            	 cout<<"\tEnter your choice:";
            	 fflush(stdin);
            	 cin>>sch;
            	 stdt[0].sorteddisplay(noofrecords, sch);
            	 fflush(stdin);
                 system("pause");
			    break;

            case '7':
                system("cls");
                cout<<"\n\tDeleting all Records\n";
                for(int i=0;i<noofrecords;i++)
                {
                    stdt[i].deleteallrecords();
                }
                cout<<"\n\tAll Records Deleted...\n\n";
                system("pause");
                break;


            case '8':
                exit(0);
                break;

        }
    }

	return 1;
}





















