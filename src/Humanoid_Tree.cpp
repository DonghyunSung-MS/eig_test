#include <Eigen/Dense>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

#define NUM_LINK 9
struct ULink{
  char name[10];
  int sister;
  int child;
};
//Set Link_tree manually
ULink ulink[10];
void gettextfile(){
  std::string line;
  std::ifstream myfile;
  myfile.open("src/eig_test/src/tree.txt");
  int ulink_cnt = 0;
  if(myfile.is_open()){
    while(std::getline(myfile,line)){
        std::stringstream ss;
        ss.str(line);
        ss>>ulink[ulink_cnt].name;
        ss>>ulink[ulink_cnt].sister;
        ss>>ulink[ulink_cnt++].child;
    }
    myfile.close();
  }
  else{
    std::cout<<"Unable to open file"<<std::endl;
  }
}
void PrintLinkName(){
  std::cout<<"name "<<"sister "<<"child"<<std::endl;
  for(int i=0;i<NUM_LINK;i++){
    std::cout<<ulink[i].name<<" ";
    std::cout<<ulink[i].sister<<" ";
    std::cout<<ulink[i].child<<std::endl;
  }
}

int main(){
  gettextfile();
  PrintLinkName();
  return 0;
}
