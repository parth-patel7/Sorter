#include <stdio.h>
#include <string.h>
#include<stdlib.h>

struct node{
  char *data;
  struct node *next;
};


struct node *insert(char *input, struct node *head);
struct node *wordSeperator(char * input, struct node *head);
void print(struct node *head);
void delete(struct node *head);

int main(int argc, char ** argv){

  // If argument counter (number of arguments) is not 2 (file, string) then return -1 (error).
  if(argc != 2){
    printf("Please print a usable string \n");
    return -1;
  }

  struct node *head = NULL;  
  head = wordSeperator(argv[1], head);  
  print(head);
  delete(head);
  free(head);
  return 0;
}


 /*
   Function: wordSeperator (Filters words from input string).
   Purpose: Seperates/filters all words from input string
   Output: head/front of linked list in which words are stored as well as sorted  
 */
struct node *wordSeperator(char * input, struct node *head){
  
  int inputLength = strlen(input);
  char *word;
  word = malloc(inputLength * sizeof(char));


 /*
   In this for loop we traverse the input string and filter all words. 
   The filtered words are stored in word (word is malloc to input string length as the biggest
   word possible is input). Once we get the word we push it into linked list.
 */
  int i = 0;
  int index = 0; // index for storing letter in word array. Counter increases after storing each letter.
  for(i=0; i<inputLength+1; i++){
    if( (input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') ){
      word[index] = input[i];
      index++;
    } else {
      word[index] = '\0';
      index = 0;
      if(word[0] != '\0'){
	head = insert(word,head);
      }
      free(word);
      word = malloc(inputLength * sizeof(char));
    }
  }
  free(word);
  return head;
}


 /*
   Function: insert (insert nodes into linked list)
   Purpose: Finds the correct place to insert new node by comparing to each word in linked list
   Output: head/front of linked list in which words are stored as well as sorted 
 */

struct node *insert(char *input, struct node *head){

  // If head is null that means the linked list is empty the node is the head.
  if(head == NULL){
    head = malloc(sizeof(struct node));
    head->data = malloc(strlen(input)*sizeof(char));
    strcpy(head->data,input);
    head->next = NULL;
    return head;  
  }

  // If the head is not null that means the linked list is not empty.  
  // We form the node that is to be inserted   
  struct node *toInsert = malloc(sizeof(struct node));
  toInsert->data = malloc(strlen(input)*sizeof(char));
  strcpy(toInsert->data, input);


  // Second check if head is not null.     
  if(head != NULL){
    struct node *ptr = head;
    struct node *prev = NULL;

    // The ascii value of a to z is from 97 to 122 and A to Z is from 65 to 90.   
    // Here the asciiVal_T is the ascii value of FIRST CHARACTER OF WORD THAT IS TO BE
    // INSERTED in the linked list.
    int asciiVal_T = input[0];
    if(asciiVal_T < 95) asciiVal_T+=110;

        
    // This while loop compared ascii value character by character of word that is to be inserted 
    // and the word that is in the node 
    while (ptr != NULL){

      // Here the asciiVal_N is the ascii value of the FIRST CHARACTER OF WORD THAT IS IN THE NODE
      int asciiVal_N = ptr->data[0];
      if(asciiVal_N < 95) asciiVal_N+=110;

      // If the ascii value of char is less than 95 it means that the letter is Capital letter and to
      // increse its priority we increase the ascii by 110 which makes the value bigger than   
      // last letter 'z' which has value of 122.
      if(asciiVal_N < asciiVal_T){
	if(prev != NULL){
	  toInsert->next = ptr;
	  prev->next = toInsert;
	  return head;
	} else if(prev == NULL){
	  toInsert->next = ptr;
	  return toInsert;
	}
      }

      // if both has first letter same then we traverse through both words       
      if(asciiVal_N == asciiVal_T){
	int wordLength = strlen(ptr->data);
	int targetLength = strlen(input);
	int i,n = 0;

	(wordLength <= targetLength) ? (n = wordLength) : (n = targetLength);

	for(i=1; i<=n; i++){

	  asciiVal_N = ptr->data[i];
	  asciiVal_T = input[i];
	  if(asciiVal_N < 95) asciiVal_N+=110;
	  if(asciiVal_T < 95) asciiVal_T+=110;

	  // If both words are same
	  if(strcmp(input, ptr->data) == 0){
            toInsert->next = ptr->next;
            ptr->next = toInsert;
            return head;
	  }
	  
	  // If target is smaller than word in node then it is inserted after the current node
	  if(asciiVal_N > asciiVal_T){
	    toInsert->next = ptr->next;
	    ptr->next = toInsert;
	    return head;
	  }
  
	  // If target is greater than word in node then it is inserted before the current node
	  if(asciiVal_N < asciiVal_T){
	    toInsert->next = ptr;
	    if(prev != NULL){
	      prev->next = toInsert;
	      return head;
	    }else{
	      toInsert->next = head;
	      return toInsert;
	    }
	  }

	}
	return head;
      }      
      prev = ptr;
      ptr = ptr->next;
    }

    // If target word is smallest in the linked list then is inserted at the end of linked list
    if(ptr == NULL && prev != NULL){
      struct node *toInsert = malloc(sizeof(struct node));
      toInsert->data = malloc(strlen(input)*sizeof(char));
      strcpy(toInsert->data, input);
      toInsert->next = NULL;
      prev->next = toInsert;
      return head;
    }
  }
  return head;
}


 /*
   Function: print
   Purpose: Print the sorted linked list
   Output: void (nothing)
 */
void print(struct node *head){
  while(head != NULL){
    printf("%s\n", head->data);
    head = head->next;
  }
}


 /*
   Function: delete
   Purpose: Delete/Free all nodes in linked list
   Output: void (nothing)
 */
void delete(struct node *head){
  while(head != NULL){
    struct node *temp = head->next;
    free(head->data);
    free(head); 
    head = temp;
  }
}
