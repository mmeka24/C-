#include <iostream> 
#include <cstring>
#include <cstdlib> 
using namespace std;



bool issame(char input[], int length, int left_index, int right_index){
    if (left_index < length and left_index != right_index){
        int front = (bool)isalnum(input[left_index]);//we dont actually remove the punctuation, we just skip the punctuation because it is not alphanumeric and check the next item in the cstring
        int back = (bool) isalnum(input[right_index]);//check if alphanumeric and divide by eight to normalize
        if(front + back == 2 and tolower(input[left_index]) != tolower(input[right_index])){
                return false;//if unequal return false
        }
        else if(front + back == 0){
                return issame(input, length, left_index + 1, right_index - 1);
        }
        else{//close in on both sides checking if equal
                return issame(input, length, left_index + back, right_index - front);
        }
    }
    return true;
}
int main(){
    char input[80];//grab input
    cin.get(input, 80);
    bool palindrome = issame(input, strlen(input), 0, strlen(input)-1);
    if (palindrome){//use palindrome function to check
        cout << "It is a palindrome"<<endl;
    }
    else{
        cout << "It is not a palindrome"<<endl;
    }
    return 0;
}
