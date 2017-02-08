/*
  Basic mono-cipher algorithm crypter. This version is intended to be used to crypt simple plain text
  yet it can be modified to do more things.


 * Author Krhertz 2016
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void crypt();	//Function to crypt text
void decrypt();	//Function to decrypt text
void instruc(); //Instructions

#define a  "=Aa&BbCcD#d1234567890EeFfGgHhIiJjKkLlMmNnOoPpQqRrSs*TtUuVvWwXxYyZzç+¡!$)(?¿{[]}Ç,-:_ñÑ\n." //NORMAL
#define cr "#d1234567890EeFfGgHhIiJjKkLlMmNnOoPpQqRrSs*TtUuVvWwXxYyZzç+¡!$)(?¿{[]}Ç,-:_ñÑ\n.=Aa&BbCcD" //CRPTING


int main (int argc, char** argv){
  int opt;
  do{
    getchar();
    printf ("*** KRHERTZ CRYPTER ***\nChoose an option: \n1) Crypt\t2) Decrypt\t3) Instructions\t4)exit\n");
    opt = getchar();

    switch(opt){
    	  case '1': crypt() ;break;
	  case '2': decrypt(); break;
	  case '3': instruc(); break;
	  default: opt != '4' ? "Choose a correct option" : " "; break;
    }
  }while(opt != '4');
  return 0;
}

void crypt(){
  int i;

  FILE  *arch, *nue; //Files to be opened: arch -> text to crypt. nue -> output of the crypted text

  if ((nue = fopen ("obf.txt","a")) != NULL){
  }else {
	perror ("Error:");
	exit(-1);
	}

  if ((arch = fopen ("hello.txt","r")) != NULL){

	do{
		char temp;
		// Read character to be changed
		temp = fgetc(arch);
		if(temp == '/'){
			fputc ('/',nue);
		}else if(temp == ' '){
			fputc ('@',nue);
		}else if(temp == '@'){
			fputc (' ',nue);
		}else  if(temp == '%'){
			  fputc ('%',nue);
			}else{
			//Finding Character
			for(i = 0; temp != a[i]; i++){

			}
			//Writing and verifying the character
			   if (temp == a[i]){
				fputc(cr[i],nue);
			   }
		        }

        }while(!feof(arch));
	rewind (arch);
	rewind (nue);
	fclose (arch);
	fclose (nue);
  }else {
          FILE *hello;
	  printf ("The file 'hello.txt' doesn't exist or there was a problem while opening it.\nTherefore a new 'hello' file will be created so you can include\nyour text-to-crypt in it.\n\n");
          hello = fopen("hello.txt","w" );
          fclose (hello);
	  exit (-1);
	}
  system ("clear;echo 'done'");
}

void decrypt(){
    int i,j;

  FILE  *arch, *nue;

  if ((nue = fopen ("decrypted.txt","w")) != NULL){
  }else {
	perror ("Error: ");
	exit(-1);
	}

  if ((arch = fopen ("obf.txt","r"))!= NULL){

	do{
		char temp;
		temp = fgetc(arch);
		if(temp == '/'){
			fputc ('/',nue);
		}else if(temp == '@'){
			fputc (' ',nue);
		}else if(temp == ' '){
			fputc ('@',nue);
		}else if(temp == '%'){
			  fputc ('%',nue);
			}else{
			//Character localization
			for(i = 0; temp != cr[i]; i++){

			}
			//Writting and Verifying the character
			if (temp == cr[i]){
					   fputc(a[i],nue);
				          }
		}
	}while(!feof(arch));

	//Rearrange the pointer and addind a ' ' character to the end
	fseek (nue,-2,SEEK_END);
        int j;
	for(j = 0; j <= 2; j++){
		fputc(' ',nue);
	}
	rewind (arch);
	rewind (nue);
	fclose (arch);
	fclose (nue);
  }else {
	  printf ("There is no 'obf.txt' file or an error occurred while opening it.\nHave you crypted anything?\n");
	  exit (-1);
	}
    system ("clear;echo 'done'");
}

void instruc(){
	system ("less README.md; clear");

}

