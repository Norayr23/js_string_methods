#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char at (char[], int);
int charCodeAt (char[], int);
char* concat (char[], char[]);
bool endsWith(char[], char[], int);
bool startsWith(char[], char[], int);
bool includes(char[], char[], int);
int indexOf(char[], char[], int);
int LastIndexOf(char[], char[], int);
char* padEnd(char[], int, char[]);
char* padStart(char[], int, char[]);
char* repeat(char[], int);
char* replace(char[], char[], char[], int*);
char* replaceAll(char[], char[], char[], int*);
char* slice(char[], int, int);
char* toLowerCase(char[]);
char* toUpperCase(char[]);
char* trimEnd(char[]);
char* trimStart(char[]);
char* trim(char[]);
char** split(char[], char[], int*);
void freeSplitted(char**);

int main(){
  
     return 0;
}


char at (char str[], int index) {
   if(index < 0){
      index = strlen(str) + index;
   }
   return str[index];
};
int charCodeAt (char str[], int index) {
   if(index < 0){
      index = strlen(str) + index;
   }
   return  (int)str[index];
};
char* concat (char str1[], char str2[]){
   int len1 = strlen(str1);
   int len2 = strlen(str2);
   char* res = (char*)malloc((len1 + len2 + 1) * sizeof(char));
   int i = 0;
   for(; i < len1; ++i){
      res[i] = str1[i];
   }
  for(int j = 0; j < len2; ++j){
      res[i + j] = str2[j];
   }
  res[len1 + len2 + 1] = '\0';
  return res;

};
bool endsWith(char str[], char search[], int end){
   if(end > strlen(str)){
      end = strlen(str);
   }
     bool found = false;
     int searchIndex = 0;
     int i = 0;
     for(; i < end && searchIndex < strlen(search); ++i){
        if(found){
           if(str[i] != search[searchIndex++]){
              return false;
           }
        }
        else if (str[i] == search[searchIndex]) {
           found = true;
           ++searchIndex;
        }
    
     }
     return found && searchIndex == strlen(search) && i == end;

};
bool startsWith(char str[], char search[], int start){
   start = start < 0 ? 0 : start;
   if(start >+ strlen(str)){
      return false;
   }
   int searchIndex = 0;
   for (int i = start; searchIndex < strlen(search); ++i){
      if(str[i] != search[searchIndex++]){
         return false;
      }
   }
   return true;
}


bool includes (char str[], char search[], int end) {
   if(end > strlen(str)){
      end = strlen(str);
   }
     bool found = false;
     int searchIndex = 0;
     int i = 0;
     for (; i < end && searchIndex < strlen(search); ++i) {
        if(found){
           if(str[i] != search[searchIndex++]){
              found = false;
              searchIndex = 0;
           }
        }
        else if (str[i] == search[searchIndex]) {
           found = true;
           ++searchIndex;
        }
    
     }
     return found && searchIndex == strlen(search);

};
int indexOf(char str[], char search[], int pos){
     int len = strlen(str);
     pos = pos < 0 ? 0 : pos > len ? len : pos;
     bool found = false;
     int searchIndex = 0;
     int i = pos;
     int res;
     for (; i < len && searchIndex < strlen(search); ++i) {
        if(found){
           if(str[i] != search[searchIndex++]){
              found = false;
              searchIndex = 0;
           }
        }
        else if (str[i] == search[searchIndex]) {
           found = true;
           ++searchIndex;
           res = i;
        }
    
     }
     return found && searchIndex == strlen(search) ? res : -1;


}
int LastIndexOf(char str[], char search[], int pos){

     int len = strlen(str);
     pos = pos < 0 ? 0 : pos >= len ? len - 1 : pos;
     bool found = false;
     int searchIndex = strlen(search) - 1;
     int i = pos;
     int res;
     for (; i >= 0 && searchIndex >= 0; --i) {
        if(found){
           if(str[i] != search[searchIndex--]){
              found = false;
              searchIndex = strlen(search) - 1;
           }
        }
        else if (str[i] == search[searchIndex]) {
           found = true;
           --searchIndex;
           res = i;
        }
    
     }
     return found && searchIndex == -1 ? res - (strlen(search) - 1) : -1;


}
char* padEnd(char source[], int len, char add[]){
   if(len <= strlen(source)){
      char* res = (char*) malloc (strlen(source) * sizeof(char) + 1);
      strcpy(res, source);
      return res;
   }
   char* res = (char*) malloc (len * sizeof(char) + 1);
   strcpy(res, source);
   int resIndex = strlen(source);
   int addIndex = 0;
   for (; resIndex < len; ++resIndex) {
         addIndex = addIndex >= strlen(add) ? 0 : addIndex;
         res[resIndex] = add[addIndex];
   }
   res[len] = '\0';
   return res;

};
char* padStart(char source[], int len, char add[]){
    if(len <= strlen(source)){
      char* res = (char*) malloc (strlen(source) * sizeof(char) + 1);
      strcpy(res, source);
      return res;
   }
   char* res = (char*) malloc (len * sizeof(char) + 1);
   int resIndex = 0;
   int paddLength = len - strlen(source);
   int addIndex = 0;
    for (; resIndex < paddLength; ++resIndex) {
         addIndex = addIndex >= strlen(add) ? 0 : addIndex;
         res[resIndex] = add[addIndex];
   }
    strcpy(&res[resIndex], source);
    return res;
}
char* repeat(char str[], int count) {
   if(count <= 0){
      return NULL;
   }
   int resLen =  strlen(str) * count; 
   char* res = (char*) malloc(resLen * sizeof(char) + 1);
   int strIndex = 0;
   for (int i = 0; i < resLen; ++i){
      strIndex = strIndex >= strlen(str) ? 0 : strIndex;
      res[i] = str[strIndex ++];
   }
   res[resLen] = '\0';
   return res;
};

char* replace(char str[], char part[], char with[], int* resSize){
   int index = indexOf(str, part, 0);
   if (index < 0){
      char* res = (char*)malloc(strlen(str) * sizeof(char) + 1);
      strcpy(res, str);
      *resSize = strlen(str);
      return res;
   }
   *resSize = strlen(str) - strlen(part) + strlen(with);
    char* res = (char*)malloc(*resSize *  sizeof(int) + 1);
    int i = 0;
    for (; i < index; ++i){
       res[i] = str[i];
    }
    strcpy(&res[i], with);
    i += strlen(with);
    strcpy(&res[i], &str[index + strlen(part)]);
    return res;
}
char* replaceAll(char str[], char part[], char with[], int* resSize){
 int index = indexOf(str, part, 0);
 if(index < 0){
    char* res = (char*)malloc(strlen(str) * sizeof(char) + 1);
    strcpy(res, str);
    *resSize = strlen(str);
    return res;
 }
 char* res = replace(str, part, with, resSize);
 while(indexOf(res,part,0 ) > 0 ){
    char* tmp = res;
    res = replace(tmp, part, with, resSize);
    free(tmp);
 }
 return res;
}
char* slice(char arr[], int start, int end){
   int size = strlen(arr);
   int resSize = 0;
   if (start < 0){
      start += size;
   }
   if(end < 0){
      end += size;
   }
   if(start > end){
     resSize = 0;
      return NULL;
   }
   resSize = end - start;
   char* dest = (char*)malloc(resSize * sizeof(char) + 1);
   for (int i = 0; i < resSize; ++i){
      dest[i] = arr[start++];
   }
   dest[resSize] = '\0';
   return dest;
}
char* toLowerCase(char str[]){
   int len = strlen(str);
   char* res = (char*)malloc(len * sizeof(char) + 1);
   for (int i = 0; i < len; ++i){
      if(str[i] >= 'A' && str[i] <= 'Z'){
         const int lowerUpperDiff = 32;
         res[i] = str[i] + lowerUpperDiff;
      }
      else{
         res[i] = str[i];
      }
      
   }
   res[len] = '\0';
   return res;
};
char* toUpperCase(char str[]){
   int len = strlen(str);
   char* res = (char*)malloc(len * sizeof(char) + 1);
   for (int i = 0; i < len; ++i){
      if(str[i] >= 'a' && str[i] <= 'z'){
         const int lowerUpperDiff = 32;
         res[i] = str[i] - lowerUpperDiff;
      }
      else{
         res[i] = str[i];
      }
      
   }
   res[len] = '\0';
   return res;
};
char* trimEnd(char str[]){
   int spaceCount = 0;
   for (int i = strlen(str) - 1; i >= 0; --i){
      if(str[i] != ' ' && str[i] != '\t'){
         break;
      }
      ++spaceCount;
   }
  char* res = (char*)malloc((strlen(str) - spaceCount) * sizeof(char) + 1);
  char* tmp = slice(str, 0, strlen(str) - spaceCount);
  strcpy(res, tmp);
  free(tmp);
  return res;
};
char* trimStart(char str[]){
   int spaceCount = 0;
   for (int i = 0; i < strlen(str); ++i){
      if(str[i] != ' ' && str[i] != '\t'){
         break;
      }
      ++spaceCount;
   }
  char* res = (char*)malloc((strlen(str) - spaceCount) * sizeof(char) + 1);
  char* tmp = slice(str, spaceCount, strlen(str));
  strcpy(res, tmp);
  free(tmp);
  return res;

};
char* trim(char str[]){
   char* tmp = trimStart(str);
   char* res = trimEnd(tmp);
   free(tmp);
   return res;
}
char** split(char str[], char sep[], int* count){
   if(strcmp(sep, "") == 0){
      *count = strlen(str);
     char** res = (char**)malloc(*count * sizeof(char*));
     char* tokens = (char*)malloc((*count * sizeof(char)) * 2);
     int tokenIndex = 0;
     for(int i = 0; i < *count; ++i, tokenIndex += 2){
       tokens[tokenIndex] = str[i];
       tokens[tokenIndex + 1] = '\0';
       res[i] = (tokens + tokenIndex);
     }
     return res;
   }
   *count = 0;
   int pos = 0;
   int indexSep = indexOf(str, sep, pos);
   char** res = (char**)malloc(sizeof(char*));
   char* tokens = (char*)malloc((sizeof(char) * strlen(str)) * 2);   
   while(indexSep != -1 && pos < strlen(str)){
    char* tmp = slice(str, pos, indexSep);
    strcpy((tokens + pos), tmp); 
    res = (char**)realloc(res, ((*count + 1) * 2) * sizeof(char*));
    res[*(count)] = (tokens + pos);
    *count += 1;
    pos = indexSep + 1;
    indexSep = indexOf(str, sep, pos);
    free(tmp);
   }
   char* tmp = slice(str, pos, strlen(str));
   strcpy((tokens + pos), tmp);
   res = (char**)realloc(res, ((*count + 1) * 2) * sizeof(char*));
   res[*(count)] = (tokens + pos);
   *count += 1;
   free(tmp);

   return res;
};
void freeSplitted(char** str){
   free(str[0]);
   free(str);
};
