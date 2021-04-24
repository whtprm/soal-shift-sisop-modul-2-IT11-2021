# Penjelasan dan Penyelesaian Soal Shift Modul 2 Sistem Operasi
<p> berikut ini merupakan repository resmi untuk laporan soal shift.</p>

## Disusun oleh :
1. Clarissa Fatimah (05311940000012)
2. Revina Rahmanisa (05311940000046)
3. Ghimnastiar AL Abiyyuna (05311940000042)

# Daftar Isi
## Daftar Isi 
* [Soal 1](#soal-1) 
  * [Penyelesaian.](#penyelesaian) 
  * [Output.](#output) 
  * [Kendala.](#Kendala-Soal1) 
* [Soal 2](#soal-2) 
   * [Penyelesaian.](#penyelesaian) 
  * [Output.](#output) 
  * [Kendala.](#Kendala-Soal2) 
* [Soal 3](#soal-3) 
  * [Penyelesaian.](#penyelesaian) 
  * [Output.](#output) 
  * [Kendala.](#Kendala-Soal3) 


        
# Soal 1

Pada suatu masa, hiduplah seorang Steven yang hidupnya pas-pasan. Steven punya pacar, namun sudah putus sebelum pacaran. Ketika dia galau memikirkan mantan, ia selalu menonton https://www.youtube.com/watch?v=568DH_9CMKI untuk menghilangkan kesedihannya. 

Di lain hal Steven anak yang tidak amat sangat super membenci matkul sisop, beberapa jam setelah diputus oleh pacarnya dia menemukan wanita lain bernama Stevany, namun Stevany berkebalikan dengan Steven karena menyukai sisop. Steven ingin terlihat jago matkul sisop demi menarik perhatian Stevany.

Pada hari ulang tahun Stevany, Steven ingin memberikan Stevany zip berisikan hal-hal yang disukai Stevany. Steven ingin isi zipnya menjadi rapi dengan membuat folder masing-masing sesuai extensi. (a) Dikarenakan Stevany sangat menyukai huruf Y, Steven ingin nama folder-foldernya adalah Musyik untuk mp3, Fylm untuk mp4, dan Pyoto untuk jpg (b) untuk musik Steven mendownloadnya dari link di bawah, film dari link di bawah lagi, dan foto dari link dibawah juga :). (c) Steven tidak ingin isi folder yang dibuatnya berisikan zip, sehingga perlu meng-extract-nya setelah didownload serta (d) memindahkannya ke dalam folder yang telah dibuat (hanya file yang dimasukkan).

(e) Untuk memudahkan Steven, ia ingin semua hal di atas berjalan otomatis 6 jam sebelum waktu ulang tahun Stevany). (f) Setelah itu pada waktu ulang tahunnya Stevany, semua folder akan di zip dengan nama Lopyu_Stevany.zip dan semua folder akan di delete(sehingga hanya menyisakan .zip).
Kemudian Steven meminta bantuanmu yang memang sudah jago sisop untuk membantunya mendapatkan hati Stevany. Bantu Woy!!

```
Note:
- Ulang Tahun Stevany : 09 April Pukul 22.22 WIB
- Semua poin dijalankan oleh 1 script di latar belakang, termasuk mendownload file zip-nya. Jadi cukup jalankan script 1x serta ubah time dan date untuk check hasilnya.
```

```
Preview :
https://drive.google.com/drive/folders/1NzRiPPoVlR_H8P51cxN4jaceeFQGk4un
*tontonnya 720p biar jelas.. ಠ‿ಠ
```
```
-Tidak boleh menggunakan fungsi system(), mkdir(), dan rename() (Yang di bahasa C) .... FORBIDDENNN!!
-Tidak boleh pake cron !!!
-Menggunakan fork dan exec.
```
```
Link
Foto :
https://drive.google.com/file/d/1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD/view
Musik :
https://drive.google.com/file/d/1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J/view
Film : 
https://drive.google.com/file/d/1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp/view

```
```
contoh
Wget --no-check-certificate "https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download" -O Musik_for_Stevany.zip

```
## Penyelesaian 

## Output

## Kendala-soal1

# Soal 2
Loba bekerja di sebuah petshop terkenal, suatu saat dia mendapatkan zip yang berisi banyak sekali foto peliharaan dan Ia diperintahkan untuk mengkategorikan foto-foto peliharaan tersebut. Loba merasa kesusahan melakukan pekerjaanya secara manual, apalagi ada kemungkinan ia akan diperintahkan untuk melakukan hal yang sama. Kamu adalah teman baik Loba dan Ia meminta bantuanmu untuk membantu pekerjaannya.

Pertama-tama program perlu mengextract zip yang diberikan ke dalam folder “/home/[user]/modul2/petshop”. Karena bos Loba teledor, dalam zip tersebut bisa berisi folder-folder yang tidak penting, maka program harus bisa membedakan file dan folder sehingga dapat memproses file yang seharusnya dikerjakan dan menghapus folder-folder yang tidak dibutuhkan.
Foto peliharaan perlu dikategorikan sesuai jenis peliharaan, maka kamu harus membuat folder untuk setiap jenis peliharaan yang ada dalam zip. Karena kamu tidak mungkin memeriksa satu-persatu, maka program harus membuatkan folder-folder yang dibutuhkan sesuai dengan isi zip.
Contoh: Jenis peliharaan kucing akan disimpan dalam “/petshop/cat”, jenis peliharaan kura-kura akan disimpan dalam “/petshop/turtle”.
Setelah folder kategori berhasil dibuat, programmu akan memindahkan foto ke folder dengan kategori yang sesuai dan di rename dengan nama peliharaan.
Contoh: “/petshop/cat/joni.jpg”. 
Karena dalam satu foto bisa terdapat lebih dari satu peliharaan maka foto harus di pindah ke masing-masing kategori yang sesuai. Contoh: foto dengan nama “dog;baro;1_cat;joni;2.jpg” dipindah ke folder “/petshop/cat/joni.jpg” dan “/petshop/dog/baro.jpg”.
Di setiap folder buatlah sebuah file "keterangan.txt" yang berisi nama dan umur semua peliharaan dalam folder tersebut. Format harus sesuai contoh.
```
nama : joni
umur  : 3 tahun

nama : miko
umur  : 2 tahun
```
Loba sangat mengapresiasi bantuanmu, minggu depan ia akan mentraktir makan malam!
```
Note:
Setiap data peliharaan disimpan sebagai nama foto dengan format [jenis peliharaan]:[nama peliharaan]:[umur peliharaan dalam tahun]. Jika terdapat lebih dari satu peliharaan, data dipisahkan menggunakan underscore(_).
Tidak boleh menggunakan fungsi system(), mkdir(), dan rename().
Menggunakan fork dan exec.
```
## Penyelesaian 

## Output

## Kendala-soal2


# Soal 3
Ranora adalah mahasiswa Teknik Informatika yang saat ini sedang menjalani magang di perusahan ternama yang bernama “FakeKos Corp.”, perusahaan yang bergerak dibidang keamanan data. Karena Ranora masih magang, maka beban tugasnya tidak sebesar beban tugas pekerja tetap perusahaan. Di hari pertama Ranora bekerja, pembimbing magang Ranora memberi tugas pertamanya untuk membuat sebuah program.

**a.** Ranora harus membuat sebuah program C yang dimana setiap 40 detik membuat sebuah direktori dengan nama sesuai timestamp [YYYY-mm-dd_HH:ii:ss].

**b.** Setiap direktori yang sudah dibuat diisi dengan 10 gambar yang didownload dari https://picsum.photos/, dimana setiap gambar akan didownload setiap 5 detik. Setiap gambar yang didownload akan diberi nama dengan format timestamp [YYYY-mm-dd_HH:ii:ss] dan gambar tersebut berbentuk persegi dengan ukuran (n%1000) + 50 pixel dimana n adalah detik Epoch Unix.

**c.** Setelah direktori telah terisi dengan 10 gambar, program tersebut akan membuat sebuah file “status.txt”, dimana didalamnya berisi pesan “Download Success” yang terenkripsi dengan teknik Caesar Cipher dan dengan shift 5. Caesar Cipher adalah Teknik enkripsi sederhana yang dimana dapat melakukan enkripsi string sesuai dengan shift/key yang kita tentukan. Misal huruf “A” akan dienkripsi dengan shift 4 maka akan menjadi “E”. Karena Ranora orangnya perfeksionis dan rapi, dia ingin setelah file tersebut dibuat, direktori akan di zip dan direktori akan didelete, sehingga menyisakan hanya file zip saja.

**d.** Untuk mempermudah pengendalian program, pembimbing magang Ranora ingin program tersebut akan men-generate sebuah program “Killer” yang executable, dimana program tersebut akan menterminasi semua proses program yang sedang berjalan dan akan menghapus dirinya sendiri setelah program dijalankan. Karena Ranora menyukai sesuatu hal yang baru, maka Ranora memiliki ide untuk program “Killer” yang dibuat nantinya harus merupakan program bash.

**e.** Pembimbing magang Ranora juga ingin nantinya program utama yang dibuat Ranora dapat dijalankan di dalam dua mode. Untuk mengaktifkan mode pertama, program harus dijalankan dengan argumen -z, dan Ketika dijalankan dalam mode pertama, program utama akan langsung menghentikan semua operasinya Ketika program Killer dijalankan. Sedangkan untuk mengaktifkan mode kedua, program harus dijalankan dengan argumen -x, dan Ketika dijalankan dalam mode kedua, program utama akan berhenti namun membiarkan proses di setiap direktori yang masih berjalan hingga selesai (Direktori yang sudah dibuat akan mendownload gambar sampai selesai dan membuat file txt, lalu zip dan delete direktori).

Ranora meminta bantuanmu untuk membantunya dalam membuat program tersebut. Karena kamu anak baik dan rajin menabung, bantulah Ranora dalam membuat program tersebut!
```
Note:
Tidak boleh menggunakan system() dan mkdir()
Program utama merupakan SEBUAH PROGRAM C
Wajib memuat algoritma Caesar Cipher pada program utama yang dibuat
```
## Penyelesaian 
```c
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
```
Berikut merupakan daftar Library yang digunakan pada soal 3

```c
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
```
Pada Fungsi killersh program akan membuat program killer dalam bentuk bash, dengan command ``` fopen ``` untuk membuat file baru dengan command w, dan command printf untuk menuliskan source code killer. lalu memanggil fork dan exec untuk mengganti hak akses file menggunakan ``` {"chmod", "+x", "killer.sh", NULL} ```. Pada killer.sh terdapat 2 argumen berupa ``` -z ``` dan ``` -x ``` (2 mode yaitu z atau x) dimana z langsung berhenti tanpa menyelesaikan semuanya terlebih dahulu.

```c
void createfolder(char *foldername){
    if(fork()==0){ 
        char *mkdirargv[] = {"mkdir", "-p",foldername, NULL};
        execv("/bin/mkdir", mkdirargv);
    }
}
```
Setelah itu dengan menggunakan exec dan fork akan membuat suatu folder dengan nama variable ``` foldername ``` yang nantinya berjalan setiap 40 detik.

```c
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
```

Pada fungsi dlgb, program akan mendownload gambar menggunakan fungsi fork dan exec untuk memanggil ``` wget ``` dengan format sesuai timestamp, karena program akan mendownload sebanyak 10 gambar maka digunakan loop ``` for(i=0;i<10;i++) ``` dengan ``` sleep(5) ``` untuk setiap gambarnya.

```c
void zip(char *foldername){
    char zipname[150];
    sprintf(zipname,"%s.zip",foldername);
    char *zipargv[] = {"zip", "-rmq", zipname, foldername, NULL};
    execv("/usr/bin/zip", zipargv);
}
```
Pada fungsi zip akan menggunakan exec untuk mengzip folder setelah selesai melakukan pendownload tan pada 10 gambar.
``` sprintf(zipname,"%s.zip",foldername); ``` digunakan untuk mendapatkan namafolder.

```c
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
```

Pada Fungsi enkrip berisikan program yang akan mengenkripsi suatu pesan pada dungsi statustext menggunakan teknik enkripsi CAesar Cipher dengan Shift 5

```c
void statustext(char *foldername){    
    char status[112];
    char message[20] = "Download Success";
    sprintf(status,"%s/status.txt",foldername);
    enkrip(message,5);
    FILE *download = fopen(status,"w");
    fprintf(download,"%s",message);
    fclose(download);
}
```
Selanjut pada fungsi statustextlah program akan membuat file .txt bernama status yang isinya adalah pesan ``` Download Succes ```
namun pesan tersebut lalu dienkripsi dengan teknik Caesar Cipher dengan shift 5 sesuai pada fungsi enkrip

```c
void final(char *foldername){
    int child1;
    if(fork()==0){ 
        dlgb(foldername);
        statustext(foldername);
        zip(foldername);
    }
}
```
Pada Fungsi final merupakan deretan procces dimana pertama menjalankan fungsi dlgb untuk mendownload gambar, lalu fungsi statustext untuk membuat status.txt yang kemudian diengkripsi, dan terakhir di zip pada fungsi zip

```c
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
```
Pada fungsi main diberikan daemon agar program berjalan di background

```c
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
```

Masih didalam parameter fungsi main dimana nanti akan membuat folder bedasarkan timestamp lalu lalu di ```wait``` hingga folder selesai yang kemudian di zip dan selagi mengzip folder program akan mulai membuat direktori baru setelah 40 detik
## Output

- compile dan run dalam mode ``` -z ```
<img src="https://cdn.discordapp.com/attachments/830775203868573756/835349233606590484/modez.jpg">

- Output Folder dan atau zip pada mode ``` -z ```
<img src="https://cdn.discordapp.com/attachments/830775203868573756/835349239026155540/outputz.jpg">

- Isi
<img src="https://cdn.discordapp.com/attachments/830775203868573756/835349253240913940/isiz.jpg">

- Output Folder dan atau zip jika dilakukan dengan mode ``` -x ```
<img src="https://cdn.discordapp.com/attachments/830775203868573756/835349255912161320/m_odex.jpg">


## Kendala-soal3

kendala utama yang dialami pada pengerjaan soal 3 ialah pembuatan folder tidak konsisten dilakukan setiap 40 detik
