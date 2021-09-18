#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class forwarding{
public:
    forwarding(int time, int duration, int target){
        insert(time, duration, target);
    }
    void insert(int time, int duration, int target){
        this->time.push_back(time);
        this->duration.push_back(duration);
        this->target.push_back(target);
    }
	vector<int> time;
	vector<int> duration;
	vector<int> target;
};
typedef unordered_map<int, class forwarding> umap;
void print(int time, int extension, int cur){
    cout<<"AT ";
    cout<<setw(4)<<setfill('0')<<time;
    cout<<" CALL TO ";
    cout<<setw(4)<<setfill('0')<<extension;
    cout<<" RINGS ";
    cout<<setw(4)<<setfill('0')<<cur<<endl;
}
int main(){
	int n;
	cin>>n;
	cout<<"CALL FORWARDING OUTPUT"<<endl;
	for(int system=1;system<=n;++system){
		cout<<"SYSTEM "<<system<<endl;
		int source;
        cin>>source;
        umap list;
        while(source){
            int time, duration, target;
            cin>>time>>duration>>target;
            umap::iterator pos=list.find(source);
            if(pos==list.end()){
                forwarding tmp_forwarding(time, duration, target);
                pair<int, class forwarding> tmp_pair(source, tmp_forwarding);
                list.insert(tmp_pair);
            }else{
                pos->second.insert(time, duration, target);
            }
            cin>>source;
        }
        int time;
        cin>>time;
        while(time!=9000){
            int extension;
            cin>>extension;
            int cur=extension;
            vector<int> found;
            while(true){
                vector<int>::iterator pos_found=find(found.begin(), found.end(), cur);
                if(pos_found!=found.end()){
                    print(time, extension, 9999);
                    break;
                }
                found.push_back(cur);
                umap::iterator pos_list=list.find(cur);
                if(pos_list==list.end()){
                    print(time, extension, cur);
                    break;
                }
                bool f=false;
                for(int i=0;i<pos_list->second.time.size();++i){
                    int start=pos_list->second.time[i];
                    int end=start+pos_list->second.duration[i];
                    if(start<=time && time<=end){
                        cur=pos_list->second.target[i];
                        f=true;
                        break;
                    }
                }
                if(!f){
                    print(time, extension, cur);
                    break;
                }
            }
            cin>>time;
        }
	}
	cout<<"END OF OUTPUT"<<endl;
	return 0;
}