#include<stdio.h>
#include<string.h>

// Production Rules

// S -> cAd
// A -> ab/a

void check(void);
void set_value_backtracking(void);
void get_value_backtracking(void);
void display_output_string(void);

int iptr=0,optr=0,current_optr=0;
char output_string[20],current_output_string[20],input_string[20],temp_string[20];

int main(){
    printf("\nEnter the string to check: ");
    scanf("%s",input_string);
    check();
    return 0;}

void check(void){

    int flag=1,rule2_index=1;
    strcpy(output_string,"S");

    printf("\nThe output string in different stages are:\n");

    // Input Pointer less than length of string (input String)
    while(iptr<=strlen(input_string)){

        //Comparing string output and temp
        // if both output and temp are not identical then display
        if(strcmp(output_string,temp_string)!=0){
            display_output_string();}

        // if input pointer and output pointer does not point to the end of their respective string
        if((iptr!=strlen(input_string)) || (optr!=strlen(output_string))){

            // if char at input string at iptr equals to the char at output string at optr
            // increment both pointers
            if(input_string[iptr]==output_string[optr]){
                iptr=iptr+1;
                optr=optr+1;}

                //else
            else{
                  //if char is 'S'
                    if(output_string[optr]=='S'){
                        memset(output_string,0,strlen(output_string));
                        //Copying "cAd" in output string ---> see the production( S -> cAd) rules
                        strcpy(output_string,"cAd");
                    }

                // if char is 'A'
                // A -> ab/a (Production Rule)
                  else if(output_string[optr]=='A'){

                        //setting Value
                        set_value_backtracking();

                        //if Rule is 1 ( A -> ab )
                      if(rule2_index==1){
                        memset(output_string,0,strlen(output_string));

                        // copying "cabd" in output string
                        strcpy(output_string,"cabd");}

                          // if Rule is 2 ( A -> a)
                        else{
                            memset(output_string,0,strlen(output_string));
                           // copying cad in output
                            strcpy(output_string,"cad");}}

                    // Rule = 2 make pointer less 1
                    else if(output_string[optr]=='b' && input_string[iptr]=='d'){
                        rule2_index=2;
                        get_value_backtracking();
                        iptr=iptr-1;}

                        // throw invalid string
                    else{
                        printf("\nThe given string, '%s' is invalid.\n\n",input_string);
                        break;}}}

        else{
            printf("\nThe given string, '%s' is valid.\n\n",input_string);
            break;}}}


// function for setting value of backtracking.
void set_value_backtracking(void){ //setting values for backtracking

    // storing the ouput ptr reference ro the current pointer reference
    current_optr=optr;
    //copying the contents of output_string to current output string
    strcpy(current_output_string,output_string);
    return;}

//getting the value of backtracking
void get_value_backtracking(void){ //backtracking and obtaining previous values

    // getting the current pointer to the output pointer
    optr=current_optr;
    memset(output_string,0,strlen(output_string));
    //copying the current to output string
    strcpy(output_string,current_output_string);
    return;}

// function to display output string
void display_output_string(void){
    printf("%s\n",output_string);
    memset(temp_string,0,strlen(temp_string));

    // Copying the output string to temp string
    strcpy(temp_string,output_string);
    return;
}