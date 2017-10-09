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
int readNum(char * s,int * temp)
{
	int i=0,j=0;
	while(s[i]!='\0')
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			temp[j]=temp[j]*10+(s[i]-'0');
		}else if(s[i]==' ')
		{
				j++;
				temp[j]=0;
		}
		i++;
	}
	return j;
}
char * construct_string(string  s){
	int i=2,j=0;
	char * t=(char *)malloc(sizeof(int)*(s.length()-2));
	while(s[i]!='\0')
	{
		t[j++]=s[i];
		i++;
	}
	t[j]='\0';
	return t;
}
void readTxt(string my_infile,string my_outfile)
{
	ifstream infile;
	infile.open(my_infile.data());
	int fd=open(my_outfile.c_str(),O_WRONLY,0);
	string s;
	while(getline(infile,s))
	{
		int * temp=(int *)malloc(3*sizeof(int));
		char * t=construct_string(s);
		cout<<"t:";
		cout<<t<<endl;
		int len=readNum(t,temp);
		write(fd,temp,sizeof(int)*(len+1));	
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
