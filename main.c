#include <stdio.h>
#include <string.h>
char upper_case[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char lower_case[26]="abcdefghijklmnopqrstuvwxyz";
char unique_key[26];
//qwertyuiopasdfghjklzxcvbnm

void plain_text(char* msg);
void encryption(char* msg);
void decryption(char* msg);

int main()
{
int i, key, opt, options;
char msg[1000];
FILE *input;// assinging file pointer

printf("To Manually input '1' (or) to Read from the file '2': ");//Option for input
scanf("%d", &opt);

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
     fclose(input);
 }
 
printf("To Encrypt, enter '1' (or) To Decrypt, enter '2': ");//Asking option for En or De cryption
scanf("%d", &options);
 
while(options != 1 && options != 2){ // The loop if user's wrong input
  printf("\nInvalid input\nTo quit, enter '0' (or) To Encrypt, enter '1' (or) To decrypt, enter '2': ");
  scanf("%d", &options); 
    if (options == 0){ return 0;}
 }
switch(options){
    case 1:encryption(msg);
           break;
    case 2:decryption(msg);
           break;
}
    return 0;
}

void encryption(char* msg){
int i, j; 
printf("Enter 26 unique key of character for encryption: ");
scanf("%s", unique_key);

for(i = 0; i< strlen (msg); i++){
    for(j = 0; j<26; j++){
        
        if (lower_case[j] == msg[i]){
           printf("\nKey replaced as below\nabcdefghijklmnopqrstuvwxyz");
           printf("\n||||||||||||||||||||||||||\n");
           printf("%s\n",unique_key);
           msg[i] = unique_key[j];
           break;
        }
        else if(upper_case[j] == msg[i]){
           printf("\nKey replaced as below\nABCDEFGHIJKLMNOPQRSTUVWXYZ");
           printf("\n||||||||||||||||||||||||||\n");
           printf("%s\n",unique_key);
           msg[i] = unique_key[j];
           break;
        }
        
    }
    
}
printf("Encryted text is: %s", msg);
}

void decryption(char* msg){
int i, j;
printf("Enter 26 unique key of characters for decryption: ");
scanf("%s", unique_key);

  for (i = 0; i<strlen(msg);i++){
      for(j = 0; j<26; j++){
          if( unique_key[j] == msg[i]){
              msg[i]=lower_case[j];
              break;
            }
        }
    }
printf("Decrypted text is: %s",msg);
}


