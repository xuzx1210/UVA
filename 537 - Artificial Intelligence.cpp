#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
using namespace std;
double value(string data){
    stringstream ss(data);
    double real_number;
    char prefix;
    ss>>real_number>>prefix;
    switch(prefix){
    case 'm':
        real_number*=0.001;
        break;
    case 'k':
        real_number*=1000.0;
        break;
    case 'M':
        real_number*=1000000.0;
        break;
    default:
        break;
    }
    return real_number;
}
int main(){
    int n;
    cin>>n;
    string line;
    getline(cin, line);
    for(int t=0;t<n;++t){
        getline(cin, line);
        stringstream ss(line);
        string data_field;
        bool found=false;
        bool I=true, U=true, P=true;
        double current, voltage, power;
        while(ss>>data_field){
            if(data_field.length()<4){
                continue;
            }
            if(data_field[1]=='='){
                string data(data_field.begin()+2, data_field.end());
                switch(data_field[0]){
                case 'I':
                    I=false;
                    current=value(data);
                    break;
                case 'U':
                    U=false;
                    voltage=value(data);
                    break;
                case 'P':
                    P=false;
                    power=value(data);
                    break;
                }
                if(found){
                    break;
                }else{
                    found=true;
                }
            }
        }
        cout<<"Problem #"<<t+1<<endl;
        if(I){
            current=power/voltage;
            cout<<"I="<<fixed<<setprecision(2)<<current<<'A'<<endl;
        }else if(U){
            voltage=power/current;
            cout<<"U="<<fixed<<setprecision(2)<<voltage<<'V'<<endl;
        }else{
            power=current*voltage;
            cout<<"P="<<fixed<<setprecision(2)<<power<<'W'<<endl;
        }
        cout<<endl;
    }
    return 0;
}