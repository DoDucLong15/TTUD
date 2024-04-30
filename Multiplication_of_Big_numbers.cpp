#include <bits/stdc++.h>
const int MAX = 1e6 + 5;

char* tisch(char* s, char c) {
    int n = strlen(s), i, nho =0, k=0, j=0;
    static char result1[MAX], result2[MAX];
    for (i=n-1; i>=0; i--) {
        int d = (c-48)*(s[i]-48)+nho;
        nho = d/10;
        if (i!=0) {
            result1[k] = d%10+48;
            k++;
        }
        else {
            result1[k] = d%10+48;
        	k++;
            result1[k] = d/10+48;
            k++;
        }
    }
    for(i=k-1; i>=0;i--) {
    	result2[j] = result1[i];
    	j++;
	}
    result2[k]='\0';
    return result2;
}

char* Sum_String(char* s1, char* s2) {
	//gia su len1>=len2
	static char result[MAX];
	int len1 = strlen(s1)-1, len2 = strlen(s2)-1, i, x=0, k=0;
	static int d=0;
	while (len1>=0 && len2>=0) {
		d = d+ s1[len1]-48+s2[len2]-48;
		result[x] = d%10+48;
		x++;
		len1-=1;
		len2-=1;
		d=d/10;
	}

	while (len1>=0) {
		d+=s1[len1]-48;
		result[x] = (d%10+48);
		x++;
		len1--;
		d=d/10;
	}
	if (d!=0) {
		result[x] = d+48;
		x++;
	}
	result[x] = '\0';
	for (i=0; i<x/2; i++) {
		char c = result[i];
		result[i] = result[x-1-i];
		result[x-1-i] = c;
	}
	return result;
}

void LongDepTrai(char s1[], char s2[]) {
    int i, n = strlen(s2), dem=0;
    char long1[MAX];
    if (n==1) strcpy(long1,tisch(s1,s2[0]));
    else {
        strcpy(long1,tisch(s1,s2[n-1]));
        for (i=n-2; i>=0; i--) {
            char temp[MAX];
            strcpy(temp,tisch(s1,s2[i]));
            temp[strlen(temp)] = '\0';
            int k =n-1-i, j;
            char zero[k];
            for(j=0; j<k; j++) zero[j] = 48;
            zero[k] = '\0';
            strcat(temp,zero);
            strcpy(long1,Sum_String(temp,long1));
        }
    }
    for (i=0; i<strlen(long1); i++)
        if(long1[i]=='0') dem++;
        else break;
    for (i=0; i<strlen(long1)-dem; i++) long1[i] = long1[i+dem];
    long1[strlen(long1)-dem]='\0';
    printf("%s", long1);
}

int main() {
    char s1[MAX], s2[MAX];
    scanf("%s", &s1); fflush(stdin);
    scanf("%s", &s2);
    LongDepTrai(s1, s2);

    return 0;
}
