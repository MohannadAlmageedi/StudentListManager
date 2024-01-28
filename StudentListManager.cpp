#include <iostream>
#include<fstream>
using namespace std;

class StudentList
{
	struct Student
	{
		string name;
		int number;
		int grade;
		Student*next;
	};
	
	Student*first;
	Student*rear;
	
	public:
		StudentList()
		{
			first=rear=NULL;
		}
		
	bool isEmpty()
	{
		return first==NULL;
	}
	

	void addStudent(ofstream&file)
	{
		Student*newStudent=new Student;
		cout<<"Type your name"<<endl;
		cin>>newStudent->name;
		cout<<"Type your number"<<endl;
		cin>>newStudent->number;
		cout<<"Type your grade"<<endl;
		cin>>newStudent->grade;
		
		file<<newStudent->name<<" "<<newStudent->number<<" "<<newStudent->grade<<endl;
		if(isEmpty())
		{
			first=rear=newStudent;
			newStudent->next=NULL;
		}
		else
		{
			rear->next=newStudent;
			rear=newStudent;
			newStudent->next=NULL;
		}
	}
	
	Student* searchStudent(const string& sname)
	{
		Student*temp=first;
		while(temp!=NULL)
		{
			if(temp->name==sname)
				return temp;
			else
				temp=temp->next;
		}//end while
		return NULL;
	}//end search function
	
	/*
	Student* searchStudent(const string& sname)//using binary search algorithm
{
    if (isEmpty())
        return nullptr;

    int low = 0;
    int high = getSize() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (sname == getStudent(mid)->name) {
            return getStudent(mid);
        } else if (sname < getStudent(mid)->name) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return nullptr;
}
*/

	void deleteStudent()
	{
		string sname;
		cout<<"Type name to delete"<<endl;
		cin>>sname;
		
		Student*temp=searchStudent(sname);
		
		if(temp!=NULL)
		{
			if(temp==first)
			//if a student at first
			first=temp->next;
			
			else//if a student at middle or at end
			{
			Student*prev=first;
			
			while (prev->next!=temp)
			{
				prev=prev->next;
			}
			prev->next=temp->next;//to make previous pointer moves to last node
			
			if(prev->next==NULL)//if a student at end [this command to make rear points to previous node
			rear=prev;
			}//end else condition
		
		
		temp->next=NULL;
		delete temp;
		
		
		cout<<"Student delete successfully"<<endl;
		}//end if condition
		else
		cout<<"Student not found"<<endl;
		
	}//end delete function
	
	void rest()//to rest data of a student
	{
		string sname;
		cout<<"Enter name to re-write his information"<<endl;
		cin>>sname;
		
		Student*temp=searchStudent(sname);
		if(temp!=NULL)
		{
			cout<<"Type new name of student"<<endl;
		cin>>temp->name;
		cout<<"Type new number of student"<<endl;
		cin>>temp->number;
		cout<<"Type new grade of student"<<endl;
		cin>>temp->grade;
		
		}
		else
		{
			cout<<"Inorrect Input"<<endl;
		}
	}
	
	
	void print()
	{
		int count=0;
		Student*cur=first;
		while(cur!=NULL)
		{
			
			count++;
			cout<<"Information "<<count<<endl;
			cout<<"name: "<<cur->name<<endl;
			cout<<"number: "<<cur->number<<endl;
			cout<<"grade: "<<cur->grade<<endl<<endl;
			cur=cur->next;
		}
		cout<<endl;
	}
	
};
int main()
{
	ofstream file;
	file.open("Mohannad.text");
	if(file.fail()){return 0;}
	
	StudentList l;
	int choice;
	do
	{
		cout<<"*******************************************"<<endl;
		cout<<"If you want to add a new Student press [1]"<<endl;
		cout<<"If you want to print all Student press [2]"<<endl;
		cout<<"if you want to delete a student press  [3]"<<endl;
		cout<<"If you want to rest information press  [4]"<<endl;
		cout<<"If you want to Exit press number       [5]"<<endl;
		cout<<"*******************************************"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				l.addStudent(file);
				break;
				
				case 2:
					l.print();
					break;
					
					case 3:
						l.deleteStudent();
						break;
						
						case 4:
							l.rest();
							break;
							case 5:
								cout<<"Exiting..."<<endl;
								break;
						default:
							cout<<"Invalid choice"<<endl;
				
		}//end switch
	
	}//end do while
	while (choice!=5);
	
}