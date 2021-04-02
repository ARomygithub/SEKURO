# Tubes Programming

## Anggota Kelompok
* M Sayyidurrahman Ash Shidqi (16720335)
* Ahmad Romy Zahran (16520159)
* Daffa Romyz Aufa (16520068)

## Pendahuluan
Program ditulis dalam bahasa C++ dan dapat dijalankan setelah di-_compile_.

## Plot
Dalam program ini, Anda akan membasmi kecoak mutan menggunakan robot.
Permainan terjadi dalam peta 13*13. Pada awal program, robot `R` akan memulai dari koordinat (0,0) dan satu kecoak `K` muncul secara random pada koordinat yang tidak sama dengan `R`.

## Aturan
- Robot memiliki atribut awal `health=20` dan dapat berkurang bila menabrak atau ditabrak oleh kecoak. Program selesai ketika dihentikan oleh pengguna atau `health` sudah habis.
- Robot dapat menembak kecoak dengan `damage=5` dan memiliki jarak maksimum `distMax=5`.
- Boss kecoak akan muncul ketika `Score` merupakan bilangan asli kelipatan tiga.
- Kecoak biasa tidak bergerak dan dapat dihabisi dengan 1 tembakan. Kecoak biasa memiliki `damage=5` ketika ditabrak.
- Boss kecoak dapat bergerak random dan memiliki `bosshealth=15` sehingga dibutuhkan 3 tembakan untuk membasminya. Boss kecoak memiliki `damage=5` ketika ditabrak atau menabrak.

## Kontrol
* `w` `a` `s` `d` berturut2 untuk maju, ke kiri, mundur, dan ke kanan.
* `e` untuk menembak.
* `x` untuk menghentikan permainan.

## Skor
* Membasmi 1 kecoak = +1 poin
* Membasmi 1 boss kecoak = +4 poin

## Link
https://github.com/ARomygithub/SEKURO/tree/main/Tubes%20Programming
