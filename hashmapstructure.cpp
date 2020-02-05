#include<iostream>
#include<vector>
using namespace std;


class Hashtable{
public:
	vector<int,pair<int,int> > data;
	int get(int key){
		return data[key];
	}
	void put(int key, int value){
		data.push_back(key, pair<int,int>(key,value);
	}
};
int main(){

	Hashtable myhash;
	myhash.put(2, make_pair(3,4));
	myhash.get(2);
	return 0;
}
