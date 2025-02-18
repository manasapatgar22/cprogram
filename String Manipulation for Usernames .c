● With built in function 
#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
 
void format_username_builtin(char *username) { 
    int i, j = 0; 
    int length = strlen(username); 
 
    for (i = 0; i < length; i++) { 
        if (username[i] != ' ') { 
            username[j++] = tolower(username[i]); 
        } 
    } 
    username[j] = '\0';  
} 
 
int main() { 
    char username[100]; 
    printf("Enter username: "); 
    fgets(username, sizeof(username), stdin); 
 
    username[strcspn(username, "\n")] = 0; 
     
    format_username_builtin(username); 
 
    printf("Formatted Username (Built-in functions): %s\n", username); 
 
    return 0; 
} 
 
● Without built in function 
#include <stdio.h> 
 
void format_username_manual(char *username) { 
    int i, j = 0; 
    char result[100]; 
 
    for (i = 0; username[i] != '\0'; i++) { 
        char ch = username[i]; 
 
        if (ch != ' ') { 
            if (ch >= 'A' && ch <= 'Z') { 
                ch = ch + ('a' - 'A'); 
            } 
            result[j++] = ch; 
        } 
    } 
    result[j] = '\0';  
 
    for (i = 0; result[i] != '\0'; i++) { 
        username[i] = result[i]; 
    } 
    username[i] = '\0';  
} 
 
int main() { 
    char username[100]; 
 
    printf("Enter username: "); 
    fgets(username, sizeof(username), stdin); 
 
    int i = 0; 
    while (username[i] != '\0') { 
        if (username[i] == '\n') { 
            username[i] = '\0'; 
            break; 
        } 
        i++; 
    } 
    format_username_manual(username); 
 
    printf("Formatted Username (Without built-in functions): %s\n", username); 
 
    return 0; 
} 
