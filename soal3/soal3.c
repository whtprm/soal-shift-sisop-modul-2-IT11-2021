#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <wait.h>


char *enkripsi(char *str, int key){
  int pjg = strlen(str);
  char *size, new;
  size = (char*)malloc(sizeof(char) * (pjg +1));

  for (int i = 0; i < pjg; ++i) {
    char j = *(str + i);
    if ('a' <= j && j <= 'z'){
      new = ((*(str + i) - 'a' + key) %26) + 'a';
    } else if ('A' <= j && j <= 'Z'){
      new = ((*(str + i) - 'A' + key) %26) + 'A';
    } else if ('0' <= j && j <= '9'){
      new = ((*(str + i) - '0' + key) %10) + '0';
    } else {
      new = *(str + i);
    }
    *(size + i) = new;
  }
  return size;
}

int main(int argc,char* argv[]) { 

  pid_t pid, sid;        // Variabel untuk menyimpan PID
  pid_t child_id;

  pid = fork();     // Menyimpan PID dari Child Process
  child_id = fork();
  /* Keluar saat fork gagal
  * (nilai variabel pid < 0) */
  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  /* Keluar saat fork berhasil
  * (nilai variabel pid adalah PID dari child process) */
  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();
  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);
  
  if (child_id < 0) {
    exit(EXIT_FAILURE);
  }

  while (1){
      char newFile[100], folderName[100], url[100], zipfile[100];
      char *isi = enkripsi("Download Success." , 5);
      time_t rawtime, loctime; // rawtime menyimpan timestamp dlm format epoch
      struct tm * cur_time, * nex_time; // tm untuk menyimpan timestamp yang sesuai dengan local time
      rawtime = time(NULL); // untuk mengambil local time pada linux
      cur_time = localtime (&rawtime);  
      strftime(folderName, 100, "/home/clae/Modul2/%Y-%m-%d_%H:%M:%S", cur_time); // untuk membuat direktori baru dengan nama format file berupa timestamp dan isi direktori kosong.
      strftime(zipfile, 100, "%Y-%m-%d_%H:%M:%S", cur_time);

      if(fork()==0)
      {
        execl("/bin/mkdir","mkdir","-p",folderName, NULL); 
      }

      if(fork()==0){
        for(int i=0; i<10 ;i++){
          loctime = time(NULL);
          nex_time = localtime(&rawtime);
          if(fork()==0){
            strftime(newFile, 100, "/%Y-%m-%d_%H:%M:%S", nex_time);
            strcat(folderName, newFile);
            int file_size = ((loctime % 1000) + 50);
            sprintf(url,"https://picsum.photos/%d",file_size);
            execl("/usr/bin/wget","wget","-O", folderName, url, NULL);
          }
          sleep(5);
        }

        FILE *fp;
        fp = fopen ("status.txt", "w");
        fprintf(fp, "%s", isi);
        fclose(fp);

        pid = wait(NULL);
        if(fork()==0){   
          execl("/usr/bin/zip","zip","-rm", zipfile, zipfile, NULL);
          }
        }
    sleep(40);     
      }
    }
