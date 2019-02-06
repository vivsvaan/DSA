#include <fstream>
#include <stdlib.h>
#include <string.h>
#include<iostream>
using namespace std;
  struct BSTnode {
        char word[128];
        struct BSTnode *left, *right;
  };

  struct BSTnode *root = NULL;

  struct BSTnode *createNode(char *word) {
        struct BSTnode *newnode;
        newnode = (struct BSTnode *)malloc(sizeof(struct BSTnode));
        strcpy(newnode->word, word);
        newnode->left = newnode->right = NULL;
        return newnode;
  }

  void insert(char *word)
   {
        struct BSTnode *parent = NULL, *current = NULL, *newnode = NULL;
        int res = 0;
        if (!root)
		{
                root = createNode(word);
                return;
        }
        for (current = root; current !=NULL;current = (res > 0) ? current->right : current->left)
		   {
                res = strcasecmp(word, current->word);
                if (res == 0) {
                        cout<<"Duplicate entry!!\n";
                        return;
                }
                parent = current;
           }
        newnode = createNode(word);
        res > 0? (parent->right = newnode) : (parent->left = newnode);
        return;
  }
  void inorderTraversal(struct BSTnode *myNode)
  {
        if (myNode)
		{
                inorderTraversal(myNode->left);
                cout<<myNode->word;
                cout<<"\n";
                inorderTraversal(myNode->right);
        }
        return;
  }

  void write2file(char *word)
  {
  	fstream file;
  	file.open("dict", ios::app | ios::out);
  	file<<word;
  	file.close();
  }

  void readfromfile()
  {
  	fstream file;
  	char line[100];
  	file.open("dict", ios::in);
  	if(!file)
  	{
  		cout<<"\nfile not found\n";
  		system("pause");
  		return;
  	}
  	file.seekg(0, ios::beg);
  	file.getline(line, 100);
  	//insert(line);
  	while(!file.eof())
  	{
  		file.getline(line, 100);
  		insert(line);
  	}
  	file.close();
  }

  int main()
  {
        int ch;
        char str[128];
        while (1) {
                cout<<"****************DICTIONARY******************\n1. Insert new words\n2. Traverse\n3. Load previous data\n";
                cout<<"4. Exit\nEnter ur choice:";
                cin>>ch;
                getchar();
                switch (ch) {
                        case 1:
                                cout<<"Word to insert:";
                                fgets(str, 100, stdin);
                                insert(str);
                                write2file(str);
                                break;
                        case 2:
                                inorderTraversal(root);
                                break;
                        case 3:
                        		readfromfile();
                        		break;
                        case 4:
                                exit(0);
                        default:
                                cout<<"You have entered wrong option\n";
                                break;
                }
        }
        return 0;
  }
