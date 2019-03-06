	                             This file contains a brief description of the program.

------------------------------------
	Total Functions: 5
------------------------------------

->The c program (Pointersorter.c) contains five functions.
  1 Main
  2 wordsSeperator
  3 insert
  4 print
  5 delete

------------------------------------
	Command Line Arguments
------------------------------------

Example: ./pointersorter "Your Argument here (within two quotation mark)"


------------------------------------
	Functions
------------------------------------

1) Main (Line 16)
-> First thing it does is check wheter the input string and number of argument is are correct or not. (Line 21-24) 
   Further makes a head node for linked list then calls for wordSeperator and print (Line 26-31)

2) wordSeperator (Line 38)
-> array named word holds the words that are filtered from input string. In this for loop we traverse the input string and filter
   all words. The filtered words are stored in the dynamically allocated array word (word is malloc to input string length as 
   the biggest word possible is input). Once we get the word we push it into linked list and re-malloc it so it can have the next
   word. 
   The for loop keeps running and saving letter by letter in word and only stops when non letter character is found.
   Therefore if	the input is "Hello" it wont be able to do anything as all characters in input string are letters 
   To solve this we will run  the for loop to input length +1 (that is 6 in "Hello") as last character in hello will 
   be '\0' thus getting a non letter character the word Hello will be pushed into linked list

3) insert (Line 78)
-> This function inserts the word that is given from wordSeperator and stores in Linked list in decending order.
   The ascii value of a to z is from 97 to 122 and A to Z is from 65 to 90. If the linked list contains two nodes
   Zebra->Apple and we want to insert Bank then it will first compare first character of node and target, in this case
   it will compare  Z and B as B's ascii value is smaller than Z it will be inserted after Zebra.
   As per the assignment the capital letters are greater than small letters but in ascci capital letters are have smaller
   value, to solve this we can simply add 110 to capital letters ascii value which makes them greater than small letters
   Example if the node has two words zebra->apple and the target word that is to be inserted is Zebra, is we simply compare 
   first character than it will end up as zebra->apple->Zebra but as we have added 110 to Z's ascii value now Z has the 
   greatest value 90+110 = 200 while z's value is 122 therefore making the linked list Zebra->zebra->apple.

4) print (Line 173)
-> This function traverse through the linked list in O(n) time and prints all the nodes.

5) delete (Line)
-> This function traverse through the linked list and deleted/free each node.


-------------------------------------
        Pseudocode
-------------------------------------

-> [wordSeperator]
   traverse through argv[0]
   save each letter in word array
   if non letter character is found stop and send it to insert
   free and re malloc the word array to save the next word
      [insert]
      get the word and insert into linked list in decending order
      	  [print]
	  after traversing argv[0] is complete print gets the head and prints the linked list
	  	[delete]
		after printing is complete we have to free all the memory and delete function traverse through the linked
		list to free each word and node

      
-------------------------------------
	Algorithm Analysis
-------------------------------------

-> The big O of filtering words from argv[0] (input) is O(n) as we traverse through the array once.
   The bg O for inserting the found word in linked list is O(n) as we traver through the linked list once
   The big O for comparing the word that is to be inserted in linked list is O(1) as we we just compare the 
   the first character, the worse case is O(n) if both words have same letters till end.
   The big O for printing and deleteing (free) linked list is O(n)
   ---> Thus making the overall big O of code O(n).


-------------------------------------
        Output file
-------------------------------------

-> After compiling the program using the gcc -O -g -o pointersorter pointersorter.c command we will get a executable file 
   named pointersorter.
