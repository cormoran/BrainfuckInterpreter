#include<cstdio>
#include<cstdlib>
#include<vector>
#include<string>
#include<iostream>
#include<fstream>

/*
  + : increment the memory's  data
  - : decrement the momory's data
  [ : goto ']' if the memory is null(0)
  ] : goto '[' if the memory is not null
  . : output from the memory
  , : input to the memory
  > : increment memory position
  < : decrement memory position
 */

#define INIT_MEMORY_SIZE 30000

int main(int argc , char **argv){

  if(argc!=2){std::cerr<<"error : no input file"<<std::endl;exit(0);}

  std::ifstream ifs(argv[1]);
  if(ifs.fail()){std::cerr<<"error : no such file"<<std::endl;exit(0);}
  
  std::string src="";

  //read all char data
  std::string temp;
  while(getline(ifs,temp))src.append(temp);

  
  std::vector<unsigned char> mem(INIT_MEMORY_SIZE,0);
  unsigned int pos=0;
  
  for(int i=0;i<(int)src.size();i++){
    switch(src[i]){
    case '+':
      ++mem[pos];
      break;
    case '-':
      --mem[pos];
      break;
    case '[':
      if(mem[pos]==0){
	int cnt=1;
	while(cnt!=0){
	  ++i;
	  if(i==src.size()){std::cerr<<"error : unexpected synctax : ']' can't find"<<std::endl;exit(1);}
	  if(src[i]=='[')cnt++;
	  else if(src[i]==']')cnt--;
	}
      }
	
      break;
    case ']':
      if(mem[pos]!=0){
	int cnt=1;
	while(cnt!=0){
	  --i;
	  if(i<0){std::cerr<<"error : unexpected synctax : '[' can't find"<<std::endl;exit(1);}
	  if(src[i]==']')cnt++;
	  else if(src[i]=='[')cnt--;
	}
      }
      break;
    case '.':
      putchar(mem[pos]);
      break;
    case ',':
      mem[pos]=getchar();
      break;
    case '>':
      ++pos;
      if(pos==mem.size()){mem.resize(mem.size()*2,0);}
      break;
    case '<':
      if(pos==0){std::cerr<<"bus error : can't decrememt pointer below zero."<<std::endl;exit(1);}
      --pos;
      break;
    }
  }

  return 0;  
}
