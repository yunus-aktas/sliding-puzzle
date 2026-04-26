 3x3 Sliding Puzzle Game

BIL1203 – Mühendislikte Proje Yönetimi dersi kapsamında geliştirilmiş, 
C dili ile yazılmış konsol tabanlı bir sliding puzzle oyunudur.

## Proje Hakkında

3x3 Sliding Puzzle (8-puzzle), 8 numaralı taşın tek bir boş hücre 
yardımıyla kaydırılarak belirli bir hedef sıralamaya ulaşılmaya 
çalışıldığı klasik bir bulmaca oyunudur.

## Özellikler

- Çözülebilir garantili rastgele tahta üretimi
- W/A/S/D tuşları ile oynanabilir kontrol sistemi
- Geçersiz hamle ve sınır kontrolü
- Hamle sayacı
- H tuşu ile BFS algoritması tabanlı otomatik çözüm ipucu sistemi
- Q tuşu ile güvenli çıkış

## Kontroller

| Tuş | Hareket |
|-----|---------|
| W | Yukarı |
| S | Aşağı |
| A | Sol |
| D | Sağ |
| H | İpucu (En kısa çözümü göster) |
| Q | Çıkış |

## Hedef Durum
+-------+-------+-------+
|   1   |   2   |   3   |
+-------+-------+-------+
|   4   |   5   |   6   |
+-------+-------+-------+
|   7   |   8   |       |
+-------+-------+-------+

## Derleme ve Çalıştırma

```bash
gcc puzzle.c -o puzzle
./puzzle
```

## Kullanılan Algoritmalar

- **Fisher-Yates:** Tahtayı rastgele karıştırmak için
- **Inversiyon Sayısı:** Çözülebilirlik kontrolü için
- **BFS (Genişlik Öncelikli Arama):** En kısa çözüm yolunu bulmak için

## Grup Bilgileri

| Öğrenci No | İsim |
|------------|------|
| 250601018 | Çağan Bulut |
| 250601028 | Mustafa Durmuş |
| 250601007 | Yunus Aktaş |
| 250601005 | Ceylin Azra Akman |

## Ders Bilgileri

**Ders:** BIL1203 – Mühendislikte Proje Yönetimi  
**Üniversite:** İzmir Bakırçay Üniversitesi  
**Bölüm:** Bilgisayar Mühendisliği  
**Tarih:** Nisan 2026
