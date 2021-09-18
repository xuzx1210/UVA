#include<iostream>
using namespace std;
class Date{
public:
    int day, month, year;
};
int gap(Date &today, Date &birthday){
    int result=today.year-birthday.year;
    if(today.month<birthday.month){
        --result;
    }else if(today.month==birthday.month){
        if(today.day<birthday.day){
            --result;
        }
    }
    return result;
}
int main(){
    int T;
    cin>>T;
    for(int t=0;t<T;++t){
        Date today, birthday;
        char slash;
        cin>>today.day>>slash>>today.month>>slash>>today.year;
        cin>>birthday.day>>slash>>birthday.month>>slash>>birthday.year;
        int age=gap(today, birthday);
        cout<<"Case #"<<t+1<<": ";
        if(age<0){
            cout<<"Invalid birth date"<<endl;
        }else if(age>130){
            cout<<"Check birth date"<<endl;
        }else{
            cout<<age<<endl;
        }
    }
    return 0;
}