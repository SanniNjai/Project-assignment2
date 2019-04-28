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
int i, key, options;
char msg[255];
printf("Enter text: ");
scanf("%s",msg);

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
        
        if (lower_case[j] == msg[i] && (msg[i]>='a' && msg[i]<='z')){
           printf("\nKey replaced as below\nabcdefghijklmnopqrstuvwxyz");
           printf("\n||||||||||||||||||||||||||\n");
           printf("%s\n",unique_key);
           msg[i] = unique_key[j];
           break;
        }
        else if(upper_case[j] == msg[i] && (msg[i]>='A' && msg[i]<='Z')){
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

