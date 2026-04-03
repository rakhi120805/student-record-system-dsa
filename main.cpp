#include<iostream>
using namespace std;

struct Student
{
    string name;
    int roll_no;
    int marks;
    string section;
};
void swap(Student &a,Student &b){
    Student temp=a;
    a=b;
    b=temp;
}
void add_students(Student arr[],int &count){
    if(count == 100){
        cout<<"The maximum capacity of this school is already achieved.";
    }
    else{
            cin>>arr[count].name;
            cin>>arr[count].roll_no;
            cin>>arr[count].marks;
            cin>>arr[count].section;
            count++;
    }
}

void display_student_details(Student arr[],int &count){
    for(int i=0;i<count;i++){
        cout<<arr[i].roll_no<<" "<<arr[i].name<<" "<<arr[i].section<<" "<<arr[i].marks<<endl;
    }
}
int search_student(Student arr[],int count,int roll){
    
    for(int i=0;i<count;i++){
        if(roll==arr[i].roll_no){
            return i;
        }
    }
  
    return -1;

}
void remove_student(Student arr[],int &count,int roll){
    int pos=search_student(arr,count,roll);
    if(pos==-1){
        cout<<"Student does not exists";
    }
    else{
        for(int i=pos;i<count-1;i++){
            arr[i]=arr[i+1];
        }
        count--;
    }
    
}
int topper(Student arr[],int count){
    
    if(count == 0){
        cout<<"No student found";
        return -1;
    }
    int maxi=0;
    for(int i=1;i<count;i++){
        if(arr[i].marks>arr[maxi].marks){
            maxi=i;
        }
    }
    return maxi;
}
void update_details(Student arr[],int count,int roll){
    string newname;
    int newroll;
    int newmarks;
    string newsection;
    int index=search_student(arr,count,roll);
    if(count == 0 || index==-1){
        cout<<"No student found to update!!";
        return;
    }
    cout<<"choose what you have to change"<<endl;
    cout<<"1: To change the name"<<endl;
    cout<<"2: To change the roll number"<<endl;
    cout<<"3: To change the section"<<endl;
    cout<<"4: To change the marks"<<endl;

    int option;
    cin>>option;
    switch (option)
    {
    case (1):
        cout<<"Enter the new name: ";
        cin>>newname;
        arr[index].name=newname;
        break;
    case (2):
        cout<<"Enter the new roll number: ";
        cin>>newroll;
        arr[index].roll_no=newroll;
        break;
    case (3):
        cout<<"Enter the new section: ";
        cin>>newsection;
        arr[index].section=newsection;
        break;
    case (4):
        cout<<"Enter the new marks: ";
        cin>>newmarks;
        arr[index].marks=newmarks;
        break;
    
    default:
        cout<<"Invalid choice";
        break;
    }

}

void sort_students_by_marks(Student arr[],int count){
    for(int i=count;i>0;i--){
        for(int j=0;j<i-1;j++){
            if(arr[j].marks>arr[j+1].marks){
                swap(arr[j],arr[j+1]);
            }
        }
    }

}

void print_menu(){
    cout<<"Please choose the below options: "<<endl;
    cout<<"1-> Add a new student."<<endl;
    cout<<"2-> Display the details of the students of the school."<<endl;\
    cout<<"3-> Search a student."<<endl;
    cout<<"4-> Remove a student details. "<<endl;
    cout<<"5-> Know the topper's mark. "<<endl;
    cout<<"6-> Update a student details. "<<endl;
    cout<<"7-> sort the student details. "<<endl;
    cout<<"0-> Exit. "<<endl;
}

int main(){
    int count=0;
    int n=100;
    Student arr[n];

    int choice;
    int roll;
    int ind;
    
    do{ 
        print_menu();
        cin>>choice;
        switch (choice)
        {
        case (1):
            add_students(arr,count);
            break;
        case (2):
            display_student_details(arr,count);
            break;
        case (3):
            
            cout<<"Enter the roll number: ";
            cin>>roll;
            ind=search_student(arr,count,roll);
            cout<<arr[ind].name<<" "<<arr[ind].roll_no<<" "<<arr[ind].section<<" "<<arr[ind].marks<<endl;
            break;
        case (4):
            cout<<"Enter the roll number: ";
            cin>>roll;
            remove_student(arr,count,roll);
            break;
        case (5):
            ind=topper(arr,count);
            if(ind!=-1)cout<<arr[ind].name<<" : "<<arr[ind].marks<<endl;
            else cout<<"Topper not exists";
            break;
        case (6):
            cout<<"Enter the roll number: ";
            cin>>roll;
            update_details(arr,count,roll);
            break;
        case (7):
            sort_students_by_marks(arr,count);
            break;
        case (0):
            cout<<"exiting ... ";
            break;
        default:
            cout<<"Invalid choice";
            break;
        }

    }
    while(choice!=0);
    



}
