#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>
#include <wait.h>
#include <dirent.h>
#include <glob.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


typedef struct petshops
{
    char username[50];
    char usertype[50];
    char userage[10];
}pet;

pet binatang[50];

char filer[100][50];
int NumFil=0;
char token[100][100];

void getdata(char fileName[]){
    int i;
    char temp[100]="";
    for (i=0;i<strlen(fileName);i++)
    {if(fileName[i]=='.' && fileName[i+1]=='j') {strcpy(filer[NumFil++], temp);
    strcpy(temp, "");
    break;
    }
    if(fileName[i]=='_'){strcpy(filer[NumFil++], temp);
    strcpy(temp, "");
    continue;
    }
    strncat(temp, &fileName[i], 1);
    }
}

pet substr(char string[], char delim)
{pet hewan;
int i;
char temp[100]="";
for (i=0;i<strlen(string);i++){if (string[i]==delim)break;
strncat(temp, &string[i], 1);
}
strcpy(hewan.usertype, temp);
     ++i;
char temp2[100]="";
for (;i<strlen(string);i++){if (string[i]==delim)break;
strncat(temp2, &string[i], 1);
}
strcpy(hewan.username, temp2);
++i;

char temp3[100]="";
for (;i<strlen(string);i++){strncat(temp3, &string[i], 1);
}
strcpy(hewan.userage, temp3);
   return hewan;
}

int canon(const char *path)
{ struct stat path_stat;
stat(path, &path_stat);
return S_ISREG(path_stat.st_mode);
}

int checkAnimal(char jenisAnimal[], int count){int i;for (i=0; i < count ; i++){if (strcmp(jenisAnimal, token[i])==0) return 1;
}
    return 0;
}

int main(int argc, char const *argv[])
{pid_t cid1, cid2, cid3, cid4, cid5, cid6;
int stat1, stat2, stat3, stat4, stat5, stat6;
DIR *dp;
struct dirent *ep;

cid1 = fork();
if (cid1 < 0) exit(0);
if (cid1 == 0){char *ag[] = {"unzip", "pets.zip", "-d", "/home/kali/modul2/petshop", NULL};
execv("/bin/unzip", ag);
 }

while(wait(&stat1)>0);
char path[] = "/home/kali/modul2/petshop";
dp = opendir(path);
if (dp != NULL) { while ((ep = readdir (dp))) {char pathTemp[500];
     sprintf(pathTemp,"%s/%s", path, ep->d_name);
    if ((strcmp(ep->d_name, ".")==0) || (strcmp(ep->d_name, "..")==0))continue;
    if (!canon(pathTemp)){
    cid2 = fork();
    if (cid2 < 0)exit(0);
    if (cid2 == 0){ char *ag[] = {"rm", "-r", pathTemp, NULL};
    execv("/bin/rm", ag);
    }
    }
    }
    (void) closedir (dp);
 } else perror ("error cek main");
    
    while(wait(&stat2)>0);
    dp = opendir(path);
    if (dp != NULL){ while ((ep = readdir (dp))) {if ((strcmp(ep->d_name, ".")==0) || (strcmp(ep->d_name, "..")==0))continue;
        char fileName[500];
         sprintf(fileName, "%s", ep->d_name);
         getdata(fileName);
        }
        (void) closedir (dp);
    } else perror ("Couldn't open the directory");

    int i;
    int kyoAnimls=0;
    int hitungtoken=0;

    for (i = 0; i < NumFil; i++)
    {
        binatang[kyoAnimls]=substr(filer[i], ';');
        kyoAnimls++;
    }

    //check file data buat kegori
    for (i = 0;i<kyoAnimls;i++){
        if(hitungtoken==0 || !checkAnimal(binatang[i].usertype, hitungtoken)){
            strcpy(token[hitungtoken++], binatang[i].usertype);
        }
    }
    
    for (i=0;i<hitungtoken;i++){
        cid3 = fork();
        if (cid3 < 0)exit(0);
        if (cid3 == 0){
            char filePath[500];
            sprintf(filePath, "%s/%s", path, token[i]);
            char *ag[] = {"mkdir", "-p", filePath, NULL};
            execv("/bin/mkdir", ag);
        }
    }

    //dem
    //dem
    //dem
    //akhir b

    //pembagian dan ubah nama
    while(wait(&stat3)>0);
    dp = opendir(path);
    if (dp != NULL)
    {
        int j;
        while ((ep = readdir (dp))) {
            if ((strcmp(ep->d_name, ".")==0) || (strcmp(ep->d_name, "..")==0))continue;
            char fileName[500];
            sprintf(fileName, "%s", ep->d_name);
            for (j=0; j<hitungtoken;j++){
                char* flag = strstr(fileName, token[j]);
                if (flag){
                    char dest[500];
                    char src[500];
                    sprintf(dest, "%s/%s", path, token[j]);
                    sprintf(src, "%s/%s", path, ep->d_name);
                    if (canon(src)){
                        cid4 = fork();
                        if (cid4 < 0)exit(0);
                        if (cid4 == 0){
                            char *ag[] = {"cp", "-f", src, dest, NULL};
                            execv("/bin/cp", ag);
                        }
                    }
                }
            }
        }
        (void) closedir (dp);
    } else perror ("error cek ubahnama");

    //dem dem dem dem dem
    //dem
    //dem
    //akhir c&d

    //buat txt keterangan tiap jenis pets
    while(wait(&stat4)>0);
    dp = opendir(path);
    if (dp != NULL)
    {
        int j;
        while ((ep = readdir (dp))) {
            char pathTemp[500];
            sprintf(pathTemp,"%s/%s", path, ep->d_name);
            if ((strcmp(ep->d_name, ".")==0) || (strcmp(ep->d_name, "..")==0))continue;
            if (!canon(pathTemp)){
                char folderName[100];
                strcpy(folderName, ep->d_name);
                int j=0,k=0;
                char pathFile[700];
                sprintf(pathFile, "%s/keterangan.txt", pathTemp);
                FILE *fp = fopen(pathFile, "a+");
                for (j=0;j<kyoAnimls;j++){
                    if (strcmp(binatang[j].usertype, folderName)==0)
                        fprintf(fp, "nama: %s\numur: %s tahun\n\n", binatang[j].username, binatang[j].userage);
                }
                fclose(fp);
            }
        }
        (void) closedir (dp);
    } else perror ("error cek keterangan");
    //dem dem dem dem dem dem
    //dem dem
    //dem
    //akhir dari e

    return 0;
}
