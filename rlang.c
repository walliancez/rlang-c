#include <stdio.h>
#include <stdlib.h>
/*
void insertAfter(char* array, int length, char insert, int position)
{
	char* 
}
*/
int isConsonant(char c);
int countConsonants(char* array, int length);

int isConsonant(char c)
{
	if(c=='a'||c=='A'||c=='e'||c=='E'||c=='i'||c=='I'||c=='o'||c=='O'||c=='u'||c=='U' || c<65 || c>122 || (c>90 && c<97))
        {
                return 0;
        } else {
                return 1;
	}
}

int countConsonants(char* array, int length)
{
	char c;
	int i,count;

	for(i = 0; i < length; i++)
	{
		c = array[i];
		if(isConsonant(c))
		{
			count++;
		} else {
			continue;
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
	printf(argv[1]);
	printf("\n");
	inputFile = fopen(argv[1], "r");
	printf("File opened\n");
	while( (ch = fgetc(inputFile)) != EOF)
	{
		words[index] = ch;
		index++;
	}
	words[index] = '\0';
	//Length with EOF
	longArray = malloc((index + (countConsonants(words,index) * 2)) * sizeof(char));
	index = 0;
	while(longArray[index] != EOF)
	{
		if(isConsonant(longArray[index])){
			char temp = longArray[index];
			longArray[index + 1] = 'o';
			longArray[index + 2] = temp;
			index += 3;
		} else {
			index++;
		}
	}
	printf(longArray);	
	fclose(inputFile);
	printf("File closed\n");
	return 0;
}
