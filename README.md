# Aplikasi Pemesanan Tiket
## Description
Applikasi yang digunakan untuk pemesanan tiket, support antrian dan kategori pemesan.

---
## Data Structures
### Pemesan
- nama
- id kategori
- kategori

### Linked List
Menyimpan daftar pemesan secara dinamis, bisa ditambah, diedit, atau ditampilkan.

Operasi:
pesan(), tampilkanPesanan()

### Queue
Menyimpan antrian pemesan.

Operasi:
pesan(), ambilAntrian(), tampilkanAntrian()

### Tree
Menyimpan hirarki kategori

Operasi:
tambahKategori(), tampilkanKategori()

## Flow chart
```mermaid
flowchart TD
    A(Start) -->B[Tampilkan menu]
    B --> C{Pilihan}
    C -->|1| D[Tambah Pemesan]
    C -->|2| E[Tampilkan Daftar Pemesan]
    C -->|3| F[Ambil Antrian]
    C -->|4| G[Tampilkan Antrian]
    C -->|5| H[Tambah Kategori Tiket]
    C -->|6| I[Tampilkan Kategori Tiket]
    D -->J[Tambah ke linked list]
    E -->K[Tampilkan linked list]
    F -->L[Tambah queue]
    G -->M[Tampilkan queue]
    H -->N[Tambah tree]
    I -->O[Tampilkan tree]
    J -->p(finish)
    K -->p(finish)
    L -->p(finish)
    M -->p(finish)
    N -->p(finish)
    O -->p(finish)    
```

## Screen Shot
![img](./screenshot/img.png)

![img](./screenshot/img_1.png)

![img](./screenshot/img_2.png)

![img](./screenshot/img_3.png)

![img](./screenshot/img_4.png)

![img](./screenshot/img_5.png)