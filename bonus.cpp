#include<iostream>
#include<algorithm>
#include<fstream>
#include<unordered_set>
#include<unordered_map>
#include<utility>
#include<queue>
using namespace std;
typedef pair<double,double> pdd;
namespace std
{
    template <>
    struct hash<pdd>
    {
        size_t operator()(const pair<double, double>& p) const
        {
            return hash<double>()(p.first) ^ hash<double>()(p.second);
        }
    };
}
bool operator<(pdd a,pdd b){
	return (a.first+a.second) < (b.first+b.second);
}
int size = 0;
double *arr1,*arr2;
void readFile(){
	ifstream GetText("bonus.txt");
	GetText >> size;
	//cout << length << endl;
	arr1 = new double[size];
	arr2 = new double[size];
	for(int i = 0;i<size;i++)
		GetText >> arr1[i];
	for(int i = 0;i<size;i++)
		GetText >> arr2[i];
	return;

}
int main(){
	readFile();
	//cout << arr1[0] << endl;
	//cout << arr2[1] << endl;
	sort(arr1,arr1+size);
	sort(arr2,arr2+size);
	//cout << arr1[0] << endl;
	//cout << arr2[1] << endl;
	//cout << arr1[0]+arr2[1] << endl;
	priority_queue<pdd> pq;
	unordered_set<pdd> htable;
	unordered_map<double,int> retableA;
	unordered_map<double,int> retableB;
	pq.push(make_pair(arr1[0],arr2[0]));
	htable.insert(make_pair(arr1[0],arr2[0]));
	retableA[arr1[0]] = 0;
	retableB[arr2[0]] = 0;
	for(int i = 0;i<3;i++){
		pdd aux = pq.top();
		while(!pq.empty() && htable.find(aux)!=htable.end()){
			pq.pop();
			aux = pq.top();
		}
		htable.insert(aux);
		int cura = retableA[aux.first];
		int curb = retableB[aux.second];
		cout << aux.first + aux.second<< endl;
		cout << cura << " " << curb << endl;
		//pq.pop();
		//cout << pq.top().first +pq.top().second << endl;
		pq.push(make_pair(arr1[cura],arr2[curb+1]));
		pq.push(make_pair(arr1[cura+1],arr2[curb]));
		cout << "inside: "<<pq.size() << endl;
		retableA[arr1[cura+1]] = cura+1;
		retableB[arr2[curb+1]] = curb+1;
	}

	

}