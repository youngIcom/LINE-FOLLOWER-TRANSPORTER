// Definisi pin untuk motor DC
#define IN1 D1 // Motor kanan - arah
#define IN2 D2 // Motor kanan - kecepatan
#define IN3 D3 // Motor kiri - arah
#define IN4 D4 // Motor kiri - kecepatan

// Definisi pin untuk sensor garis
#define S1 D0  // Sensor kiri
#define S2 D5  // Sensor tengah-kiri
#define S3 D6  // Sensor tengah
#define S4 D7  // Sensor tengah-kanan
#define S5 D8  // Sensor kanan 

// Variabel global
int kecepatan = 800; // Kecepatan motor (0-1023 untuk PWM ESP8266)

void setup() {
  // Inisialisasi komunikasi serial
  Serial.begin(9600);

  // Atur pin motor sebagai output
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Atur pin sensor sebagai input
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);
}

void loop() {
  // Membaca status sensor
  int kiri = digitalRead(S1);
  int tengahKiri = digitalRead(S2);
  int tengah = digitalRead(S3);
  int tengahKanan = digitalRead(S4);
  int kanan = digitalRead(S5);

  // Menampilkan status sensor di Serial Monitor
  Serial.print("Sensor 1: "); Serial.print(kiri ? "PUTIH " : "HITAM ");
  Serial.print("| Sensor 2: "); Serial.print(tengahKiri ? "PUTIH " : "HITAM ");
  Serial.print("| Sensor 3: "); Serial.print(tengah ? "PUTIH " : "HITAM ");
  Serial.print("| Sensor 4: "); Serial.print(tengahKanan ? "PUTIH " : "HITAM ");
  Serial.print("| Sensor 5: "); Serial.println(kanan ? "PUTIH" : "HITAM");

  // Logika kendali berdasarkan sensor
  if (tengah == HIGH) {
    // Garis terdeteksi di tengah, robot maju
    maju();
  } else if (kiri == HIGH || tengahKiri == HIGH) {
    // Garis terdeteksi di kiri, robot belok kanan
    belokKanan();
  } else if (kanan == HIGH || tengahKanan == HIGH) {
    // Garis terdeteksi di kanan, robot belok kiri
    belokKiri();
  } else {
    // Tidak ada garis, berhenti
    berhenti();
  }

  // Tunggu sebentar sebelum membaca ulang
  delay(50); // 50 ms untuk respons cepat
}

// Fungsi untuk menggerakkan motor maju
void maju() {
  digitalWrite(IN1, HIGH); 
  analogWrite(IN2, kecepatan); // Kecepatan motor kanan
  digitalWrite(IN3, HIGH); 
  analogWrite(IN4, kecepatan); // Kecepatan motor kiri
}

// Fungsi untuk menghentikan motor
void berhenti() {
  digitalWrite(IN1, LOW); 
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// Fungsi untuk belok kanan
void belokKanan() {
  digitalWrite(IN1, HIGH); 
  analogWrite(IN2, kecepatan); // Motor kanan lambat
  digitalWrite(IN3, LOW); 
  analogWrite(IN4, 0);        // Motor kiri berhenti
}

// Fungsi untuk belok kiri
void belokKiri() {
  digitalWrite(IN1, LOW); 
  analogWrite(IN2, 0);        // Motor kanan berhenti
  digitalWrite(IN3, HIGH); 
  analogWrite(IN4, kecepatan); // Motor kiri lambat
}
