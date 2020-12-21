/* Vigenere Cipher CLI Tool
 * Screaming
 * zhaba.dev
 *  
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int
wrapMod(int a, int b)
{
        if (a >= 0){
                return (a % b);
        } else {
                return (a % b + b) % b;
        }
}

static inline char
caesarEncode(char message, int shift)
{

        return ((message + shift - 'a') % 26) + 'a';
}

static inline char
caesarDecode(char message, int shift)
{
        char decode = wrapMod((message - shift - 97), 26) + 97;
        return decode;
}

char*
encode(char* message, char* key)
{
        int msgLen = strlen(message);
        int keyLen = strlen(key);

        for (int i = 0; i < msgLen; ++i){
                message[i] = caesarEncode(message[i], key[i % keyLen] - 'a');
        }

        return message;
}

char*
decode(char* message, char* key)
{
        int msgLen = strlen(message);
        int keyLen = strlen(key);

        for (int i = 0; i < msgLen; ++i){
                message[i] = caesarDecode(message[i], (int)(key[i % keyLen]) - 97);
        }
        

        return message;
}


char*
format(char* fileBuffer)
{
        // Format incoming file buffer to remove all spaces and add newline char after every 80 characters
        return fileBuffer;
}

int
processFile(char* fileName, char* option, char* key)
{
        /* 1. Open fileName
         * 2. Read the contents into a buffer
         *    - Format the buffer to remove all non-lowercase characters if 
         *      it's being encoded
         * 4. Encode/decode the buffer
         * 5. Write the buffer to a new file called <fileName>_[encode, decode].txt
         * 6. Return 1 if everything worked or 0 if something broke.
         *
         * It might be easier to just use a single character buffer
         */

        FILE *fp;
        fp = fopen(fileName, "r");

        char charBuffer;

        while(1){
                charBuffer = fgetc(fp);
                if (feof(fp)){
                        break;
                }

                printf("%c", c);
        }
        // how about now?
        fclose(fp);
        retrun 0;
}

int
main(int argc, char** argv){
        
        if (strcmp("encode", argv[1]) == 0){
                printf("Encoded: %s\n", encode(argv[2], argv[3]));

        }
        else if (strcmp("decode", argv[1]) == 0){
                printf("Decoded: %s\n", decode(argv[2], argv[3]));
        }

        return 0;
}

