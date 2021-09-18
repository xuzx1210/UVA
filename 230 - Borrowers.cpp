#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Book{
public:
	Book(string line){
		this->borrowed=false;
		this->returned=false;
		int by=line.find("by");
		string t(line, 0 ,by-1);
		this->title=t;
		string a(line, by+3, line.length()-by+3);
		this->author=a;
	}
	string title;
	string author;
	bool borrowed;
	bool returned;
};
int main(){
	string line;
	vector<Book> lib;
	getline(cin, line);
	for(;line!="END";getline(cin, line)){
		Book book=Book(line);
		bool inserted=false;
		for(int i=0;i<lib.size();++i){
			int ca=book.author.compare(lib[i].author);
			if(ca<0){
				lib.insert(lib.begin()+i, book);
				inserted=true;
				break;
			}else if(ca==0){
				int ct=book.title.compare(lib[i].title);
				if(ct<0){
					lib.insert(lib.begin()+i, book);
					inserted=true;
					break;
				}
			}
		}
		if(!inserted){
			lib.push_back(book);
		}
	}
	getline(cin, line);
	for(;line!="END";getline(cin, line)){
		if(line=="SHELVE"){
			for(int i=0;i<lib.size();++i){
				if(lib[i].returned){
					bool put=false;
					for(int j=i-1;j>=0;--j){
						if(!lib[j].borrowed){
							cout<<"Put "<<lib[i].title<<" after "<<lib[j].title<<endl;
							lib[i].borrowed=false;
							lib[i].returned=false;
							put=true;
							break;
						}
					}
					if(!put){
						cout<<"Put "<<lib[i].title<<" first"<<endl;
						lib[i].borrowed=false;
						lib[i].returned=false;
					}
				}
			}
			cout<<"END"<<endl;
			continue;
		}
		string action(line, 0, 6);
		string title(line, 7, line.length()-7);
		for(int i=0;i<lib.size();++i){
			if(lib[i].title==title){
				if(action=="BORROW"){
					lib[i].borrowed=true;
				}else if(action=="RETURN"){
					lib[i].returned=true;
				}
				break;
			}
		}
	}
	return 0;
}
