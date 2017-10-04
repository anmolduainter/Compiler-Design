#include <bits/stdc++.h>
using namespace std;

// Function to check KeyWord
int isKeyword(char buffer[]){
    char keywords[32][10] = {"auto","break","case","char","const","continue","default",
                             "do","double","else","enum","extern","float","for","goto",
                             "if","int","long","register","return","short","signed",
                             "sizeof","static","struct","switch","typedef","union",
                             "unsigned","void","volatile","while"};
    int i, flag = 0;

    for(i = 0; i < 32; ++i){
        if(strcmp(keywords[i], buffer) == 0){
            flag = 1;
            break;
        }
    }

    return flag;
}

int main() {

    // 6 operators
    char operators[]="-=*/%+";

    char ch;

    int i,j=0;

    char buffer[15];

    ifstream fin("test1.txt");

    //if file does not open
    if (!fin.is_open()){
        cout<<"Error opening the file";
        exit(0);
    }

    //Loop till end of file eof
    while(!fin.eof()){

        //getting one char
        ch=fin.get();

        // Checking if character is operator
        for (int i = 0; i < 6 ; ++i) {
            if (operators[i]==ch){
                cout<<ch<<" : - operator \n";
            }
        }

        if (isalnum(ch)){
            buffer[j++]=ch;
        }
        else if ((ch==' ' || ch=='\n') && (j!=0)){
            buffer[j]='\0';
            j=0;

            //Now It can be an identifier or keyword

            //Checking for Keyword

            if (isKeyword(buffer)){
                cout<<buffer<<" is Keyword"<<endl;
            }
            else{
                cout<<buffer<<" is identifier"<<endl;
            }
        }
    }

    //Closing file
    fin.close();
    return 0;
}