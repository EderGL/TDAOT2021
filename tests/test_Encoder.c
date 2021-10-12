/// @file Encoder.c
/**
*
* @author: Eder Garcia Lastiri
          Juan Carlos Rosales Alvarez
* @date:  12/10/2021
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../libs/unity.h"
#include "../libs/Encoder.h"

#define TEST_ARRAY "Hello BuddyBud \0"
#define SECRET_CODE "77, 112, 33, 105, 98, 116, 33, 109, 112, 104, 115, 98, 101, 112, 34, 33"
#define CODE 77, 112, 33, 105, 98, 116, 33, 109, 112, 104, 115, 98, 101, 112, 34, 33


static char* buffer = NULL;
static int code[] = {CODE};
static size_t offset= OFFSET;

void setUp(void){
    buffer = calloc(BUFSIZ, sizeof(char));
    strncpy(buffer, TEST_ARRAY, BUFSIZ);
}

void tearDown(void){
    free(buffer);
}

void test_encoderInit(void){
    puts("Positive Test");
    Message frame = newMessageContainer(TEST_ARRAY);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(buffer, getMessage(&frame), strlen(TEST_ARRAY));
}

void test_encoderSetMessage(void){
    puts("Positive Test Set Message");
    Message frame = newMessageContainer(TEST_ARRAY);
    setMessage(&frame,TEST_ARRAY);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(buffer, getMessage(&frame), strlen(TEST_ARRAY));
}

void test_encoderGetMessage(void){
    puts("Positive Test Get Message");
    Message frame = newMessageContainer(TEST_ARRAY);
    getMessage(&frame);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(buffer, getMessage(&frame), strlen(TEST_ARRAY));
}


int main(void){

    int lenght = (sizeof(code)/sizeof(int)-1);

    UNITY_BEGIN();
    RUN_TEST(test_encoderInit, __LINE__);
    RUN_TEST(test_encoderSetMessage, __LINE__);
    RUN_TEST(test_encoderGetMessage, __LINE__);

    Message test = newMessageContainer(SECRET_CODE);
    Message test2 = newMessageContainer(SECRET_CODE);
    setMessage(&test, TEST_ARRAY);
    encodeMessage(&test,code,1);
    printf("\n");
    printf("Decode Message 1: %s\n", TEST_ARRAY);
    printf("Encode Message 1: ");
    for(int i=0;i<strlen(TEST_ARRAY);i++){
      printf("%d, ", test.text[i]);
    }
    printf("\n\n");

    printf("Encode Message 2: %s\n", test2.text);
    printf("Decode Message 2: ");
    for(int j=0;j<lenght;j++){
      printf("%c", code[j]);
    }
    printf("\n");

    return UNITY_END();

}
