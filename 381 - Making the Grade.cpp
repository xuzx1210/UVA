#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double standard_deviation(double *x, const double mean, int n){
    double sd=0;
    for(int i=0;i<n;++i){
        sd+=((x[i]-mean)*(x[i]-mean));
    }
    sd=sqrt(sd/(double)n);
    if(sd<1){
        sd=1;
    }
    return sd;
}
int penalty(int level, int absence){
    if(absence==0){
        ++level;
        return (level>4)?4:level;
    }
    int result=level-(absence>>2);
    return (result>0)?result:0;
}
int main(){
    cout<<"MAKING THE GRADE OUTPUT"<<endl;
    int n;
    cin>>n;
    for(int cls=0;cls<n;++cls){
        int s, t;
        cin>>s>>t;
        int grade[s][t];
        int bonus[s], absence[s];
        for(int i=0;i<s;++i){
            for(int j=0;j<t;++j){
                cin>>grade[i][j];
            }
            cin>>bonus[i]>>absence[i];
        }

        double student_mean[s];
        for(int i=0;i<s;++i){
            if(t>2){
                double min=100, sum=0;
                for(int j=0;j<t;++j){
                    sum+=grade[i][j];
                    if(grade[i][j]<min){
                        min=grade[i][j];
                    }
                }
                sum-=min;
                student_mean[i]=sum/(double)(t-1);
            }else{
                double sum=0;
                for(int j=0;j<t;++j){
                    sum+=grade[i][j];
                }
                student_mean[i]=sum/(double)t;
            }
            student_mean[i]=floor(student_mean[i]);
        }

        double class_mean=0;
        for(int i=0;i<s;++i){
            class_mean+=student_mean[i];
        }
        class_mean/=(double)s;
        double sd=standard_deviation(student_mean, class_mean, s);

        for(int i=0;i<s;++i){
            double b=bonus[i]>>1;
            b*=3;
            student_mean[i]+=b;
        }
        int level[s];
        for(int i=0;i<s;++i){
            if(student_mean[i]>=class_mean+sd){
                level[i]=4;
            }else if(student_mean[i]>=class_mean){
                level[i]=3;
            }else if(student_mean[i]>=class_mean-sd){
                level[i]=2;
            }else{
                level[i]=1;
            }
        }
        for(int i=0;i<s;++i){
            level[i]=penalty(level[i], absence[i]);
        }

        double avg=0;
        for(int i=0;i<s;++i){
            avg+=level[i];
        }
        avg/=(double)s;
        
        cout<<fixed<<setprecision(1)<<avg<<endl;
    }
    cout<<"END OF OUTPUT"<<endl;
    return 0;
}