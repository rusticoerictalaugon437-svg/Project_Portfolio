#include <Wire.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

#define SOUND_SENSOR A0
#define CLAP_THRESHOLD 600
#define CLAP_TIMEOUT 200
#define MAX_CLAP_TIME 2000



static const uint8_t PIN_MP3_TX = 2;
static const uint8_t PIN_MP3_RX = 3;
SoftwareSerial mySerial(PIN_MP3_RX, PIN_MP3_TX);

DFRobotDFPlayerMini player;
bool dfPlayerReady = false;
int currentTrack = 0;
bool isPlaying = false;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);

  for (int i = 0; i < 5; i++) {
    if (player.begin(mySerial)) {
      dfPlayerReady = true;
      break;
    }
    delay(500);
  }
  int soundValue = analogRead(A0);
  Serial.println(soundValue);
  delay(100);
}

void loop() {
  int clapCount = detectClaps();

  if (clapCount == 1) {
    toggleMusic();
  } else if (clapCount == 2) {
    stopMusic();
  }
}

void toggleMusic() {
  if (!isPlaying) {
    startMusic(1, 229);  // Start with track 1
  } else {
    int nextTrack = (currentTrack == 1) ? 2 : 1; // Toggle between track 1 and 2
    startMusic(nextTrack, (nextTrack == 1) ? 229 : 210);
  }
}

void startMusic(int track, int duration) {
  stopMusic();  // Stop any currently playing music before switching
  delay(100);
  player.playMp3Folder(track);
  currentTrack = track;
  isPlaying = true;

  // Smooth RGB transition while the music plays
}

void stopMusic() {
  player.stop();
  isPlaying = false;
  currentTrack = 0;
}

int detectClaps() {
  int count = 0;
  unsigned long lastClapTime = 0;
  unsigned long startTime = millis();

  while (millis() - startTime < MAX_CLAP_TIME) {
    int soundLevel = analogRead(SOUND_SENSOR);
    if (soundLevel > CLAP_THRESHOLD) {
      if (millis() - lastClapTime > CLAP_TIMEOUT) {
        count++;
        Serial.println("Clap detected");
        lastClapTime = millis();
      }
    }
    if (count >= 2) break;
  }
  delay(300);
  return count;
}



