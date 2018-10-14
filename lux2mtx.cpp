#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdint.h>
#include <stdlib.h>
using namespace std;
typedef uint32_t V_IDX;
typedef uint64_t E_IDX;
struct Edges{
    V_IDX src,dst;
};
int main(int argc,char * * argv){
    string fileName;
    fileName=string(argv[1]);
    ifstream fin(fileName.c_str(),ios_base::in|ios_base::binary);
    V_IDX nv;
    E_IDX ne;
    fin.read((char *)&nv,sizeof(V_IDX));
    fin.read((char *)&ne,sizeof(E_IDX));
    E_IDX * row_ptrs=(E_IDX *)malloc(((size_t)nv)*sizeof(E_IDX));
    fin.read((char *)row_ptrs,sizeof(E_IDX)*nv);
    fileName=string(argv[2]);
    ofstream fout(fileName.c_str(),ios_base::out);
    int startId=0;
    for(int i=0;i<nv;i++)
    {
        int endId=row_ptrs[i];
        //cout<<"node:"<<i<<endl;
        //cout<<startId<<"-"<<endId<<endl;
        for(int j=startId;j<endId;j++)
        {
            V_IDX temp;
            fin.read((char *)&temp,sizeof(V_IDX));
            Edges edg;
            edg.src=temp;
            edg.dst=i;
          //  cout<<edg.src<<" "<<edg.dst<<endl;
            fout<<edg.src<<" "<<edg.dst<<endl;
            //fout.write((char *)&edg,sizeof(Edges));
        }
        //cout<<"--------------"<<endl;
        startId=endId;
    }
    fin.close();
    fout.close();
    return 0;
}
