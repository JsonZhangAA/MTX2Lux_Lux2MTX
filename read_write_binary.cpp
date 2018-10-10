#include<iostream>
#include<fstream>
#include <string>
using namespace std;
int main(void){
    string fileNameI="In.txt";
    string fileNameO="Out.txt";
    ofstream ofd(fileNameO.c_str(),ios_base::out|ios_base::binary);
    ifstream ifd(fileNameI.c_str(),ios_base::in|ios_base::binary);
    if(ifd.is_open()&&ofd.is_open()){
        int temp;
        while(ifd>>temp){
            cout<<temp<<endl;
            ofd.write((char *)&temp,sizeof(int));
        }
    }
    ifd.close();
    ofd.close();
    ifd.open(fileNameO.c_str(),ios_base::in|ios_base::binary);
    int temp;
    cout<<"check:"<<endl;
    if(ifd.is_open())
	    while(ifd.read((char *)&temp,sizeof(int))){
	    	cout<<temp<<endl;
		}
	else
		cout<<"open fileO failed"<<endl;
	ifd.close();
    return 0;
}
