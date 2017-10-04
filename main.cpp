#include<iostream>
#include<fstream>
#include<cassert>
#include<string>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<malloc.h>
using namespace std;
int readNum(string & s,int * temp)
{
	int i=0,j=0;
	while(s[i]!='\0')
	{
		//cout<<s[i]<<' ';
		if(s[i]>='0'&&s[i]<='9')
		{
			temp[j]=temp[j]*10+(s[i]-'0');
			//cout<<temp[j]<<' ';
		}else if(s[i]==' ')
		{
			//cout<<temp[j]<<' ';
			j++;
			temp[j]=0;
		}
		i++;
	}
	//cout<<endl;
	return j;
}
void showBin(string binfile)
{
	ifstream infile;
	infile.open(binfile.data());
	string s;
	while(getline(infile,s))
	{
		cout<<s<<endl;
	}
}
void readTxt(string my_infile,string my_outfile)
{
	ifstream infile;
	infile.open(my_infile.data());
	int fd=open(my_outfile.c_str(),O_WRONLY,0);
	//ofstream outfile("outtest.bin",ios::binary);
	string s;
	while(getline(infile,s))
	{
		//readNum(s);
		//cout<<s<<endl;
		int * temp=(int *)malloc(2*sizeof(int));
		int len=readNum(s,temp);
		//cout<<"len:"<<len<<endl;
		//int temp[3]={1,2,3};
		write(fd,temp,sizeof(int)*(len+1));
		//s="Hello";
		//outfile.write(s.c_str(),sizeof(s));
		
	}
	infile.close();
	close(fd);
}
int main(int argc,char * * argv)
{
	string infile=argv[1];
	string outfile=argv[2];
	readTxt(infile,outfile);
	//showBin(outfile);
	return 1;
}
