#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    //12345
    vector<int> num1 = {1,2,3,4,5};
    
    // 21232425
    vector<int> num2 = {2,1,2,3,2,4,2,5};
    
    //33 11 22 44 55
    vector<int> num3 = {3,3,1,1,2,2,4,4,5,5};
    
    int cor1=0;
    int cor2=0;
    int cor3=0;
    
    for(size_t i= 0 ; i<answers.size() ;++i)
    {
        if(answers[i] == num1[i % num1.size()])
            ++cor1;
        if(answers[i] == num2[i % num2.size()])
            ++cor2;
        if(answers[i] == num3[i % num3.size()])
            ++cor3;
    }
    
    
    printf("%d\n",&cor1);
    printf("%d\n",&cor2);
    printf("%d\n",&cor3);
    
    int max = 0;
    max = max < cor1 ? cor1:max;
    max = max < cor2 ? cor2:max;
    max = max < cor3 ? cor3:max;
    
    if(cor1 == max)  answer.push_back(1);
    if(cor2 == max)  answer.push_back(2);
    if(cor3 == max)  answer.push_back(3);
    
    
    return answer;
}