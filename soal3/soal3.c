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

// program bash killer.sh untuk mengehntikan proses
void killersh(int argc,char **argv,int pid){
    FILE *pkiller = fopen("killer.sh", "w");
    if(strcmp(argv[1], "-x") == 0 && argc == 2){ 
        fprintf(pkiller, "#!/bin/bash\nkill %d\nrm \"$0\"", pid);
    }else if(strcmp(argv[1], "-z") == 0 && argc == 2){ 
        fprintf(pkiller, "#!/bin/bash\nkillall -9 soal3\nrm \"$0\"");
    }else {
        printf("argument  salah %s. pilih -x / -z\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    fclose(pkiller);

    if(fork() == 0){
        char *chomdargv[] = {"chmod", "+x", "killer.sh", NULL};
        execv("/bin/chmod", chomdargv);
    }
}
//pembuatan folder untuk menaruh gambar yang didownload
void createfolder(char *foldername){
    if(fork()==0){ 
        char *mkdirargv[] = {"mkdir", "-p",foldername, NULL};
        execv("/bin/mkdir", mkdirargv);
    }
}
// program untuk mendownload file gambar dari url yg ditentukan
void dlgb(char *foldername){
    time_t rawtime;
    int i,size;
    char filename[200];
    char buffer[100];
    char urlname[100];

    for(i=0;i<10;i++){
        time(&rawtime);
        strftime(buffer, 100, "%Y-%m-%d_%X", localtime(&rawtime));
        sprintf(filename,"%s/%s.jpg",foldername,buffer);
        size = (int)time(NULL);
        size = (size%1000)+50;
        sprintf(urlname,"https://picsum.photos/%d",size);

        if(fork()==0){
            char *dlargv[] = {"wget", "-qO", filename, urlname, NULL};
            execv("/usr/bin/wget", dlargv);
        }
        sleep(5);
    }
}

//direktori di zip setelah download gambar
void zip(char *foldername){
    char zipname[150];
    sprintf(zipname,"%s.zip",foldername);
    char *zipargv[] = {"zip", "-rmq", zipname, foldername, NULL};
    execv("/usr/bin/zip", zipargv);
}

//program enkripsi 
void enkrip(char* rawstring,int shift){
    char enk;
    int i;
    for (i=0;rawstring[i]!='\0';i++){
        enk = rawstring[i];
        if(enk>='A'&&enk<='Z'){
            enk=enk+shift;
            if (enk > 'Z') enk = enk-'Z'+'A'-1;
            rawstring[i] = enk;
        }
        else if (enk>='a'&&enk<='z'){
            enk=enk+shift;
            if (enk > 'z') enk = enk-'z'+'a'-1;
            rawstring[i] = enk;
        }
    }
}

//program membuat status.txt 
void statustext(char *foldername){    
    char status[112];
    char message[20] = "Download Success";
    sprintf(status,"%s/status.txt",foldername);
    enkrip(message,5);
    FILE *download = fopen(status,"w");
    fprintf(download,"%s",message);
    fclose(download);
}


void final(char *foldername){
    int child1;
    if(fork()==0){ 
        dlgb(foldername);
        statustext(foldername);
        zip(foldername);
    }
}


int main(int argc, char **argv){
    pid_t pid, sid; // Variabel untuk menyimpan PID
    char tempfile[100];
    time_t rawtime;

    pid = fork(); // Menyimpan PID dari Child Process

    /* Keluar saat fork gagal (nilai variabel pid < 0) */
    if (pid < 0) exit(EXIT_FAILURE);

    /* Keluar saat fork berhasil (nilai variabel pid adalah PID dari child process) */
    if (pid > 0) exit(EXIT_SUCCESS);

    umask(0);

    sid = setsid();
    if (sid < 0) exit(EXIT_FAILURE);

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    killersh(argc,argv,(int)getpid());

    while (1){
        int child1;

        //buat folder berdasarkan timestamp
        time(&rawtime);
        strftime(tempfile, 100, "%Y-%m-%d_%X", localtime(&rawtime));
        createfolder(tempfile);
        //menunggu folder selesai
        while((wait(&child1))>0);
        //proses zip 10 gambar
        final(tempfile);
        //menunggu folder di zip
        while((wait(&child1))>0);

        sleep(40); 
    }

}