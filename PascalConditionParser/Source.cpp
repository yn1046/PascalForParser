#include <iostream>

struct Group
{
	char value[100];
	char altValue[100];
	bool isMutable;
	bool hasAlternative;
};

bool Parse()
{	
	char inputString[100], bufferString[100];
	gets_s(inputString);

	Group Pattern[7];
	Pattern[0] = { "for", "", false, false };
	Pattern[1] = { "", "", true, false };
	Pattern[2] = { ":=", "", false, false };
	Pattern[3] = { "", "", true, false };
	Pattern[4] = { "to", "downto", false, true };
	Pattern[5] = { "", "", true, false };
	Pattern[6] = { "", "", true, false };

	int i, j = 0, expectedHere = 0;
	for (i = 0; i < 100; i++) {
		if (inputString[i] != ' ' && inputString[i] != '\0')
		{
			bufferString[j] = inputString[i];
			j++;
		}
		else
		{
			bufferString[j] = '\0';
			if (!Pattern[expectedHere].isMutable)
			{
				if (strcmp(Pattern[expectedHere].value, bufferString) == 0 ||
					(Pattern[expectedHere].hasAlternative && strcmp(Pattern[expectedHere].altValue, bufferString) == 0))
				{
					printf_s("%s is a correct term\n", bufferString);
				}
				else
				{
					printf_s("%s is not a correct statement. Check for an error.\n", bufferString);
					return false;
				}					
			}
			else printf_s("%s can be anything\n", bufferString);
			strcpy_s(bufferString, "");
			j = 0;
			expectedHere++;
		}
	}

	return expectedHere == 7;
}

int main()
{
	if (Parse()) puts("String matches the pattern, everything is OK.");
	else puts("String doesn't match the pattern.");

	system("pause");
	return 0;
}