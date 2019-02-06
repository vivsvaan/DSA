#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream>
using namespace std;

struct bptnode
{
    int *data;
    bptnode **child_ptr;
    bool leaf;
    int n;
}*root = NULL, *np = NULL, *x = NULL, *x1 = NULL, *x2 = NULL, *del = NULL;
bptnode * init()
{
    int i;
    np = new bptnode;
    np->data = new int[5];
    for(i=0;i<5;i++)
    {
    	np->data[i] = 2147483647;
    }
    np->child_ptr = new bptnode *[6];
    np->leaf = true;
    np->n = 0;
    for (i = 0; i < 6; i++)
    {
        np->child_ptr[i] = NULL;
    }
    return np;
}
void traverse(bptnode *p)
{
	if(p == NULL)
	{
		cout<<"\nNode not found"<<endl;
		system("pause");
		return;
	}
    cout<<endl;
    int i;
    for (i = 0; i < p->n; i++)
    {
        if (p->leaf == false)
        {
            traverse(p->child_ptr[i]);
        }
        cout << " " << p->data[i];
    } 
    if (p->leaf == false)
    {
        traverse(p->child_ptr[i]);
    }
    cout<<endl;
}

void traverseleaf(bptnode *p)
{
	if(p == NULL)
	{
		cout<<"\nNode not found"<<endl;
		system("pause");
		return;
	}
	while(p != NULL)
	{
		int i;
		cout<<endl;
		for(i=0; i<p->n; i++)
		{
			cout<<" "<<p->data[i];
		}
		p = p->child_ptr[p->n];
	}
}
void sort(int *p, int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n-1; j++)
        {
            if (p[j] > p[j+1])
            {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

int find(bptnode *x, int a);

int merge(int mid)
{
	int i, j;
	j = find(x, mid);
    for(i = x->n; i>j+1; i--)
    {
    	x->child_ptr[i] = x->child_ptr[i-1];
    }
    return j;
}

int split_child(bptnode *x, int i)
{
    int j, mid;
    bptnode *np1, *np3, *y;
    np3 = init();
    np3->leaf = true;
    if (i == -1)
    {
    	mid = x->data[2];
        x->data[2] = 0;
        x->n--;
        np1 = init();
        np1->leaf = false;
        x->leaf = true;
        np3->data[0] = mid;
        np3->n++;
        for (j = 3; j < 5; j++)
        {
            np3->data[j - 2] = x->data[j];
            np3->n++;
            x->data[j] = 0;
            x->n--;
        }
        np1->data[0] = mid;
        np1->child_ptr[0] = x;
        np1->child_ptr[1] = np3;
        np1->n++;
        root = np1;
    }
    else
    {
        mid = x1->data[2];
        x1->data[2] = 2147483647;
        x1->n--;
        np3->data[0] = mid;
        np3->n++;
        for (j = 3; j < 5; j++)
        {
            np3->data[j - 2] = x1->data[j];
            np3->n++;
            x1->data[j] = 2147483647;
            x1->n--;
        }
        x->data[x->n] = mid;
        x->n++;
        sort(x->data, x->n);
        j = merge(mid);
        x->child_ptr[j+1] = np3;
        del = x->child_ptr[j+1];

        
    }
    return mid;
}
void insert(int a)
{
    int i, temp, flag = 0;
    x = root;
    if (x == NULL)
    {
        root = init();
        x = root;
        x->data[0] = a;
    	x->n++;
    }
    else
    {
        if (x->leaf == true && x->n == 4)
        {
            x->data[4] = a;
            x->n++;
            sort(x->data, x->n);
            temp = split_child(x, -1);
        }
        else
        {
            while (x->leaf == false)
            {
            	flag = 1;
	            for (i = 0; i < (x->n); i++)
	            {
	                if(x->n == 1 && a > x->data[0])
	                {
	                	flag = 1;
	                    i++;
	                    x1 = x->child_ptr[i];
	                    break;
	                }
	                if ((a > x->data[i]) && (a < x->data[i + 1]))
	                {
	                    i++;
	                    x1 = x->child_ptr[i];
	                    flag = 1;
	                    break;
	                }
	                else if (a < x->data[0])
	                {
	                	flag = 1;
	                	x1 = x->child_ptr[i];
	                    break;
	                }
	                else
	                {
	                    continue;
	                }
	            }
	            if (x1->n == 4)
	            {
	            	x1->data[4] = a;
	            	x1->n++;
	            	sort(x1->data, x1->n);
	                temp = split_child(x, i);
	                break;
	            }
	            else if(flag == 1 )
	            {
	                x = x->child_ptr[i];
	                x->data[x->n] = a;
	                x->n++;
	                sort(x->data, x->n);
	                break;
	            }
            }
            if(flag == 0)
            {
            	x->data[x->n] = a;
            	x->n++;
            	sort(x->data, x->n);
            }
        }
    }
}


void delete_item(int a)
{
    int i, temp, j;
    bptnode *np1;
    x = root;
    if(x == NULL)
    {
        cout<<"\nTree does not exist\n";
    }
    j = find(x, a);
    if(del->leaf == true)
    {
        del->data[j] = 0;
        for(i=j+1;i<del->n;i++)
        {
            del->data[i-1] = del->data[i];
        }
    }
    else if(del->leaf == false)
    {
        if((del->child_ptr[j])->leaf == true)
        {
            np1 = del->child_ptr[j];
            del->data[j] = np1->data[0];
            np1->data[0] = 0;
            for(i=1;i<np1->n;i++)
            {
                np1->data[i-1] = np1->data[i];
            }
        }
    }    
}

int find(bptnode *x, int a)
{
    int j=0,i, flag = 0;
    for(i=0;i<(x->n); i++)
    {
        if(x->data[i] == a)
        {
            del = x;
            return i;
        }
        else if(x->data[i] > a && x->leaf == false)
        {
            j = find(x->child_ptr[i], a);
            return j;
        }
        else if(x->data[i] < a && x->leaf == false)
        {
            j = find(x->child_ptr[i+1], a);
            return j;
        }
    }
}

bptnode* connectall()
{
	int i;
	struct bptnode *y1, *y2;
	x = root;
	if(x->child_ptr[1] != NULL)
	{
		for(i=0; i<x->n;i++)
		{
			y1 = x->child_ptr[i];
			y2 = x->child_ptr[i+1];
			y1->child_ptr[y1->n] = y2;
		}
		return x->child_ptr[0];
	}
	else
		return NULL;
}

//5 7 9 11 10 8 2 14 6 15 16

int main()
{
    int i, n, t, d, choice;
    while(1)
    {
    	system("cls");
    	cout<<"\n1. Insert elements"
    	<<"\n2. Traverse through B+ Tree from root (index page)"
    	<<"\n3. Traverse through B+ Tree from leaf (record page)"
    	<<"\n4. Delete an element"
    	<<"\n5. Exit"
    	<<"\nEnter your choice: ";
    	cin>>choice;
    	switch(choice)
    	{
    		case 1:
    			cout<<"\nEnter the no of elements to be inserted\n";
			    cin>>n;
			    cout<<"\nEnter all "<<n<<" elements"<<endl;
			    for(i = 0; i < n; i++)
			    {
			        cin>>t;
			        insert(t);
			    }
			    x2 = connectall();
			    break;
			case 2:
				cout<<"\nTraversal of constructed tree\n";
				traverse(root);
				system("pause");
				break;
			case 3:
				cout<<"\nTraversal of constructed tree\n";
				traverseleaf(x2);
				cout<<endl;
				system("pause");
				break;
			case 4:
				cout<<"\nEnter element which you want to delete"<<endl;
				cin>>d;
				delete_item(d);
				break;
			case 5:
				exit(0);
    	}
    }
    return 0;
}
