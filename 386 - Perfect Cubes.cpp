#include<cstdio>
using namespace std;
int main(){
    for(int a=6;a<=200;++a){
        int A=a*a*a;
        for(int b=2;b<a;++b){
            int B=b*b*b;
            if(A<3*B){
                break;
            }
            for(int c=b;c<a;++c){
                int C=c*c*c;
                if(A<B+2*C){
                    break;
                }
                for(int d=c;d<a;++d){
                    int D=d*d*d;
                    int E=B+C+D;
                    if(A<E){
                        break;
                    }
                    if(A==E){
                        printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
                    }
                }
            }
        }
    }
    return 0;
}