#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main ()
{
          string strng;
          getline(cin,strng);
          char character[strng.length()];
    strcpy(character, strng.c_str());
    for(int iterator_1=0;iterator_1<strng.length()-1;iterator_1++){
          if(character[iterator_1]>=char(33)&&character[iterator_1]<=char(57)){
              cout<<"invalid string";
              
        return 0;
                           
          }
        
    }
           for(int iterator_2=0;iterator_2<strng.length()-1;iterator_2++){
                   for(int iterator_3=0;iterator_3<strng.length()-iterator_2-1;iterator_3++){
                      
                             if(character[iterator_3]>character[iterator_3+1])
                             {
                                      int reference=character[iterator_3];
                                      character[iterator_3]=character[iterator_3+1];
                                      character[iterator_3+1]=reference;
                                     
                            
                            
                             }
                             
                   }
          }
    for(int iterator_4=0;iterator_4<strng.length();iterator_4++){
        
    cout<<character[iterator_4];
        
    }

}