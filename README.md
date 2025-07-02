# 🤖 LINE-FOLLOWER-TRANSPORTER 🚗

**Proyek robot Line Follower Transporter**  
_Polibatam - Prodi Robotika - Semester 1, 2024_

---

## Deskripsi

Repositori ini berisi seluruh file dan kode selama pengerjaan **robot line follower transporter**. Proyek ini menggunakan ESP8266 dan 5 buah sensor garis untuk mengikuti lintasan, dikembangkan sebagai tugas semester 1 di Politeknik Negeri Batam, Prodi Robotika, Jurusan Teknik Elektro.

---

## 🎯 Fitur Utama

- **Mengikuti garis otomatis** dengan 5 sensor (kiri, tengah-kiri, tengah, tengah-kanan, kanan)
- **Kontrol motor DC**: maju, belok kiri/kanan, dan berhenti
- **Tampilan status sensor** real-time di Serial Monitor
- **Kecepatan motor bisa diatur** lewat variabel kode

---

## 🛠️ Kebutuhan Hardware

- ESP8266 (NodeMCU/D1 Mini)
- 2 Motor DC + Motor Driver (L298N/L9110S)
- 5 Sensor Garis (misal TCRT5000)
- Kabel jumper & power supply

---

## ⚡ Skema Pin

| Fungsi                | Pin ESP8266 |
|-----------------------|:-----------:|
| Motor Kanan Arah      | D1          |
| Motor Kanan Kecepatan | D2          |
| Motor Kiri Arah       | D3          |
| Motor Kiri Kecepatan  | D4          |
| Sensor Kiri           | D0          |
| Sensor Tengah-Kiri    | D5          |
| Sensor Tengah         | D6          |
| Sensor Tengah-Kanan   | D7          |
| Sensor Kanan          | D8          |

---

## 🚦 Cara Kerja Singkat

1. **Sensor membaca garis** (PUTIH/HITAM).
2. **Logika kontrol:**
    - Garis di tengah → robot maju 🚗💨
    - Garis di kiri → robot belok kanan ↩️
    - Garis di kanan → robot belok kiri ↪️
    - Tidak ada garis → robot berhenti ⛔
3. **Status sensor** ditampilkan di Serial Monitor.

---

## 👀 Cuplikan Kode
if (tengah == HIGH) {
  maju();
} else if (kiri == HIGH || tengahKiri == HIGH) {
  belokKanan();
} else if (kanan == HIGH || tengahKanan == HIGH) {
  belokKiri();
} else {
  berhenti();
}


##🚀 Cara Penggunaan

    Upload file PBLv3.ino ke board ESP8266.
    Hubungkan hardware sesuai tabel pin di atas.
    Nyalakan robot, buka Serial Monitor (baudrate 9600).
    Robot siap mengikuti garis pada lintasan!

📸 Dokumentasi & Pengembangan

    Dokumentasi lengkap dan update pengembangan ada di folder ini.
    Silakan modifikasi kode sesuai kebutuhan eksperimenmu!

📢 Kontribusi

Terbuka untuk diskusi, pengembangan, dan sharing pengalaman. Silakan buat issue atau pull request!
