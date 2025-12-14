# Tugas Besar Struktur Data - MusikKuh by EL CUMLAUDE

## Deskripsi
Proyek ini adalah aplikasi manajemen musik sederhana menggunakan C++.  
Aplikasi ini dapat:
- Mengelola daftar lagu berdasarkan genre
- Membuat dan mengelola playlist
- Menandai lagu favorit
- Memutar lagu melalui queue
- Menyimpan riwayat pemutaran lagu

Proyek ini dibuat sebagai bagian dari Tugas Besar Mata Kuliah Struktur Data.

## Struktur Data yang Digunakan

1. **Doubly Linked List (DLL)**
   - Digunakan untuk menyimpan daftar lagu (`ListSong`) dan playlist.
   - Mempermudah traversal maju dan mundur, serta insert/delete di posisi tertentu.

2. **Singly Linked List (SLL)**
   - Digunakan untuk menyimpan daftar playlist (`ListPlaylist`) dan daftar favorit (`ListFavorite`).
   - Simpel untuk traversal searah.

3. **Queue**
   - Digunakan untuk memutar lagu dalam antrian (`PlayQueue`).
   - Menjaga urutan pemutaran lagu sesuai FIFO (First In First Out).

4. **Stack**
   - Digunakan untuk menyimpan riwayat pemutaran lagu sementara (`HistoryStack`).
   - Mempermudah undo atau melihat lagu terakhir yang diputar.

5. **Permanent History**
   - Menyimpan riwayat lagu yang sudah diputar secara permanen (`PermanentHistory`).

## Struktur File

- `musik.h` : Header file yang berisi deklarasi struct dan fungsi.
- `musik.cpp` : Implementasi fungsi-fungsi manajemen musik.
- `main.cpp` : File utama untuk menjalankan aplikasi.

## Cara Compile dan Run

Gunakan terminal/command prompt:

```bash
g++ main.cpp musik.cpp -o musikApp
./musikApp
