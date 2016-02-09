#include <stdio.h>
#include <stdlib.h>
/*
void insertAfter(char* array, int length, char insert, int position)
{
	char* 
}
*/
int countConsonants(char* array, int length)
{
	char c;
	int i,count;

	for(i = 0; i < length; i++)
	{
		c = array[i];
		if(c=='a'||c=='A'||c=='e'||c=='E'||c=='i'||c=='I'||c=='o'||c=='O'||c=='u'||c=='U' || c<65 || c>22 || (c>90 && c<97))
		{
			continue;
		} else {
			count++;
		}
	}

	return count;
}

int main(int argc, char** argv)
{
	FILE *inputFile;
	int index = 0;
	char* ch;
	char* longArray;
	char* words = malloc(1000 * sizeof(char));
	inputFile = fopen(argv[1], "r");
	printf("File opened");
	while( (ch = fgetc(inputFile)) != EOF)
	{
		words[index] = ch;
		index++;
	}
	words[index] = '\0';
	//Length with EOF
	ch = malloc((index + (countConsonants(words,index) * 2)) * sizeof(char));	
	fclose(inputFile);
	printf("File closed");
	return 0;
}
