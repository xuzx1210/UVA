#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class information{
public:
    string title;
    string firstName;
    string lastName;
    string address;
    string department;
    string homePhone;
    string workPhone;
    string campusBox;
};
int main(){
    int n;
    cin>>n;
    vector<information> people;
    string tmp;
    getline(cin, tmp);
    for(int i=0;i<n;++i){
        string department;
        getline(cin, department);
        string line;
        while(getline(cin, line)){
            if(line==""){
                break;
            }
            int comma[6];
            for(int i=0, j=0;i<line.length() && j<6;i++){
                if(line[i]==','){
                    comma[j]=i;
                    ++j;
                }
            }
            information person;
            string title(line, 0, comma[0]);
            string firstName(line, comma[0]+1, comma[1]-comma[0]-1);
            string lastName(line, comma[1]+1, comma[2]-comma[1]-1);
            string address(line, comma[2]+1, comma[3]-comma[2]-1);
            string homePhone(line, comma[3]+1, comma[4]-comma[3]-1);
            string workPhone(line, comma[4]+1, comma[5]-comma[4]-1);
            string campusBox(line, comma[5]+1, line.length()-comma[5]-1);
            person.title=title;
            person.firstName=firstName;
            person.lastName=lastName;
            person.address=address;
            person.department=department;
            person.homePhone=homePhone;
            person.workPhone=workPhone;
            person.campusBox=campusBox;
            people.push_back(person);
        }
    }
    for(int i=0;i<people.size()-1;++i){
        for(int j=i+1;j<people.size();++j){
            if(people[i].lastName.compare(people[j].lastName)>0){
                swap(people[i], people[j]);
            }
        }
    }
    for(int i=0;i<people.size();++i){
        cout<<"----------------------------------------"<<endl;
        cout<<people[i].title<<" "<<people[i].firstName<<" "<<people[i].lastName<<endl;
        cout<<people[i].address<<endl;
        cout<<"Department: "<<people[i].department<<endl;
        cout<<"Home Phone: "<<people[i].homePhone<<endl;
        cout<<"Work Phone: "<<people[i].workPhone<<endl;
        cout<<"Campus Box: "<<people[i].campusBox<<endl;
    }
    return 0;
}