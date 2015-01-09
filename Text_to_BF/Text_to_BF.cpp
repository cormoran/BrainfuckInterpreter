#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>


int main(int argc,char **argv){
  if(argc!=3){std::cerr<<"please input following format : inputfilepath outputfilename"<<std::endl;exit(0);}

  std::ifstream ifs(argv[1]);
  
  if(ifs.fail()){std::cerr<<"no such file"<<std::endl;exit(0);}

  std::string input="",output="";
  unsigned char value=0;
  while(getline(ifs,input)){
    input.push_back('\n');
    for(int i=0;i<input.size();i++){
      int diff=abs((int)input[i]-(int)value+256) - abs((int)value+256-(int)input[i]);
      //incrementしたほうが近い場合
      if(diff>0){
	while(value!=input[i]){++value;output.push_back('+');}
      }
      //decrementしたほうが近い場合
      else if(diff<0){
	while(value!=input[i]){--value;output.push_back('-');}
      }
      output+=".\n";
    }    
  }
  ifs.close();
  
  std::ofstream ofs(argv[2]);
  ofs<<output;
  ofs.close();

  return 0;
}
