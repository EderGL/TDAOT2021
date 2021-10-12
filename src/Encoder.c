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

/**
 * Constructs a new message container with a given string.
 * If message = NULL - then an empty container is returned.
 *
 * @param[in] message to be stored within the container.
 * @param[out] Message created container reference.
 */
Message newMessageContainer(char* message){
  int i=0;
  Message *newMessage = NULL;
  newMessage = malloc(sizeof(Message));
  newMessage->lenght = strlen(message);
  for(i=0;i<newMessage->lenght;i++){
    newMessage->text[i]=message[i];
  }
  return *newMessage;
}


/**
 * Sets a particular string message to a Message container module.
 *
 * @param[in] frame objective to modify.
 * @param[in] string to be set
 *
 * @returns ERROR code. TRUE if was successfully set. FALSE otherwise.
 */
ERROR setMessage(Message *frame, char* string){
  int i;

  if(string == NULL){
    return FALSE;
  }

  frame->lenght=strlen(string);
  strcpy(frame->text, string);
  return TRUE;

}

/**
 * Returns a given char* reference to the string within a frame object.
 *
 * @param[in] frame object to be analised.
 * @param[out] message starting pointer.
 */
char *getMessage(Message *frame){
  char *message;
  strcpy(message,frame->text);
  return message;
}


/**
 * Encodes a given message contained within a frame by an offset.
 *
 * @param[in] frame object whose string is to be encoded.
 * @param[in] offset type encoding.
 *
 * @returns ERROR CODE.
 */
ERROR encodeMessage(Message *frame, int frameInt[], size_t offset){
  int i;
  if(frame==NULL){
    return FALSE;
  }

  for(i=0;i<frame->lenght;i++){
    frame->text[i]=(frame->text[i]+offset);
    frameInt[i]=frameInt[i]-offset;
  }
  return TRUE;
}
