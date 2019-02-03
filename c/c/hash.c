#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct mydata_tag {
  int used;  /*0 -- empty, 1-- used */
  int key;
  char name[24];
}mydata;

//implement hash function
int hash_key(char *name) {
  int key;
  int len;
  int i;

  key = 0;
  len = strlen(name);

  for(i =0; i< len; i++){
    key += name[i];
  }
  key %= 10;
  return key;
}

void init_table(char *filename, int size){
  FILE *fp;
  mydata data;
  int i;

  memset(&data, 0, sizeof(data));

  fp = fopen(filename, "w+");
  if(fp == NULL){
    perror("fopen: init_table");
    exit(1);
  }
 
  for (i = 0; i < size; i++){
    fwrite(&data, sizeof(mydata), 1, fp);
  }
  fclose(fp); 
}

void insert_data(int key, char *name, char *filename){
  FILE *fp;
  mydata data, slot;
  int pos;
  pos = key;

  data.used = 1;
  data.key = key;
  strcpy(data.name, name);

  fp = fopen(filename, "r+");
  if(fp == NULL){
    perror("fopen: insert_data");
    exit(1);
  }
  printf("to insert: key = %d, name = %s\n", key, name);
  while(1){
    fseek(fp, pos*sizeof(mydata), SEEK_SET);
    fread(&slot, sizeof(mydata), 1, fp);
    //printf("--> slot.used: %d\n", slot.used);
    if(slot.used != 1){
      break;
    }
    printf("Collision at position %d!\n", pos);
    pos++;
    pos %= 10;
  }
  printf("position found! pos  = %d\n\n", pos);
  fseek(fp, pos*sizeof(mydata), SEEK_SET);
  fwrite(&data, sizeof(mydata), 1, fp);
  fclose(fp);
}

void print_buckets(char *filename){
  FILE *fp;
  mydata data;
  int i;
  fp = fopen(filename, "r+");
  if(fp == NULL) {
    perror("fopen: insert_data");
    exit(1);
  }
  for(i = 0; i<10; i++){
    fseek(fp, i*sizeof(mydata), SEEK_SET);
    fread(&data, sizeof(mydata), 1, fp);
    printf("used = %d, key = %d, data = %s\n", 
           data.used, data.key, data.name);
  }
  fclose(fp);
}

int main(int argc, char *argv[])
{
  char *names[7] = {
    "John",
    "Steve",
    "Ajit",
    "Premal",
    "Kho",
    "Xiang",
    "Yamamoto"
  };
  int i, key;

  init_table("hash.txt", 10);
  print_buckets("hash.txt");
/*
  for(i =0; i < 7; i++){
    key = hash_key(names[i]);
    printf("key = %d, name = %s\n", key, names[i]);
  }
*/
  for(i = 0; i < 7; i++){
    key = hash_key(names[i]);
    insert_data(key, names[i], "hash.txt");

  }
  print_buckets("hash.txt");
  return 0;
}
