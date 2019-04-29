#include <stdio.h>
#include <string.h>

//Global char array
char upper_case[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char lower_case[26]="abcdefghijklmnopqrstuvwxyz";//lower case
char unique_key[26];//unique keys for encryption and decryption

void encryption(char* msg);// encrytion prototype
void decryption(char* msg);// decrytion prototype

int main() //main function
{
int opt, //assinging option 1
    options; // assigning option 2
char msg[1000]; //defining array input size or file 
FILE *input;// assinging file pointer

printf("To Manually input '1' (or) to Read from the file '2': ");//Option for input
scanf("%d", &opt); //getting option value

while(opt != 1 && opt != 2){ // if user put other than 1 or 2 in the first attemp, the loop will start
 printf("\nInvalid input\nTo quit, enter '0' (or) To Manually input, enter '1' (or) To Read from the file, enter '2': ");
 scanf("%d", &opt); 
 if (opt == 0){ return 0;}// loop will end if input is '0'
 }
 if (opt == 1){ 
 printf("Enter text: "); //Printing to ask user
 scanf("%s",msg); //Getting user "string" input and storing at "text" variable
 }
 else if (opt == 2){ //file will read if input is 2
     input = fopen("sub.txt", "r"); //("file name", "read")
     if(input == NULL) { //if there is no file accessible, user's friendly error will show up and value returns to '0'
     perror("fopen()");
     return 0;
     }
     while(!feof(input)){ //making sure system reads till the end of file
     fgets(msg, 1000, input);//getting("char variable", array size, file pointer)
     }
     fclose(input); // this make sure file closes after using
 }
 
printf("To Encrypt, enter '1' (or) To Decrypt, enter '2': ");//Asking option for En or De cryption
scanf("%d", &options);
 
while(options != 1 && options != 2){ // The loop if user's wrong input
  printf("\nInvalid input\nTo quit, enter '0' (or) To Encrypt, enter '1' (or) To decrypt, enter '2': ");
  scanf("%d", &options); 
    if (options == 0){ return 0;} //for input 0 to end the program
 }
 
switch(options){
    case 1:encryption(msg);//for input 1, it will call encrytion fucntion
           break;
    case 2:decryption(msg);// for input 2, it will call decryption function
           break;
}
    return 0; //ending the program
}

//defining encrytion function
void encryption(char* msg){
int i, j; //counters
printf("Enter 26 unique key of character for encryption: ");
scanf("%s", unique_key); //getting unique keys for input

//This show the chart
printf("\nKey replaced as below\nABCDEFGHIJKLMNOPQRSTUVWXYZ\nabcdefghijklmnopqrstuvwxyz");
printf("\n||||||||||||||||||||||||||\n");
printf("%s\n",unique_key);


for(i = 0; i< strlen (msg); i++){// loop will run until the end of text input
    for(j = 0; j<26; j++){//loop will find the positions of unique key for plain text dring 26 counts
        if (lower_case[j] == msg[i]){ 
           msg[i] = unique_key[j]; // the value in the position of unique key will replace the value of input positon.
           break;//every time position of input text matches normal plain text postion, the count will start again
        }
        else if(upper_case[j] == msg[i]){//for upper case input letter detected
           msg[i] = unique_key[j];
           break;
        }
     }
  }
 printf("Encryted text is: %s", msg);// after getting the final value and print
}


//defining decryption function
void decryption(char* msg){
int i, j;//counters
printf("Enter 26 unique key of characters for decryption\naccording to upper or lower case of input text: ");
scanf("%s", unique_key);//getting unique:

  for (i = 0; i<strlen(msg);i++){// loop until end of input text
      for(j = 0; j<26; j++){// loop until positon of input matches position of unique keys
          if( unique_key[j] == msg[i]){// if condition matches,the position of unique key will pass to plain text position
              msg[i]=lower_case[j]; // then, value in the position of plain text will replace value in the position of output 
              break; // once the condition met counting will start agian
            }
        }
    }
printf("Decrypted text is: %s",msg); // the value of msg is printed
}


