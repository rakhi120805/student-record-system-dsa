#include<iostream>
using namespace std;

struct Student
{
    string name;
    int roll_no;
    int marks;
    string section;
};
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
    bool found=false;
    int st=-1;
    for(int i=0;i<count;i++){
        if(roll==arr[i].roll_no){
            found=true;
            st=i;
            break;
        }
    }
    if(found==true){
        cout<<arr[st].roll_no<<" "<<arr[st].name<<" "<<arr[st].section<<" "<<arr[st].marks<<endl;
    }
    else{
        cout<<"Student not found";
    }
    return st;

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


int main(){
    int count=0;
    int n=100;
    Student arr[n];
    int a,b,c,d,e;
    int options;
    cout<<"Please choose the below options: "<<endl;
    cout<<"a-> Add a new student "<<endl;
    cout<<"b-> Display the details of the students of the school"<<endl;\
    cout<<"c-> Search a student "<<endl;
    cout<<"d->  "<<endl;
    

    cin>>options;
    if(options==a){
        add_students(arr,count);
    }
    else if(options==b){
        display_student_details(arr,count);
    }
    else if(options==c){

    }
    



}
