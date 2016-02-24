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
	int i;
	int count = 0;

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
	int longIndex = 0;
	int ch;
	char* longArray;
	char* words = malloc(1000 * sizeof(char));

	inputFile = fopen(argv[1], "r");
	while( (ch = getc(inputFile)) != EOF)
	{
		words[index++] = (char)ch;
	}
	fclose(inputFile);
	printf("%d\n", countConsonants(words,index));
	//Length with EOF
	longArray = malloc((index + (countConsonants(words,index) * 2)) * sizeof(char));
	index = 0;
	while(words[index] != EOF)
	{
		if(isConsonant(words[index])){
			char temp = longArray[index];
			longArray[longIndex] = temp;
			longArray[longIndex + 1] = 'o';
			longArray[longIndex + 2] = temp;
			longIndex += 3;
			index++;
		} else {
			longArray[longIndex];
			index++;
			longIndex++;
		}
	}
	printf("%s\n",longArray);
	free(words);
	free(longArray);
	return 0;
}
