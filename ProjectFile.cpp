#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;

int size=0;
bool static found=false;

void Check(string ans,string ch,int n,int nf)
{
	bool flag=false;
	int i=0;
	for(i=0;i<n;i++)
	{
		if(ch[i]!='.')
		{
			if(ch[i]==ans[i])
			{
				flag=true;
			}
			else 
			{
				flag=false;
			}
			if(flag==false && ch[i]!='.')
			{
				return;
			}
		}
	}
	if(flag==true)
	{
		if(nf==n)
		{
			if(found==false)
			{
				cout<<"\nMatching Words:\n";
				found=true;
			}
			for(int i=0;i<n;i++)
			{
				cout<<ans[i];
			}
			cout<<endl;	
		}
		
	}
}

void Check2(string reg, string text)
{
	int i, rlen, tlen, f = 0,flg=0,tempIndex;
    int starIndex = 0, tempin; 
    rlen = reg.length();
	tlen = text.length();
	
	for(int j =0; j<rlen; j++)
	{
		if(reg[j]=='*')
			starIndex = j;		
	}
	       if (reg[0] == '*' )
           {  
    	        tempin = tlen-1;
            	for(int i=rlen-1; i>0; i--,tempin--)
            	{
            		if(reg[i]==text[tempin])
            		{	f=1;	}
					else
					{	f=0;	break;	}       	               	           
				}
				
				if(f==1) 
				{
					if(found==false)
					{
						cout<<"\nMatching Words:\n";
						found=true;
					}
					cout<<text<<endl; found=true;
				}
            	  
           }
                       
    if(reg[1]=='.')
	  exit(0);
			   
    if ((reg[0] >= 65 && reg[0] <= 90) || (reg[0] >= 97 && reg[0] <=122))
    {
        if (reg[0] == text [0])
        {             
            		
			if(reg[rlen-1]=='*')
			{   
				    
				    if(rlen == 2 && reg[0] == text[0])
				    {
						if(found==false)
						{
							cout<<"\nMatching Words:\n";
							found=true;
						} 
						cout<<text<<endl; found = true;		
					}   
					
					for(int i = 1; i<rlen-1; i++)
					{
						if(reg[i]==text[i])
						   f=1;
						else
						  {  f=0; break; }						       
					}
					
					if(f==1)
					{ 
						if(found==false)
						{
							cout<<"\nMatching Words:\n";
							found=true;
						}
						cout<<text<<endl; found = true;	  
					} 
			}           
			         
			else{
			
			    if(reg[1] == '*')
				{  
					tempIndex=tlen-1;
					for(int i =rlen-1; i>starIndex; i--,tempIndex--)
				    {
				    	if(reg[i] == text[tempIndex])
				    	  { f = 1;  }
				    	else{	  f = 0; break;	 }																 	    
					}
					if(f==1)
    			    {  
						if(found==false)
						{
							cout<<"\nMatching Words:\n";
							found=true;
						}
						cout<<text<<endl;	found=true;	return;		  
					} 	
				}  
				else
				{
				 f=1;
				 for(int j =1; j<starIndex; j++)
				 {
					if( reg[j] == text[j])
						f = 1;
					else
					{ f = 0; break;	}			
				 }
			      tempIndex=tlen-1;
				  if(f==1)
				  {   
				    for(int i =rlen-1; i>starIndex; i--,tempIndex--)
				    {
				    	if(reg[i] == text[tempIndex])
				    	  flg = 1;
				    	else{
				    		flg = 0; break;
						}						  					 	    
					}
					
					if(flg==1)
    			    {
						if(found==false)
						{
							cout<<"\nMatching Words:\n";
							found=true;
						}
						cout<<text<<endl;	found=true;	return;		  
					} 					
				}
			    
				}
			} 
				 
            }
        else{}
		
    }	
}

class Node
{
	public:
		
		Node *Next;
		string Data;
		
		Node()
		{
			size++;
			this->Next=NULL;
			this->Data="q";
		}
		
		Node(Node *N, string d)
		{
			this->Next=N;
			this->Data=d;
		}
		
		Node(string data)
		{
			this->Next=NULL;
			this->Data=data;
		}

};

class LinkedList
{
	public:
		
		Node *head=NULL;
		Node *tail=NULL;
		
		bool InsertAtHead(Node *newNode)
		{
			if(head==0)
			{
				head=newNode;
				tail=newNode;
				return true;
			}
			else
			{
				newNode->Next=head;
				head=newNode;
				return true;
			}
		}
		
		bool InsertAtTail(Node *newNode)
		{
			Node *temp=head;
			if(temp!=0)
			{
				while(temp->Next!=0)
				{
					temp=temp->Next;
				}
				temp->Next=newNode;
				tail=newNode;
				return true;
			}
			else
			{
				temp->Next=newNode;
				tail=newNode;
				return true;
			}
		}
		
		bool DeleteFromHead()
		{
			if (head==NULL)
      		{	cout << "list is empty!\n";	}
  			else 
			{
    			Node *Ptr = head;
     			head = head->Next; 
     			size--;
     			
			}
			return true;
		}
		
		bool DeleteFromTail()
		{
		    if (head==0)
  			{	cout << "Error: list is empty!\n";		}
  			Node *ptr = head;
  			while(ptr->Next !=0) 
			{
				ptr=ptr->Next; 
			}
  			ptr->Data="q";
  			ptr->Next=NULL;
  			size--;
  			
  			return true;
		}
			
		bool DeleteFromIndex(int p)
		{
			if(p==0)
			{
				DeleteFromHead();
				return true;
			}
			else
			{
				Node *temp=head;
				Node *ptr;
				for(int i=0;i<p;i++)
				{
					ptr=temp;
					temp=temp->Next;
				}
				ptr->Next=temp->Next;
				temp=0;
				return true;
			}
		}

};

class HashMap
{
	private:
	
		int H_Size; 
	    LinkedList *table; 
    
	public: 
	
	    HashMap()
	    {
		    this->H_Size = 100; 
		    table = new LinkedList[H_Size]; 	
		}
	    
		void insertItem(string key)
		{
			int index = hashFunction(key); 
			Node *n=new Node(key);
		    
		    if(table[index].head==0)
		    {	table[index].InsertAtHead(n);	}
			else
			{	table[index].InsertAtTail(n);	}	
		}
		
	    void deleteItem(string key)
		{
			int index = hashFunction(key); 
		  	int i=0;
		  	string a="q";
		  	Node *te=table[index].head;
		  	
			while(a!=key)
			{
				if(i==H_Size)
				{cout<<"\n\nError!, Word Not Found"; break;}
				
				else if(te->Data==key)
				{
					table[index].DeleteFromIndex(i);
					a=key;
				}
				i++;
			}
		}  
	    
		int hashFunction(string x)
		{
			int s=x.length();
			int sum=0;
			for(int i=0;i<s;i++)
			{
				sum=sum+x[i];
			}
			
			sum=sum%H_Size;
			return sum;	
		}
	    
		void displayHash()
		{
			for(int i=0;i<H_Size;i++)
			{
				cout<<"\n"<<i<<"] ";
				Node *n = table[i].head;
				while(n!=0)
				{	
					cout<<" --> "<<n->Data;
					n=n->Next;		
				}
			}	
		} 
		
		void DeleteTable()
		{
			for(int i=0;i<100;i++)
			{
				while(table[i].head!=0)
				{
					table[i].DeleteFromHead();
				}
			}
		}
		
		bool StartSearching1(string name)//for *
		{
			string word;
			for(int i=0;i<100;i++)
			{
				Node *n=table[i].head;
				while(n!=0)
				{
					word=n->Data;
					Check2(name, word);
					n=n->Next;
				}
			}
			if(found==false)
			{	cout<<"\nEntered Name Is Not Found!\n";	}
			
			cout<<"\n\nPress Any Key To Continue............!";
			getch();
			return true;
		}
		
		bool StartSearching2(string name)//for .
		{
			string word;
			for(int i=0;i<100;i++)
			{
				Node *n=table[i].head;
				while(n!=0)
				{
					word=n->Data;
					Check(word, name, name.length(), word.length());
					n=n->Next;
				}
			}
			if(found==false)
			{	cout<<"\nEntered Name Is Not Found!\n";	}
			
			cout<<"\n\nPress Any Key To Continue............!";
			getch();
			return true;
		}
		
		bool StartSearching3(string name)// for simple word
		{
			for(int i=0;i<100;i++)
			{
				Node *n = table[i].head;
				while(n!=0)
				{	
					if(n->Data==name)
					{	cout<<"\nMatching Words:\n"<<n->Data<<"\n\nPress Any Key To Continue............!"; getch(); return true;	}
					n=n->Next;		
				}
			}
			cout<<"\nEntered Name Is Not Found!";
			cout<<"\n\nPress Any Key To Continue............!";
			getch();
			return false;	
		}
		
};

HashMap MyTable;

bool Exceptions(string name)
{
	if(name.length()==1)
	{	cout<<"Sorry You Have Entered Only One Character, Please Write Word!";	getch(); return false;	}
	if(name[0]>90 && name[0]<97 || name[0]<65 || name[0]>122)
	{	
		if(name[0]!=42 && name[0]!=46)
		{	cout<<"Sorry, Please Enter Characters Not Other Symbols Or Numbers!";	getch(); return false;	}
		else
		{	return true;		}	
	}
	return true;
}

int SignChecking(string name)
{
	int a=0, b=0;
	
	for(int j=0;j<name.length();j++)
	{
		if(name[j]=='*')
		{	a++;	}
		else if(name[j]=='.')
		{	b++;	}
	}
	if(a!=0 && b!=0)
	{
		cout<<"\n\nInvalid Entry, Please Write Any One Sign!\n\nPress Any Key to Continue...........................!";
		getch();
		return 0;
	}
	else
	{
		for(int i=0;i<name.length();i++)
		{
			if(name[i]=='*')
			{	return 1;	}
			else if(name[i]=='.')
			{	return 2;	}
		}
		return 3;
	}

}

bool TakeInput(string name)
{
	if(name[0]!='*' && name[0]!='.')
	{
		string temp;
		int i=0;
		string filename="q";
		filename[0]=name[0];
		filename += ".txt";
		
		std::ifstream infile;
		infile.open(filename.c_str());
		while(!infile.eof())
		{
			infile>>temp;
			MyTable.insertItem(temp);
		}
		infile.close();
		return true;
	}
	else
	{	return false;	}
}

void OpenAllFiles()
{
	string temp;
	int i=0;
	
	for(int i=97; i<123; i++)
	{
		string filename="q";
		filename[0]=i;
		filename += ".txt";
		
		
		std::ifstream infile;
		infile.open(filename.c_str());
		while(!infile.eof())
		{
			infile>>temp;
			MyTable.insertItem(temp);
		}
		infile.close();
	}
	
	return;
}

void Instruction()
{
	system("cls");
	
	cout<<"Overview:\n\nA regular expression (sometimes called a rational expression) is a sequence of characters that define a search pattern\nThis is mainly for use in pattern matching with strings, or string matchings\nGiven a series of text or dataset we can shorten and improve our searching using different symbols\nThat Symbols corresponds to a specific conditions for searching in a given dataset\n";
	cout<<"\n\nInput Instruction:\n";
	cout<<"1)  ( * ) means any length of string\n";
	cout<<"2)  ( . ) means a single character\n\n";
	cout<<"Some Example:\n\n[Input: *khan] == [Output: Imran khan, Nadeem khan, Sharukh khan and all those words that ends on khan]\n";
	cout<<"[Input: r*e] == [Output: race, rare, rage and all those words that starts with r or ends on e]\n"; 
	cout<<"[Input: f*] == [Output: fame, fake, far and all those words that starts with f]\n";
	cout<<"[Input: .an] == [Output: fan, man, ban and all those word whose 2,3 character is an\n";
	cout<<"[Input: r..e] == [Output: race, rare, and all those word that starts with r or have total 4 characters and ends on e]\n"; 
	cout<<"[Input: f..] == [Output: fan, fry, far and all those word that starts with f and have total 3 characters]\n";
	cout<<"\n\nPress Any Key To Continue............!";
	getch();	
	system("cls");
	return;
}

string ConvertLower(string n)
{
	for(int i=0;i<n.length();i++)
	{
		if(n[i]!='*' && n[i]!='.' && n[i]<96)
		{	n[i]=n[i]+32;	}
	}
	return n;
}

int main()
{	
	string name;
	int a, sign, op;
	bool check, complete=false;
	
	while(complete!=true)
	{
		system("cls");
		cout<<"**********************************!Basic Regular Expression Matching!**********************************\n\n";
		cout<<"\n\nWhat You Want To Do?\n\n1) Find A Word in Paragraph\n2) Find A Word in Files\n3) Instruction\n4) Exit\n\nType: ";
		cin>>a;
		
		if(a==1)
		{
			system("cls");
			string word;
			
			ifstream infile;
			infile.open("Paragraph.txt");
			
			cout<<"Your Paragraph:\n\n";
			while(!infile.eof())
			{
				infile>>word;
				cout<<word<<" ";
			}
			infile.close();
			cout<<"\n\n";
			cout<<"************************************\nEnter A Word That You Want To Find: ";
			cin>>name;
			check=Exceptions(name);
			if(check == true)
			{	
				sign=SignChecking(name);
				if(sign!=0)
				{
					string temp;
					
					std::ifstream infile;
					infile.open("Paragraph.txt");
					while(!infile.eof())
					{
						infile>>temp;
						MyTable.insertItem(temp);
					}
					infile.close();
					name=ConvertLower(name);
					
					if(sign==1)//for * sign
					{	MyTable.StartSearching1(name);	}
					else if(sign==2)//for . sign
					{	MyTable.StartSearching2(name);	}
					else if(sign==3)//for simple name
					{	MyTable.StartSearching3(name);	}
				}
				else
				{	continue;	}
			}
			
			system("cls");
			cout<<"Do You Want To Continue You Program\n\n1)Yes\n\nType: ";
			cin>>op;
			
			if(op!=1)
			{	cout<<"\nOk, GoodBye and Thankyou!";	 MyTable.DeleteTable(); 	complete=true;	}
			else
			{	MyTable.DeleteTable();		found=false; 	continue;		}
		}
		else if(a==2)
		{
			cout<<"************************************\nEnter A Word That You Want To Find: ";
			cin>>name;
			
			check=Exceptions(name);
			
			if(check == true)
			{	
				sign=SignChecking(name);
				if(sign!=0)
				{
					check=TakeInput(name);
					name=ConvertLower(name);
					
					if(check!=true)
					{	OpenAllFiles();		}
					
					if(sign==1)//for * sign
					{	MyTable.StartSearching1(name);		}
					else if(sign==2)//for . sign
					{	MyTable.StartSearching2(name);	}
					else if(sign==3)//for simple name
					{	MyTable.StartSearching3(name);	}
				}
				else
				{	continue;	}
			}
			system("cls");
			cout<<"Do You Want To Continue You Program\n\n1)Yes\n\nType: ";
			cin>>op;
			
			if(op!=1)
			{	cout<<"\nOk, GoodBye and Thankyou!";	 MyTable.DeleteTable(); 	complete=true;	}
			else
			{	MyTable.DeleteTable();		found=false; 	continue;		}
		}
		else if(a==3)
		{	Instruction();	}
		else if(a==4)
		{		cout<<"\nOk, GoodBye and Thankyou!";	complete=true;	}
		else
		{	cout<<"Wrong input!";	getch();}
	}
}
